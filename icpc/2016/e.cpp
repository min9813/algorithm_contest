#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <complex>
#include <random>
#include <bitset>
#include <list>
#include <assert.h>
#include <prettyprint.hpp>
using namespace std;
#define repi(i,n) for(int i=0;i<n;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repinvi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vvv(t) vector<vector<vector<t>>>
typedef long long ll;
typedef double lf;
typedef short int si;

struct point{
    ll i, x, y, z;
    point(ll i, ll x, ll y, ll z): i(i), x(x),y(y),z(z){};
};
ostream& operator<<(ostream& os, const point& a) { return os << "i=" << a.i << " x,y,z=" << a.x << "," << a.y << "," << a.z;}

static const ll max_n = 2010;

// ll field[max_n][max_n];
vv(ll) dp(max_n, v(ll)(max_n, 0));

inline bool is_overlap(ll x1, ll x2, ll s){
    return abs(x1 - x2) < s;
}

inline ll calc_ov(ll x1, ll x2, ll s){
    ll v;
    if(x1< x2){
        v = x1 + s - x2;
    }else{
        v = x2 + s - x1;
    }

    return v;
}

inline ll calc_surface(point p1, point p2, ll s){
    ll x_ov, y_ov, z_ov;
    x_ov = calc_ov(p1.x, p2.x, s);
    y_ov = calc_ov(p1.y, p2.y, s);
    z_ov = calc_ov(p1.z, p2.z, s);
    ll surface = (x_ov * y_ov + x_ov * z_ov + y_ov * z_ov) * 2;
    return surface;
}

void Main(){
    ll n, k, s, x, y, z;
    vector<ll>answers;
    while(cin >> n>>k>>s){
        if(n==0 && k==0 &&s==0){
            break;
        }
        fill(dp.begin(), dp.end(), v(ll)(max_n, 0));
        map<ll,map<ll, ll>> counter;
        v(point) points(n, {-1, 0, 0, 0});
        rep(i, n){
            cin >> x >> y >> z;
            points[i] = point(i, x, y, z);
        }
        vector<ll> is_one(n, true);
        rep(i, n){
            point sp = points[i];
            for(ll j=i+1;j<n;++j){
                if(i==j) continue;
                point tp = points[j];
                if(is_overlap(tp.x, sp.x, s) && is_overlap(tp.y, sp.y, s) && is_overlap(tp.z, sp.z, s)){
                    is_one[i] = false;
                    is_one[j] = false;
                    ll ov = calc_surface(sp, tp, s);
                    // ov = abs(ov);
                    counter[i][j] = ov;
                    counter[j][i] = ov; 
                    // cout << "i,j=" <<i << "," << j << " ov=" << ov << " sp=" << sp << " tp=" << tp <<endl;
                }
            }
        }


        vector<bool> used(n, false);
        vector<v(ll)> joint;
        vector<bool> is_line;
        // v(pll) scores;
        rep(i, n){
            if(used[i]) continue;
            if(is_one[i]){
                // v(ll) v = {i};
                joint.emplace_back(v(ll){i});
                // scores.emplace_back(0, 1);
                is_line.emplace_back(false);
                continue;
            }
            // queue<point> Q;
            stack<point> S;
            S.push(points[i]);
            used[i] = true;

            v(ll) v;
            ll min_dim = 2;
            ll start_i = -1;
            while(!S.empty()){
                auto p = S.top(); S.pop();
                // if(used[p.i]) continue;
                v.emplace_back(p.i);
                ll counter_size = counter[p.i].size();
                if(counter_size == 1){
                    start_i = p.i;
                }
                // cout << "p:" << p <<endl;
                min_dim = min(counter_size, min_dim);
                for(auto p2: counter[p.i]){
                    if(used[p2.first]) continue;
                    // cout << "p2:" << p2 <<endl;
                    // v.emplace_back(p2.first);
                    S.push(points[p2.first]);
                    used[p2.first] = true;
                }
            }
            // cout << "i=" << i << " v=" << v <<endl;
            if(min_dim == 2){
                is_line.emplace_back(false);
            }else{
                is_line.emplace_back(true);
                fill(used.begin(), used.end(), false);
                v.clear();
                v = {start_i};
                queue<point> Q;
                Q.push(points[start_i]);
                while(!Q.empty()){
                    auto p = Q.front(); Q.pop();
                    if(used[p.i]) continue;
                    for(auto p2: counter[p.i]){
                        if(used[p2.first]) continue;
                        v.emplace_back(p2.first);
                        Q.push(points[p2.first]);
                    }
                    used[p.i] = true;
                }
            }
            joint.emplace_back(v);
        }

        ll ans1 = -1;
        ll max_size = -1;
        rep(i, joint.size()){
            auto v = joint[i];
            // cout << " vi=" << i << " v=" << v << " isline:" << is_line[i] << endl;
            ll j_value = 0;
            if(v.size()<k) continue;
            if(v.size()==1){
                if(ans1 < 0){
                    ans1 = 0;
                    max_size = 1;
                }
            }else if(is_line[i]){
                rep(j, v.size()){
                    ll this_j_value = 0;

                    for(ll k1=j,l=0;k1<v.size()&&l<k-1;++k1,++l){
                        this_j_value += counter[v[k1]][v[k1+1]];
                    }
                    j_value = max(j_value, this_j_value);
                }
            }else{
                if(v.size()==2){
                    j_value = counter[v[0]][v[1]];
                }else{
                    ll vs = v.size();
                    rep(j, v.size()){
                        
                        ll stop_i;
                        if(j == 0){
                            stop_i = v.size()-1;
                        }else{
                            stop_i = j - 1;
                        }
                        ll stop_k;
                        if(v.size() == k){
                            stop_k = k;
                        }else{
                            stop_k = k - 1;
                        } 
                        // cout << " stopk=" << stop_k <<endl;
                        ll this_j = 0;
                        for(ll k1=j,l=0;l<stop_k;++k1,++l){
                            this_j += counter[v[k1%vs]][v[(k1+1)%vs]];
                            if(k1%vs==stop_i) break;
                        }
                        j_value = max(j_value, this_j);
                    }
                }

            }
            // cout << "ok" << endl;
            if(ans1 < j_value){
                ans1 = j_value;
                max_size = min((ll)v.size(), k);
            }
        }

        ll ans;
        if(max_size < k){
            ans = -1;
        }else{
            ans = max_size * s * s * 6  - ans1;
        }
        // cout << "ans before=" << ans1 << ", ans after:" << ans <<endl;
        answers.emplace_back(ans);
        // cout << "ok" <<endl;

    }
    rep(i, answers.size()){
        cout << answers[i] << endl;
    }

}

int main(){
    Main();
}