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

static const ll MAX_N = 100010;
struct Edge{
    ll u, v, c;
    Edge(ll u, ll v, ll c): u(u), v(v), c(c){}
};

vector<ll> edges[MAX_N];
ll searched[MAX_N];
ll ans[MAX_N];

void Main(){
    ll N, u, v;
    cin >> N;
    map<pll, ll> reg;
    ll first_u, first_v;
    rep(i, N-1){
        cin >> u >> v;
        -- u; -- v;
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
        reg[make_pair(u, v)] = i;
        if(i == 0){
            first_u = u;
            first_v = v;
        }
        searched[i] = 0;
    }
    searched[N-1] = 0;

    queue<Edge> Q;
    ll next_c = 1;
    for(ll next_u:edges[first_u]){
        Q.push({first_u, next_u, next_c});
        searched[next_u] = 1;
        ++ next_c;
    }
    searched[first_u] = 1;

    ll k = edges[first_u].size();
    while(!Q.empty()){
        auto e = Q.front(); Q.pop();

        ll next_c;
        if(e.c == 1){
            next_c = 2;
        }else{
            next_c = 1;
        }

        ll u = e.u;
        ll v = e.v;
        if(u > v){
            ll edge_i = reg[{v, u}];
            ans[edge_i] = e.c;
        }else{
            ll edge_i = reg[{u, v}];
            ans[edge_i] = e.c;
        }

        for(ll next_u: edges[e.v]){
            if(searched[next_u] == 1) continue;
            searched[next_u] = 1;
            Q.push({e.v, next_u, next_c});
            ++next_c;
            if(next_c == e.c){
                ++ next_c;
            }
        }
        k = max(k, (ll)edges[e.v].size());
    } 

    cout << k << endl;
    rep(i, N-1){
        cout << ans[i] <<endl;
    }

}

int main(){
    Main();
}