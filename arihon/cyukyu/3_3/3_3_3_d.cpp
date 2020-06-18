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
typedef long long ll;
typedef double lf;
typedef short int si;

vector<pair<lf, ll>> grad_x;
vector<pair<lf, ll>> grad_y;
vector<lf> bc_list;
vector<lf> ac_list;
vector<lf> y_coords;
vector<lf> y_coords_s;

template<typename T>
class BIT{
    public:
        vector<T> x_list;
        ll n;

        BIT(ll n=1, T fill_value=0): n(n){
            x_list.resize(n+1);
            fill(x_list.begin(), x_list.end(), fill_value);
        }

        void add(ll idx, T v){
            for(ll x=idx; x<= n;x += (x & -x)){
                x_list[x] += v;
            }
        }

        ll get_sum(ll idx){
            T v = 0;
            for(ll x=idx;x>0;x-=(x & -x)){
                v += x_list[x];
            }
            return v;
        }
};

ll N;

ll get_vx(lf coord){
    rep(i, N){
        lf y = grad_x[i].first * coord + bc_list[grad_x[i].second];
        y_coords[i] = y;
        y_coords_s[i] = y;
    }
    map<lf, ll> index;
    sort(y_coords_s.begin(), y_coords_s.end());
    BIT<ll> bit(N, 0);
    rep(i, N){
        index[y_coords_s[i]] = i;
    }
    // cout << " --- coord = "<<coord << "---\n";
    // cout << "grad y:" << grad_x <<endl;
    // cout << y_coords <<endl;
    // cout << index << endl;
    ll ans = 0;
    rep(i, N){
        ll bit_index = index[y_coords[i]] + 1;
        ans += i - bit.get_sum(bit_index);
        bit.add(bit_index, 1);
    }
    // cout << "ans = "<< ans << endl;

    return ans;

}

ll get_vy(lf coord){
    rep(i, N){
        lf y = grad_y[i].first * coord + ac_list[grad_y[i].second];
        y_coords[i] = y;
        y_coords_s[i] = y;
    }
    map<lf, ll> index;
    sort(y_coords_s.begin(), y_coords_s.end());
    BIT<ll> bit(N, 0);
    rep(i, N){
        index[y_coords_s[i]] = i;
    }

    // cout << " --- coord = "<<coord << "---\n";
    // cout << "grad y:" << grad_y <<endl;
    // cout << "ac_list:" << ac_list <<endl;
    // cout << y_coords <<endl;
    // cout << index << endl;
    ll ans = 0;
    rep(i, N){
        ll bit_index = index[y_coords[i]] + 1;
        ans += i - bit.get_sum(bit_index);
        bit.add(bit_index, 1);
    }

    // cout << "ans = "<< ans << endl;

    return ans;

}

void Main(){
    lf a, b, c;
    sll(N);
    y_coords.resize(N);
    y_coords_s.resize(N);
    rep(i, N){
        slf(a);
        slf(b);
        slf(c);
        grad_x.emplace_back(-a/b, i);
        grad_y.emplace_back(-b/a, i);
        bc_list.emplace_back(c / b);
        ac_list.emplace_back(c / a);
    }
    sort(grad_x.begin(), grad_x.end(), greater<pair<lf, ll>>());
    sort(grad_y.begin(), grad_y.end(), greater<pair<lf, ll>>());

    cout << grad_x <<endl;
    cout << grad_y <<endl;

    lf coord_l = - 1e18;
    lf coord_r = 1e18;
    lf eps = 1e-11;
    ll target_v = (N * (N-1)) / 4;
    if((N * (N-1)) % 4 != 0){
        ++ target_v;
    }
    // if(N == 2){
        // target_v = 0;
    // }
    for(ll i=0;i<=100;i++){
        lf mid = (coord_l + coord_r) * 0.5;
        ll this_v = get_vx(mid);
        if(this_v >= target_v){
            coord_r = mid;
        }else{
            coord_l = mid;
        }
        cout << "mid = " << mid << " this v = "<<this_v << " target v = " << target_v << " coord r,l=" << coord_r<<","<<coord_l<<endl;

    }

    lf coord_x = coord_r;

    coord_l = - 1e18;
    coord_r = 1e18;
    for(ll i=0;i<=100;i++){
        lf mid = (coord_l + coord_r) * 0.5;
        ll this_v = get_vy(mid);
        if(this_v >= target_v){
            coord_r = mid;
        }else{
            coord_l = mid;
        }
    }

    lf coord_y = coord_r;

    cout << fixed << setprecision(11) << coord_x << " " << coord_y  <<endl;

    
}

int main(){
    Main();
}