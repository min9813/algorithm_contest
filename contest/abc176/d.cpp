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

static const ll ndim = 4;
static const ll max_l = 1010;
static const ll INF = 1e15;
vector<ll> dx = {-1, 0, 1, 0};
vector<ll> dy = {0, -1, 0, 1};
char field[max_l][max_l];
ll searched[max_l][max_l];
// vector<vector<ll>> n_d = {{1, 0, -1}, {2, 1, 0, -1, -2}};

// vector<vector<char>> F;
// vector<vector<ll>> num_w;
ll H, W, Ch, Cw, Dh, Dw;

struct node{
    ll x, y, d;

    bool operator<(const node& n1){
        return d < n1.d;
    }


};

bool compare_node(node &n1, node &n2){
    return n1.d < n2.d;
}
// istream& operator>>(istream& is, const node& a) { return is >> a.d;}


void Main(){
    cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
    -- Ch;
    -- Cw;
    -- Dh;
    -- Dw;

    rep(i, H){
        rep(j, W){
            cin >> field[i][j];
            searched[i][j] = INF;
        }
    }

    deque<node> DQ;
    DQ.push_front(node{Ch, Cw, 0});
    searched[Ch][Cw] = 0;
    while (!DQ.empty())
    {
        node n = DQ.front();
        DQ.pop_front();
        if(n.d > searched[n.x][n.y]){
            continue;
        }

        rep(i, dx.size()){
            ll nx = n.x + dx[i];
            ll ny = n.y + dy[i];
            if(nx < 0 || nx >= H) continue;
            if(ny < 0 || ny >= W) continue;
            if(field[nx][ny] == '#') continue;
            if(searched[nx][ny]<=n.d){
                continue;
            }
            searched[nx][ny] = n.d;
            DQ.push_front(node{nx, ny, n.d});
        }

        for(ll ndx=-2;ndx<=2;ndx++){
            for(ll ndy=-2; ndy<=2;ndy++){
                ll nx = n.x + ndx;
                ll ny = n.y + ndy;
                if(nx < 0 || nx >= H) continue;
                if(ny < 0 || ny >= W) continue;
                if(field[nx][ny] == '#') continue;
                if(searched[nx][ny]<=n.d+1){
                    continue;
                }
                searched[nx][ny] = n.d+1;
                DQ.push_back(node{nx, ny, n.d+1});
            }
        }
    }

    ll ans = searched[Dh][Dw];
    if(ans == INF){
        cout << "-1" <<endl;
    }else{
        cout << ans <<endl;
    }
    





}

int main(){
    Main();
}