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
static const ll max_v = 16;

vector<vector<ll>> dp((1<<max_v), vector<ll>(max_v, INF));

void Main(){
    ll V, E, s, t, d;
    sll(V);
    sll(E);
    vector<vector<ll>> adjm(V, vector<ll>(V, INF));

    rep(i, E){
        cin >> s >> t >> d;
        adjm[s][t] = d;
    }

    dp[(1<<V)-1][0] = 0;
    for(ll s=(1<<V)-2;s>=0;--s){
        for(ll u=0;u<V;u++){
            if(s&(1<<u)) continue;
            for(ll v=0;v<V;v++){
                // if(s&(1<<v)) continue;
                // dp[s][u] = min(dp[s][u], dp[s|(1<<v)][v] + adjm[u][v]);
                dp[s][v] = min(dp[s][v], dp[s|(1<<u)][u] + adjm[v][u]);
            }
        }
    }

    if(dp[0][0] == INF){
        cout << "-1" <<endl;
    }else{
        cout << dp[0][0] <<endl;
    }


}

int main(){
    Main();
}