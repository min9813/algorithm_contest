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
#include <assert.h>
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
static const ll INF = 1e15;


void Main(){
    ll N, M, a;
    sll(N);
    sll(M);
    vector<ll> as(N);
    vector<ll> counter(M);
    vector<ll> dp(1<<M, INF);
    vector<vector<ll>> pos_c(M, vector<ll>(N+1,0));
    rep(i, N){
        sll(a);
        -- a;
        as[i] = a;
        ++pos_c[a][i+1];
        ++counter[a];
    }

    rep(i, M){
        rep(j, N){
            pos_c[i][j+1] += pos_c[i][j];
        }
    }
    dp[0] = 0;

    for(ll s=0;s<(1<<M);++s){
        // 左から用いるぬいぐるみの種類を決めると、ぬいぐるみをどう並べたかに関わらず今いる場所が定まる
        // 今いる場所を記録する変数 now_pos
        ll now_pos = 0;
        for(ll j=0;j<M;j++){
            if(s&(1<<j)){
                now_pos += counter[j];
            }
        }

        for(ll j=0;j<M;j++){
            if(s&(1<<j)) continue;
            dp[s+(1<<j)] = min(dp[s+(1<<j)], dp[s]+counter[j]-(pos_c[j][now_pos+counter[j]]-pos_c[j][now_pos]));
        }
    }

    cout << dp[(1<<M)-1] <<endl;

}

int main(){
    Main();
}