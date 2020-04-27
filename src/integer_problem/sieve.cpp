#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
static const ll max_n = 10000;

vector<ll> primes(max_n);
vector<bool> is_prime(max_n, true);

ll sieve(ll N){
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = false;
    is_prime[1] = false;
    ll num_p=0;
    for(ll i=2;i<N;i++){
        if(is_prime[i]){
            primes[num_p++] = i;
            for(ll j=2*i;j<N;j+=i){
                is_prime[j] = false;
            }
        }
    }
    return num_p;
}

int main(){
    ll N, a, b, c, gcd_num;
    scanf("%lld", &N);

    printf("%lld\n", sieve(N));
    return 0;
}