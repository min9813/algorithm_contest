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
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define repi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
typedef long long ll;
typedef double lf;
typedef short int si;

static const ll INF = 1 << 24;
static const ll max_n = 1010;
vector<pii> X;
vector<pii> Y;

vector<si> dx = {0, -1, 0, 1};
vector<si> dy = {-1, 0, 1, 0};

ll W, H, N;

ll compress(vector<pii> &x, ll w){
    vector<int> vs;
    rep(i, N){
        for(short int d=-1;d<=1;d++){
            int x1 = x[i].first + d;
            int x2 = x[i].second + d;
            if(0<= x1 && x1 < w){
                vs.push_back(x1);
            }

            if(0<=x2 && x2 < w){
                vs.push_back(x2);
            }
        }
    }

    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());

    // cout << "size = " << vs.size() <<endl;
    // rep(i, vs.size()){
        // cout << "vs[" << i << "] = " << vs[i] <<endl;
    // }
    rep(i, N){
        int x1 = find(vs.begin(), vs.end(), x[i].first) - vs.begin();
        int x2 = find(vs.begin(), vs.end(), x[i].second) - vs.begin();
        // auto it = lower_bound(vs.begin(), vs.end(), x[i].first);
        // cout << "find it=" << *it << ", search i =" << x[i].first << endl;
        // if(*it != x[i].first){
            // printf("comething wrong x 1 !\n");
            // exit(1);
        // }
        // ll x1 = it - vs.begin();
        // cout << "it = " << *it << " distance = " << x1 << endl;
        // it = lower_bound(vs.begin(), vs.end(), x[i].second);
        // ll x2 = it - vs.begin();
        // if(*it != x[i].second){
            // printf("comething wrong x 2 !\n");
            // exit(1);
        // }
        x[i] = make_pair(x1, x2);
    }

    return vs.size();
}



void Main(){
    sll(W);
    sll(H);
    sll(N);
    int x1, x2, y1, y2;
    rep(i, N){
        sii(x1);
        sii(y1);
        sii(x2);
        sii(y2);

        X.emplace_back(x1, x2-1);
        Y.emplace_back(y1, y2-1);
    }

    // cout << "x = " << X <<endl;
    // cout << "y = " << Y <<endl;


    W = compress(X, W);
    H = compress(Y, H);

    // cout << "new x = " << X <<endl;
    // cout << "new y = " << Y <<endl;

    // cout << "new W, H = " << W << "," <<H <<endl;

    vector<vector<short int>> field(H+1, vector<short int>(W, 0));
    // vector<vector<short int>> rows(H+1, vector<short int>(W, 0));
    for(int i=0;i<N;i++){
        // for(ll y=Y[i].first; y<=Y[i].second;y++){
        for(int x=X[i].first;x<=X[i].second;x++){
                // cout << "x,y = " << x << "," << y << endl;
            field[Y[i].first][x] ++;
            field[Y[i].second+1][x] --;
        }
        // }
    }

    // cout << " ok !" <<endl;

    for(int i=1;i<H;i++){
        for(int j=0;j<W;j++){
            // row_cum[j] += rows[i][j];
            field[i][j] += field[i-1][j];
        }

        // field[i] = row_cum;
    }

    // rep(i, H){
        // cout << "field y="<<i <<":"<< field[i]<<endl;
    // }

    // cout << "ok ! "<<endl;

    ll ans = 0;
    for(si i=0;i<H;i++){
        for(si j=0;j<W;j++){
            if(field[i][j]) continue;
            queue<psi> queue;
            queue.push(make_pair(i,j));
            ans ++;
            while(!queue.empty()){
                psi coord = queue.front(); queue.pop();
                // cout << coord << " ans = " << ans << endl;
                // field[coord.first][coord.second] = 1;
                field[coord.first][coord.second] = 1;
                for(si i=0;i<4;i++){
                    si y1 = coord.first + dy[i];
                    si x1 = coord.second + dx[i];
                    if(0<=x1 && x1< W && 0<= y1 && y1 < H && field[y1][x1]<=0){
                        field[y1][x1] = 1;
                        // field[y1][x1] = true;
                        queue.push(make_pair(y1, x1));
                    }
                }
            }
        }
    }

    cout << ans <<endl;

    
}

int main(){
    Main();

    return 0;

}