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
    string S;
    cin >> S;
    ll N = S.size();
    vector<vector<ll>> dp(N+1, vector<ll>(2,0));
    dp[0][0] = 1;
    // dp[1][1] = 1;
    rep(i, N){
        rep(j, 2){

            ll max_d;
            if(j==0){
                max_d = S[i] - '0';
            }else{
                // if(i==0){
                //     continue;
                // }
                max_d = 9;
            }
            printf("i=%lld, j=%lld, max_d=%lld\n", i, j, max_d);
            for(ll d=0;d<=max_d;d++){
                dp[i+1][j||d<S[i]-'0'] += dp[i][j];
            }
        }

    }
    rep(i, N+1){
        rep(j, 2){
            printf("dp[%lld][%lld]=%lld\n", i, j, dp[i][j]);
        }
    }

    cout << dp[N][1] + dp[N][0] <<endl;


}

int main(){
    Main();
}