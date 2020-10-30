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

static const ll max_r = 3001;
static const ll max_c = 3001;

vector<vector<ll>> field(max_r, vector<ll>(max_c, 0));
vector<vector<vector<ll>>> dp(max_r, vector<vector<ll>>(max_c, vector<ll>(4, 0)));

void Main(){
    ll R, C, K, r, c, v;
    cin >> R >> C >> K;
    rep(i, K){
        cin >> r >> c >> v;
        --r;
        --c;
        field[r][c] = v;
        // items[r].emplace_back(c, v);

    }

    rep(i, R){
        rep(j, C){
            // if(field[i][j] > 0)
            if(i>0){
                rep(n, 4){
                    dp[i][j][0] = max(dp[i-1][j][n], dp[i][j][0]);
                }
            }
            if(field[i][j]>0){
                dp[i][j][1] = dp[i][j][0] + field[i][j];
            }


            if(j>0){
                rep(n, 3){
                    if(field[i][j]>0){
                        ll v = max(dp[i][j-1][n] + field[i][j], dp[i][j-1][n+1]);
                        dp[i][j][n+1] = max(v, dp[i][j][n+1]);
                    }else{
                        dp[i][j][n] = max(dp[i][j][n], dp[i][j-1][n]);
                        dp[i][j][n+1] = max(dp[i][j][n], dp[i][j-1][n+1]);
                    }
                }
            }
            // rep(n, 4){
                // printf("dp[%lld][%lld][%lld]=%lld \n", i, j, n, dp[i][j][n]);
            // }
        }
    }

    ll score = 0;
    rep(n, 4){
        score = max(score, dp[R-1][C-1][n]);
    }
    cout << score <<endl;

}

int main(){
    Main();
}