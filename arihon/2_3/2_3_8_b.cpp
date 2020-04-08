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
typedef long long llong;
// static const int max_n = 110;
// static const int max_s = 20010;
static const llong mod = 1000000007;
// static const int max_v = 10000000;
// vector<int> num_array(max_n);
// vector<vector<int>> dp(max_n, vector<int>(max_s, 0));

vector<llong> factor(300001, 1);
vector<llong> inverse_factor(300001, 1);

template<typename T>
T mod_pow(T base, T power_it){
    // calc base ^ power_it % mod 
    T ans = 1;
    while(power_it != 0){
        if(power_it&1) ans = ans * base % mod;
        base = base * base % mod;
        power_it = power_it >> 1;
    }
    // if(base <= 10){
    //     printf("mod pow %lld ^ %lld = %lld", base ,power_it, ans);
    // }

    return ans;

}

template<typename T>
T mod_comb(T n, T r){
    if(n < r || n < 0) return 0;
    llong devider = inverse_factor[n-r] * inverse_factor[r] % mod;
    return factor[n] * devider % mod;
}

int main(){
    llong N, K;
    scanf("%lld %lld", &N, &K);

    llong n = N + K - 1;
    for(llong i=1; i<(llong)factor.size();i++){
        factor[i] = factor[i-1] * i % mod;
        inverse_factor[i] = inverse_factor[i-1] * mod_pow(i, mod-2) % mod;
        // if(i<= 10){
            // printf("factor [%lld] = %lld\n", i, factor[i]);
            // printf("inverse factor [%lld] = %lld\n", i, inverse_factor[i]);
        // }

    }

    llong ans = inverse_factor[K] * inverse_factor[n-K] % mod;

    ans = (ans * factor[n]) % mod;

    printf("%lld\n", ans);

}