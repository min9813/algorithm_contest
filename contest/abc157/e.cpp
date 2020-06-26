#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <complex>
#include <random>
#include <bitset>
#include <list>
// #include <prettyprint.hpp>
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
typedef long long ll;
typedef double lf;
typedef short int si;

class RMQ{
    public:
        string x_list;
        vector<map<char,ll>> y_list;
        ll n;
        ll length = 1;
        map<char, ll> fvalue;

        RMQ(ll n=1, string S="", map<char, ll> fvalue={}): n(n), fvalue(fvalue){
            length = 1;
            while (length < n){
                length *= 2;
            }
            // cout << "length;" << length <<endl;
            x_list = S;
            y_list.resize(2*length-1);
            fill(y_list.begin(), y_list.end(), fvalue);
            for(ll i=0;i<S.size();i++){
                this->update(i, S[i]);
            }
        }

        void update(ll idx, char v){
            
            char org_c = x_list[idx];
            if(y_list[idx][org_c]>0){
                -- y_list[idx][org_c];
            }
            x_list[idx] = v;
            idx += length - 1;
            ++ y_list[idx][v];
            
            // cout << "update idx "<<idx <<" to " << v <<endl;
            while(idx > 0){
                idx = (idx - 1 )/ 2;
                auto left_m = y_list[idx*2+1];
                auto right_m = y_list[idx*2+2];
                map<char, ll> new_m;
                for(auto p:left_m){
                    new_m[p.first] = p.second;
                }
                for(auto p:right_m){
                    new_m[p.first] += p.second;
                }
                y_list[idx] = new_m;
                // cout << "update idx" << idx << "to " << x_list[idx] <<endl;
            }
        }

        map<char,ll> query(ll x, ll y){return query(x, y, 0, 0, length);}

        map<char,ll> query(ll x, ll y, ll k, ll l, ll r){
            if(y <= l || x >= r){
                // cout << "l,r,x,y,k = "<< l << "," << r << "," << x << "," << y << "," <<k <<endl;
                return fvalue;
            }

            // cout << "k = " << k << " l,r=" << l << "," <<r << " x,y=" << x << "," << y <<endl;

            if(x <= l && r <= y) return y_list[k];

            auto left_m = query(x, y, 2*k+1, l, (l+r)/2);
            auto right_m = query(x, y, 2*k+2, (l+r)/2, r);
            map<char, ll> new_m;
            for(auto p:left_m){
                new_m[p.first] = p.second;
            }
            for(auto p:right_m){
                new_m[p.first] += p.second;
            }
            return new_m;

        }
};



void Main(){
    ll N, Q, t, a, b;
    char c;
    string S;
    cin >> N;
    cin >> S;
    cin >> Q;
    RMQ rmq(N, S);
    vector<ll> queries(Q);
    vector<pair<char,ll>> indices1(Q);
    vector<pll> indices2(Q);
    rep(i, Q){
        cin >> t >> a;
        // sll(t);
        // sll(a);
        // cout << "t,a,b=" << t<<"," <<a<<endl;
        // cout << "i=" <<i <<endl;
        if(t==1){
            cin >> c;
            -- a;
            rmq.update(a, c);
        }else{
            cin >> b;
            -- a;
            -- b;
            auto m = rmq.query(a, b+1);
            ll ans = 0;
            for(auto p:m){
                if(p.second>0){
                    ++ ans;
                }
            }
            printf("%lld\n", ans);
        }
    }

}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}