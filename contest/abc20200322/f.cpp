#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
struct edge{
    ll to;
    ll w;
};
static const ll max_n = 3010;
// static const ll max_abs_value = 1000000010;
static const ll mod = 998244353;
// vector<vector<ll>>dp(max_n, vector<ll>(max_n, 0));
vector<ll>dp(max_n, 0);
vector<ll> value_list(max_n);
// int N;
ll N, S;

int main(){
    // int u, v;
    // bool updated = false;
    ll ans = 0, u, v;
    scanf("%lld %lld", &N, &S);
    for(ll i=0;i<N;i++){
        scanf("%lld", &u);
        value_list[i] = u;
    }

    // ll ans = 0;

    // dp[0] = 1;
    for(ll i=0;i<N;i++){
        (dp[0] += 1) %= mod;
        vector<ll> dp2(max_n, 0);
        for(ll w=0;w<=S;w++){
            if(w+value_list[i] <= S){
                (dp2[w + value_list[i]] += dp[w]) %= mod;
            }
            ((dp2[w] += dp[w])) %= mod;
        }
        dp = dp2;
        ans += dp[S];
        ans %= mod;
    }
    // ans = dp[S];

    printf("%lld\n", ans);


    return 0;

}