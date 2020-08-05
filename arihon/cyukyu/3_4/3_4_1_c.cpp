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

// vector<vector<ll>> dp((1<<max_v), vector<ll>(max_v, INF));

void Main(){
    ll N, M , x, y;
    cin >> N >> M;
    // vector<pll> edges(M);
    set<pll> edges;
    vector<ll> dp(1<<N, 0);
    rep(i, M){
        cin >> x >> y;
        -- x;
        -- y;
        edges.insert(make_pair(x, y));
    }

    dp[0] = 1;
    for(ll s=1;s<1<<N;++s){
        ll this_n = 0;
        vector<ll> ns;
        for(ll i=0;i<N;i++){
            if(s & (1<<i)){
                ns.emplace_back(i);
            }
        }
        for(auto u:ns){
            bool this_ok = true;
            for(auto v:ns){
                auto p = make_pair(u, v);
                if(edges.find(p) != edges.end()){
                    this_ok = false;
                    break;
                }
            }
            if(this_ok){
                this_n += dp[s-(1<<u)];
            }
        }
        dp[s] = this_n;
    }

    cout << dp[(1<<N)-1] <<endl;





}

int main(){
    Main();
}