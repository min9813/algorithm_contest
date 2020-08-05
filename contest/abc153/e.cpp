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

static const ll max_v = 1e15;



void Main(){
    ll H, N, a, b;
    cin >> H >> N;
    vector<ll> as(N);
    vector<ll> bs(N);
    ll max_a = H;
    rep(i, N){
        sll(as[i]);
        sll(bs[i]);
        max_a = max(max_a, as[i]);
    }


    vector<ll> dp(2*max_a+10, max_v);
    dp[0] = 0;
    rep(i, 2*max_a+1){
        rep(j, N){
            if(i>=as[j]){
                dp[i] = min(dp[i-as[j]]+bs[j], dp[i]);
            }
        }
    }

    ll ans = max_v;
    for(ll i=H;i<=2*max_a;i++){
        ans = min(dp[i], ans);
    }

    cout << ans <<endl;


}

int main(){
    Main();
}