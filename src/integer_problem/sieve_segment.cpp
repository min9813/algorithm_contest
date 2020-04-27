#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <prettyprint.hpp>
typedef long long ll;
using namespace std;
// 22801787297
static const ll max_n = 1000000;
static const ll max_interval = 1000010;

// vector<ll> primes(max_n);
vector<bool> is_prime_small(max_n, true);
vector<bool> is_prime(max_interval, true);
vector<vector<pair<ll,ll>>> primes(max_interval);
vector<ll> devided_numbers(max_interval, -1);

void sieve_segment(ll L, ll R){
    // fill(is_prime.begin(), is_prime.end(), true);
    is_prime_small[0] = false;
    is_prime_small[1] = false;
    // ll num_p=0;
    for(ll i=L;i<R;i++){
        devided_numbers[i-L] = i;
    }
    for(ll i=2;i*i<R;i++){
        if(is_prime_small[i]){
            // primes[num_p++] = i;
            for(ll j=2*i;j*j<R;j+=i){
                is_prime_small[j] = false;
            }
            for(ll j=((L+i-1) / i) * i; j<R;j+=i){
                // if(j<L){
                    // printf("j=%lld, L=%lld, i=%lld, exit!\n", j, L, i);
                    // exit(1);
                // }
                is_prime[j-L] = false;
                // if(devided_numbers[j-L]==-1){
                //     devided_numbers[j-L] = j;
                // }
                ll power_num = 0;
                ll num = devided_numbers[j-L];
                while(num%i==0){
                    power_num ++;
                    num /= i;
                }
                devided_numbers[j-L] = num;
                primes[j-L].push_back(make_pair(i, power_num));
            }
        }
    }
    // return num_p;
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

int main(){
    // ll N, a, b, c, gcd_num;
    ll L, R;

    scanf("%lld %lld", &L, &R);
    // printf("okok!");
    R++;
    // printf("okok!");
    sieve_segment(L, R);
    // printf("ok!\n");
    // exit(0);
    ll ans = 0;
    for(ll i=L;i<R;i++){
        if(is_prime[i-L]) continue;
        // auto res = prime_factor(i);
        // printf("%lld\n", )
        // cout << "i="<<i<<" "<<primes[i-L] <<endl;
        ll num = 0;
        for(const auto &p:primes[i-L]){
            num += p.second;
        }
        if(devided_numbers[i-L]>1){
            num += 1;
        }
        ans += (ll)is_prime_small[num];
    }
    printf("%lld\n", ans);
    return 0;
}