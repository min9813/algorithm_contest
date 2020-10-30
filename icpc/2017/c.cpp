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
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vvv(t) vector<vector<vector<t>>>
typedef long long ll;
typedef double lf;
typedef short int si;

static const ll max_d = 13;

v(v(ll))  F(max_d, v(ll)(max_d, 0));

void Main(){
    ll d, w;
    v(ll) answers;
    while(cin >> d >> w){
        if(d==0){
            break;
        }
        rep(i, d){
            rep(j, w){
                cin >> F[i][j];
            }
        }

        ll ans = 0;
        rep(ix, d)rep(iy, d){
            for(ll jx=ix+2;jx<d;++jx){
                for(ll jy=iy+2;jy<w;++jy){
                    // (ix,iy), (jx, jy)
                    ll min_v = 10;
                    for(ll x=ix;x<=jx;++x){
                        min_v = min(F[x][iy], min_v);
                        min_v = min(F[x][jy], min_v);
                    }
                    for(ll y=iy;y<=jy;++y){
                        min_v = min(F[ix][y], min_v);
                        min_v = min(F[jx][y], min_v);
                    }
                    // 池チェック
                    ll max_v = 0;
                    ll s = 0;
                    for(ll x=ix+1;x<jx;++x){
                        for(ll y=iy+1;y<jy;++y){
                            max_v = max(max_v, F[x][y]);
                            s += min_v - F[x][y];
                        }
                    }
                    if(max_v < min_v){
                        ans = max(ans, s);
                    }
                }
            }
        }
        answers.emplace_back(ans);
    }

    rep(i, answers.size()){
        cout << answers[i] <<endl;
    }

}

int main(){
    Main();
}