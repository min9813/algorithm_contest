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

static const ll max_n = 200010;
BIT<ll> bit(max_n, 0);

void Main(){
    ll Q, t, x;
    sll(Q);
    rep(i, Q){
        sll(t);
        sll(x);
        if(t==1){
            bit.add(x, 1);
        }else{
            ll left_v = 0;
            ll right_v = max_n;
            while(right_v - left_v > 1){
                ll mid = (left_v + right_v) / 2;
                ll lower_num = bit.get_sum(mid);
                if(lower_num >= x){
                    right_v = mid;
                }else{
                    left_v = mid;
                }
            }
            bit.add(right_v, -1);
            printf("%lld\n", right_v);
        }

    }

}

int main(){
    Main();
}