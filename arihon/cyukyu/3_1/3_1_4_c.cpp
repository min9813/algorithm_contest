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
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,n) for(ll i=n-1;i>=0;i--)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 51;
static const ll mod = 2019;
static const ll max_value = 100000000000100;
vector<vector<vector<ll>>> dp(max_n, vector<vector<ll>>(max_n, vector<ll>(max_n*max_n, 0)));
// static const ll max_x = max_value * max_value;
vector<ll> cards(max_n);
// vector<ll> S(max_n);
// vector<pair<ll, ll>> times_vec(max_n);
ll N, M;


int main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, A, x, sum=0;
    sll(N);
    sll(A);
    rep(i, N){
        sll(x);
        cards[i] = x;
        // dp[0][i][x] = 1;
        sum += x;
    }

    rep(j,N+1){
        dp[0][j][0] = 1;
    }

    // dp[0][0][0] = 1;
    rep(i, N){
        // i++;
        rep(j, N){
            // j++;
            rep(k,sum+1){
                // printf("k - cards[%lld] = %lld, cards[%lld]=%lld\n", j, k-cards[j], j, cards[j]);
                ll v = dp[i+1][j][k];
                if(k-cards[j]>=0){
                    // printf("k - cards, dp[%lld][%lld][%lld]=%lld\n", i, j, k-cards[j], dp[i][j][k-cards[j]]);
                    v += dp[i][j][k-cards[j]];
                }
                dp[i+1][j+1][k] = v;
            }
        }
    }

    ll num = 0;
    rep(i,N){
        // i ++;
            // j ++;
        // printf("#### dp[%lld][%lld][%lld] = %lld\n", i+1, N, (i+1)*A, dp[i+1][N][(i+1)*A]);
        num += dp[i+1][N][(i+1)*A];
    }

    // cout<<fixed<<setprecision(10)<<num<<endl;
    cout << num << endl;
    return 0;

}

// ll main(){
//     Main();

//     return 0;

// }