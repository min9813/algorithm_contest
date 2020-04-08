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
vector<pair<T, T>> prime_fatorize(T N){
    vector<pair<T, T>> primes;
    T power_it;

    for (T p = 2; p*p<=N; p++){
        if(N%p != 0) continue;
        power_it = 0;
        while(N%p == 0){
            ++power_it; 
            N /= p; 
        }
        primes.push_back(make_pair(p, power_it));
    }

    if (N != 1){
        primes.push_back(make_pair(N, 1));
    }

    return primes;

}

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
    llong N, M, sign;
    scanf("%lld %lld", &M, &N);
    if(M < 0){
        sign = 1;
        M = - M ;
    }else{
        sign = 0;
    }
    for(llong i=1; i<(llong)factor.size();i++){
        factor[i] = factor[i-1] * i % mod;
        inverse_factor[i] = inverse_factor[i-1] * mod_pow(i, mod-2) % mod;
        // if(i<= 10){
            // printf("factor [%lld] = %lld\n", i, factor[i]);
            // printf("inverse factor [%lld] = %lld\n", i, inverse_factor[i]);
        // }

    }
    auto primes = prime_fatorize(M);

    llong signed_ans = 1;
    for(auto &prime: primes){
        // printf("prime: %lld ^ %lld\n", prime.first, prime.second);
        signed_ans = (signed_ans * mod_comb(prime.second + (N - 1), prime.second)) % mod;
    }

    llong coef = 0;
    if(N % 2 == 0){
        for(llong i=sign;i*2<N;i+=2){
            coef = (coef + mod_comb(N, i)) % mod;
        }
        coef = (2 * coef) % mod;
        if(N/2 % 2 == sign){
            coef = (coef + mod_comb(N, N/2)) % mod;
        }
    }else{
        coef = mod_pow((llong)2, N-1);
    }

    // printf("coef=%lld\n", coef);

    signed_ans = (coef * signed_ans) % mod; 



    printf("%lld\n", signed_ans);

}