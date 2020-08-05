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

void Main(){
    ll N, Q, c, l, r;
    cin >> N >> Q;
    vector<ll> as(N);
    vector<ll> cs(N, -1);
    vector<vector<ll>> ps(N);
    vector<vector<pll>> qs(N);
    rep(i, N){
        sll(c);
        -- c;
        l = cs[c];
        if(l != -1){
            ps[l].emplace_back(i);
        }
        as[i] = c;
        cs[c] = i;
    }

    rep(i, Q){
        sll(l);
        sll(r);
        -- l;
        -- r;
        qs[l].emplace_back(r,i);
    }

    BIT<ll> bit(N);

    vector<ll> ans(Q);
    for(ll i=N-1;i>=0;--i){
        for(auto p:ps[i]){
            bit.add(p, 1);
        }
        for(auto q:qs[i]){
            ans[q.second] = (q.first-i+1) - bit.get_sum(q.first);
        }
    }

    rep(i, Q){
        cout << ans[i] <<endl;
    }

}

int main(){
    Main();
}