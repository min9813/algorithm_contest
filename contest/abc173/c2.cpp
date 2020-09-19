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
    cin >> H >> W >> K;
    vector<vector<char>> F(H, vector<char>(W, '.'));
    rep(i, H){
        rep(j, W){
            cin >> F[i][j];
        }
    }

    ll ans = 0;
    for(ll bit_h=0;bit_h<(1<<H); ++bit_h){
        for(ll bit_w=0;bit_w<(1<<W);++bit_w){
            vector<vector<char>> F2 = F;
            rep(i, H){
                if((bit_h>>i)&1){
                    rep(j, W){
                        F2[i][j] = '&';
                    }
                }
            }
            rep(i, W){
                if((bit_w>>i)&1){
                    rep(j, H){
                        F2[j][i] = '&';
                    }
                }
            }

            ll num = 0;
            rep(i, H){
                rep(j, W){
                    num += (F[i][j] == '#') & (F2[i][j] == '#');
                }
            }

            ans += (num == K);

        }
    }

    cout << ans <<endl;
}

int main(){
    // ll a = 10;
    // cout << (a>>1 & 1) << endl;
    Main();
}