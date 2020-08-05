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


void Main(){
    ll H, W, K;
    char c;
    cin >> H >> W >> K;
    vector<vector<ll>> fs(H, vector<ll>(W, 0));

    rep(i, H){
        rep(j, W){
            cin >> c;
            fs[i][j] = (c=='.');
        }
    }
    // cout << "ok" <<endl;
    ll ans = 0;
    for(ll bit=0;bit<(1<<H); ++bit){
        set<ll> use_row;
        for(ll w=0;w<H;++w){
            if(bit & (1<<w)){
                use_row.insert(w);
            }
        }
        for(ll bit2=0;bit2<(1<<W); ++bit2){
            set<ll> use_col;
            for(ll w=0;w<W;++w){
                if(bit2 & (1<<w)){
                    use_col.insert(w);
                }
            }
            vector<vector<ll>> fs2(H, vector<ll>(W, 0));
            rep(h, H){
                bool is_h_ok = use_row.find(h) != use_row.end();
                rep(w, W){
                    bool is_w_ok = use_col.find(w)!= use_col.end();
                    fs2[h][w] = (is_h_ok || is_w_ok);
                }
            }
            ll this_k = 0;
            rep(h, H){
                rep(w, W){
                    this_k += (fs2[h][w] == 0 && fs[h][w] == 0);
                }
            }
            if(this_k == K){
                ans += 1;
            }
        }
    }
    cout << ans <<endl;
}

int main(){
    Main();
}