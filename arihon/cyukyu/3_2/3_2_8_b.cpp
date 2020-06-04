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

static const ll INF = 1 << 24;
static const ll max_n = 310;
vector<pii> X;
vector<pii> Y;
vector<pii> Z;

vector<si> dx = {0, 0, -1, 0, 0, 1};
vector<si> dy = {0, -1, 0, 0, 1, 0};
vector<si> dz = {-1, 0, 0, 1, 0, 0};

vector<vector<vector<si>>> field(max_n, vector<vector<si>>(max_n, vector<si>(max_n, 0)));

ll N, K, W, H, D;

map<int, ll> compress(vector<pii> &x){
    vector<int> vs;
    map<int, ll> new2old;
    rep(i, N){
        // for(short int d=-1;d<=1;d++){
            int d = 0;
            int x1 = x[i].first + d;
            int x2 = x[i].second + d;
            // if(0<= x1 && x1 < w){
            vs.push_back(x1);
            // }

            // if(0<=x2 && x2 < w){
            vs.push_back(x2);
            // }
        // }
    }

    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    repi(i, vs.size()){
        new2old[i] = vs[i];
    }
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

    return new2old;
}



void Main(){
    // sll(W);
    // sll(H);
    sll(N);
    sll(K);
    int x1, x2, y1, y2, z1, z2;
    rep(i, N){
        sii(x1);
        sii(y1);
        sii(z1);
        sii(x2);
        sii(y2);
        sii(z2);

        X.emplace_back(x1, x2);
        Y.emplace_back(y1, y2);
        Z.emplace_back(z1, z2);
    }

    // cout << "x = " << X <<endl;
    // cout << "y = " << Y <<endl;


    auto x_map = compress(X);
    auto y_map = compress(Y);
    auto z_map = compress(Z);
    W = x_map.size();
    H = y_map.size();
    D = z_map.size();

    // cout << "new x = " << X <<endl;
    // cout << "new y = " << Y <<endl;
    // cout << "new z = " << Z <<endl;

    // cout << "map x = " << x_map <<endl;
    // cout << "map y = " << y_map <<endl;
    // cout << "map z = " << z_map <<endl;

    // cout << "new W, H, D = " << W << "," <<H <<"," << D<<endl;

    // vector<vector<vector<short int>>> field(D+1, vector<short int>(W, 0));
    // vector<vector<short int>> rows(H+1, vector<short int>(W, 0));
    for(int i=0;i<N;i++){
        // for(ll y=Y[i].first; y<=Y[i].second;y++){
        for(int z=Z[i].first;z<Z[i].second;z++){
            field[z][Y[i].first][X[i].first] ++;
            field[z][Y[i].first][X[i].second] --;
            field[z][Y[i].second][X[i].first] --;
            field[z][Y[i].second][X[i].second] ++;
        }
        // }
    }

    // rep(i, D){
    //     cout << " z = " << i << endl;
    //     rep(j, H){
    //         cout << "y=" <<j << " ";
    //         rep(k, W){
    //             cout << field[i][j][k] << " " ;
    //         }
    //         cout << endl;
    //     }
    // }

    // cout << " ok !" <<endl;

    repi(i, D){
        for(int j=0;j<H;j++){
            for(int k=1;k<W;k++){
                field[i][j][k] += field[i][j][k-1];
            }
        }

        for(int j=1;j<H;j++){
            for(int k=0;k<W;k++){
                field[i][j][k] += field[i][j-1][k];
            }
        }
    }

    // rep(i, D){
    //     cout << " z = " << i << endl;
    //     rep(j, H){
    //         cout << "y=" <<j << " ";
    //         rep(k, W){
    //             cout << field[i][j][k] << " " ;
    //         }
    //         cout << endl;
    //     }
    // }

    ll ans = 0;
    repi(i, D){
        repi(j,H){
            repi(k, W){
                if(field[i][j][k] >= K){
                    ans += (x_map[k+1]-x_map[k]) * (y_map[j+1]-y_map[j]) * (z_map[i+1]-z_map[i]);
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