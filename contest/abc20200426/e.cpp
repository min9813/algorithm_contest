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
static const ll MAX_N = 52;
static const ll MAX_S = MAX_N * 50 + 5;
static const ll INF = 1e17;

struct Edge{
    ll u, a, b;
    Edge(ll u, ll a, ll b):u(u), a(a), b(b){}
};

struct Data{
    ll v, s, t;
    Data(ll v, ll s, ll t): v(v), s(s), t(t) {}
    bool operator<(const Data& a) const {
        return t>a.t;
    }
};

vector<Edge> edges[MAX_N];
vector<Data> nodes(MAX_N, Data{0, 0, 0});
ll dp[MAX_N][MAX_S+5];

void Main(){
    ll N, M, S;
    ll u, v, a, b, c, d;
    rep(i, MAX_N){
        rep(j, MAX_S+5){
            dp[i][j] = INF;
        }
    }
    cin >> N >> M >> S;
    rep(i, M){
        cin >> u >> v >> a >> b;
        -- u;
        -- v;
        edges[u].emplace_back(v, a, b);
        edges[v].emplace_back(u, a, b);
    }
    rep(i, N){
        cin >> c >> d;
        nodes[i] = Data{i, c, d};
    }
    S = min(S, MAX_S);
    priority_queue<Data> PQ;

    auto push = [&](ll v, ll s, ll x){
        if(s<0) return;
        if(dp[v][s]<=x) return;
        PQ.emplace(v, s, x);
    };
    push(0, S, 0);
    // Data dd = PQ.top();
    // cout << "u,s,t=" << dd.v << "," << dd.s << "," << dd.t <<endl;
    
    while(!PQ.empty()){

        Data d = PQ.top();
        PQ.pop();
        // cout << "u,s,t=" << d.v << "," << d.s << "," << d.t <<endl;

        // if(d.t==0 && d.v != 0){
            // cout << "u,s,t=" << d.v << "," << d.s << "," << d.t <<endl;
            // break;

        // }
        if(d.t >= dp[d.v][d.s]) continue;
        // if(d.s >= 100) break;
        dp[d.v][d.s] = d.t;
        ll ns = min(d.s+nodes[d.v].s, MAX_S);
        push(d.v, ns, d.t+nodes[d.v].t);

        for(auto e:edges[d.v]){
            push(e.u, d.s-e.a, d.t+e.b);
        }

    }

    rep(i, N){
        if(i == 0) continue;
        ll v = INF;
        rep(j, MAX_S){
            v = min(dp[i][j], v);
        }

        cout << v <<endl;
    }

}

int main(){
    Main();
}