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

static const ll max_v = 15;
static const ll INF = 1e16;
// stacic const ll max_n = 1010;
vector<vector<ll>> dp((1<<max_v), vector<ll>(max_v, INF));
vector<vector<ll>> edges(max_v, vector<ll>(max_v, INF));

void Main(){
    ll V, E, s, t, d;
    cin >> V >> E;
    rep(i, E){
        cin >> s >> t >> d;
        edges[s][t] = d;
    }

    dp[(1<<V)-1][0] = 0;
    for(ll S=(1<<V)-1;S>=0;--S){
        rep(u, V){
            rep(v, V){
                if(S&(1<<v)){
                    dp[S-(1<<v)][u] = min(dp[S-(1<<v)][u], dp[S][v]+edges[u][v]);
                    // cout << "dp[" << bitset<10>(S-(1<<v)) << "]=" << dp[S-(1<<v)][u] <<endl;
                }
            }
        }
    }

    if(dp[0][0]==INF){
        cout << "-1" <<endl;
    }else{
        cout << dp[0][0] << endl;
    }

}

int main(){
    Main();
}