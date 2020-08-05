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
static const ll max_n = 16;
static const ll max_v = 1LL<<62LL;
vector<ll> xs(max_n);
vector<ll> ys(max_n);
vector<ll> ps(max_n);
vector<vector<ll>> tate_s((1<<max_n), vector<ll>(max_n, max_v));
vector<vector<ll>> yoko_s((1<<max_n), vector<ll>(max_n, max_v));
ll N;




void Main(){
    sll(N);
    rep(i, N){
        sll(xs[i]);
        sll(ys[i]);
        sll(ps[i]);
    }

    // x
    for(ll bit=0;bit<(1<<N);++bit){
        for(ll i=0;i<N;i++){
            tate_s[bit][i] = abs(xs[i]);
            yoko_s[bit][i] = abs(ys[i]);
            rep(k, N){
                if((1<<k) & bit){
                    tate_s[bit][i] = min(tate_s[bit][i], abs(xs[i]-xs[k]));
                    yoko_s[bit][i] = min(yoko_s[bit][i], abs(ys[i]-ys[k]));
                }
            }
        }
    }

    vector<ll> ans(N+1, max_v);
    for(ll bit=0;bit<(1<<N);++bit){
        ll cnt = 0;
        for(ll i=0;i<N;i++){
            if((bit>>i)&1) ++cnt;
        }

        for(ll j=bit;j>=0;--j){
            j &= bit;
            ll v = 0;
            rep(k, N){
                if(!((bit>>k) & 1)){
                    v += min(tate_s[j][k], yoko_s[bit-j][k]) * ps[k];
                }
            }
            ans[cnt] = min(ans[cnt], v);
        }
    }

    rep(i, N+1){
        cout << ans[i] <<endl;
    }


}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}