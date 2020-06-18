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
static const ll INF = 1e18;

vector<ll> dx = {0, -1, 0, 1};
vector<ll> dy = {-1, 0, 1, 0};


void Main(){
    ll H, W, K;
    cin >> H >> W >> K;

    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    -- sx;
    -- sy;
    -- tx;
    -- ty;

    
    vector<string> field(H);
    rep(i, H){
        cin >> field[i];
    }
    vector<ll> dist(H*W*4, INF);

    priority_queue<pll, vector<pll>, greater<pll>> PQ;

    auto toid = [&](ll x, ll y, ll nd){
        return x * W * 4 + y * 4 + nd;
    };

    auto push = [&](int x, int y, int nd, ll d){
        ll id = toid(x, y, nd);
        if(dist[id]<= d){
            return;
        }
        dist[id] = d;
        PQ.emplace(d, id);
    };

    auto mod_ceil = [&](ll d){
        return (d + K - 1) / K * K;
    };

    rep(v, 4) push(sx, sy, v, 0);

    while(!PQ.empty()){
        ll d = PQ.top().first;
        ll id = PQ.top().second;
        PQ.pop();
        if(d!=dist[id]) continue;
        ll i = id / W / 4;
        ll j = id / 4 % W;
        ll v = id % 4;
        rep(nv, 4) push(i, j, nv, mod_ceil(d));
        ll next_i = i + dx[v];
        ll next_j = j + dy[v];
        if(next_i >= 0 && next_i < H && next_j >= 0 && next_j < W){
            if(field[next_i][next_j] == '.'){
                push(next_i, next_j, v, d+1);
            }
        }

    }

    ll ans = INF;
    rep(v, 4){
        ans = min(ans, dist[toid(tx, ty, v)]);
    }

    if(ans == INF){
        cout << "-1"<<endl;
    }else{
        cout << mod_ceil(ans) / K <<endl;
    }




}

int main(){
    Main();
}