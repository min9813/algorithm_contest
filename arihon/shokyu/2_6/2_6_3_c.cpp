#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <prettyprint.hpp>
typedef long long ll;
using namespace std;
static const ll mod = 1000000007;
static const ll max_n = 200000;
vector<ll> factorial(max_n+1);
vector<ll> factorial_inv(max_n+1);

bool is_prime(ll N){
    ll i=2;
    while(i*i<N){
        if(N % i == 0){
            return false;
        }else{
            i ++;
        }
    }
    if(N % i == 0){
        return false;
    }
    return true;
}

template<typename T>
vector<T> divisor(T N){
    vector<T> divisors_list;
    T i = 1;
    for(i = 1;i*i<N;i++){
        if(N % i == 0){
            divisors_list.emplace_back(i);
            divisors_list.emplace_back(N / i);
        }
    }

    if(N % i == 0){
        divisors_list.emplace_back(i);
    }

    return divisors_list;

}

template<typename T>
map<T, T> prime_factor(T N){
    map<T, T> res;
    ll i = 2;
    for(i=2;i*i<=N;i++){
        while(N%i==0){
            ++res[i];
            N /= i;
        }
    }
    if(N!=1){
        res[N] = 1;
    }
    return res;
}

ll mpow(ll base, ll power){
    if(power==0){
        return 1;
    }
    ll b = mpow(base, power/2);
    b *= b;
    b %= mod;
    if(power % 2==1) b = (b * base) % mod;
    return b;
}

void initialze_factorial(){
    factorial[0] = 1;
    factorial[1] = 1;
    ll v = 1;
    for(ll i=2;i<=max_n;i++){
        v *= i;
        v %= mod;
        factorial[i] = v;
    }

    factorial_inv[max_n] = mpow(factorial[max_n], mod-2);
    // printf("max n inv = %lld\n", factorial_inv[max_n]);

    for(ll i=max_n-1;i>=2;i--){
        factorial_inv[i] = (factorial_inv[i+1] * (i+1)) % mod;
    }

    factorial_inv[0] = 1;
    factorial_inv[1] = 1;

}


int main(){
    ll N, M;
    scanf("%lld %lld", &N, &M);
    initialze_factorial();
    map<ll, ll> primes = prime_factor(M);
    // cout << primes <<endl;
    // for(int i=0;i<10;i++){
    //     printf("f[%d]=%lld ", i, factorial[i]);
    // }
    // printf("f^-1[%lld]=%lld", max_n, factorial[max_n]);

    // printf("\n");
    // for(int i=0;i<10;i++){
    //     printf("f^-1[%d]=%lld ", i, factorial_inv[i]);
    // }
    // printf("f^-1[%lld]=%lld", max_n, factorial_inv[max_n]);
    // printf("\n");


    ll ans = 1;
    for(const auto &key: primes){
        ans *= factorial[key.second+N-1];
        ans %= mod;
        ans *= factorial_inv[key.second];
        ans %= mod;
        ans *= factorial_inv[N-1];
        ans %= mod;
    }

    printf("%lld\n", ans);
    return 0;
}