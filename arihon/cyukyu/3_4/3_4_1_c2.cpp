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

static const ll max_v = 17;
static const ll INF = 1e16;
// stacic const ll max_n = 1010;
vector<ll> dp((1<<max_v), 0);
vector<vector<ll>> edges(max_v, vector<ll>(max_v, 0));

void Main(){
    ll N, M, u, v;
    cin >> N >> M;
    rep(i, M){
        cin >> u >> v;
        edges[u-1][v-1] = 1;
    }
    // rep(i, N){
    //     dp[1<<i] = 1;
    // }
    dp[0] = 1;

    for(ll S=0;S<(1<<N);++S){
        rep(u, N){
            if(!((S>>u)&1)){
                bool ok = true;
                rep(v, N){
                    if(edges[u][v] && (S>>v)&1){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    dp[S|(1<<u)] += dp[S];
                }
            }

        }
    }

    cout << dp[(1<<N)-1] <<endl;




}

int main(){
    Main();
}