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
#include <stack>
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

    auto toid = [&](ll x, ll y, ll nd){
        return x * W * 4 + y * 4 + nd;
    };

    auto mod_ceil = [&](ll d){
        return (d + K - 1) / K * K;
    };

    queue<pll> Q;

    auto push = [&](int x, int y, int v, ll d){
        ll id = toid(x, y, v);
        if(d >= dist[id]) return;
        dist[id] = d;
        Q.emplace(d, id);
    };

    rep(v, 4){
        push(sx, sy, v, 0);
    }
    while(!Q.empty()){
        ll d = Q.front().first;
        ll id = Q.front().second;
        Q.pop();
        if(dist[id]!=d) continue;

        ll i = id / W / 4;
        ll j = id / 4 % W;
        ll v = id  % 4;
        rep(nv, 4){
            push(i, j, nv, d);
        }
        rep(nv, 4){
            for(ll nk=1;nk<=K;nk++){
                ll ni = i + dx[nv] * nk;
                ll nj = j + dy[nv] * nk;
                // cout << "ni,nj = " << ni << "," <<nj<<endl; 

                if(ni < 0 || ni >= H || nj < 0 || nj >= W || field[ni][nj]=='@'){
                    break;
                }
                ll nid = toid(ni, nj, nv);
                if(d+1>dist[nid]) break;
                if(field[ni][nj] == '.'){
                    push(ni, nj, nv, d+1);
                }
            }

        }

    }
    
    ll ans = INF;
    rep(v, 4){
        ans = min(ans, dist[toid(tx, ty, v)]);
    }
    if(ans == INF){
        cout << "-1" <<endl;
    }else{
        cout << ans << endl;
    }



}

int main(){
    Main();
}