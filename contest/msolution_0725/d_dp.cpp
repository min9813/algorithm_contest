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
    ll N;
    sll(N);
    vector<ll> dp(N+1);
    vector<ll> as(N+1);
    rep(i, N){
        sll(as[i+1]);
    }

    dp[0] = 1000;
    rep(i, N){
        dp[i+1] = dp[i];
        for(ll j=1;j<=i;j++){
            ll W = dp[j-1] / as[j];
            ll M = dp[j-1] - as[j] * W;
            M = M + as[i+1] * W;
            dp[i+1] = max(dp[i+1], M);
        }
    }
    cout << dp[N] <<endl;
}

int main(){
    Main();
}