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
using namespace std;
typedef long long ll;
static const ll max_n = 200010;
static const ll mod = 1000000007;
// static const ll max_dist = 10000000;
// vector<vector<ll>> distance_table(max_n, vector<ll>(max_n, max_dist));
// vector<ll> distance_list(max_n);
vector<ll> combination_table(max_n, 0);
vector<ll> value_num(max_n, 0);
vector<ll> combination_minus1_table(max_n, 0);
vector<ll> balls(max_n);

ll N, K;

ll this_num(ll this_k){
    ll m1 = this_k * N % mod;
    ll m2 = ((this_k - 1) * this_k / 2) % mod;
    m2 = (m2 * 2) %mod;
    return (m1 - m2 + 1) % mod;
}


int main(){
    // int u, v;
    // bool updated = alse;
    scanf("%lld %lld", &N, &K);

    ll ans = 0;
    for(ll i=K;i<=N+1;i++){
        ll this_sum = this_num(i);
        // printf("i=%lld, sum = %lld\n", i, this_sum);
        ans += this_sum;
        ans %= mod;
    }

    printf("%lld\n", ans);

    return 0;

}