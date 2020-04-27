#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
static const ll max_n = 100010;

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
    ll Q, l, r, c, gcd_num;
    scanf("%lld", &Q);
    vector<ll> cum_sum(max_n, 0);
    sieve(max_n);
    cum_sum[0] = 0;
    cum_sum[1] = 0;
    cum_sum[2] = 0;
    for(ll i=3;i<=max_n;i+=2){
        bool is_ok = (is_prime[i] && is_prime[(i+1)/2]);
        cum_sum[i] = ((ll)is_ok + cum_sum[i-2]);
        cum_sum[i+1] = cum_sum[i];
        // printf("cum sum[%lld] = %lld\n", i, cum_sum[i]);
    }
    vector<ll> answers;
    for(ll i=0;i<Q;i++){
        scanf("%lld %lld", &l, &r);
        ll ans = cum_sum[r] - cum_sum[l-1];
        answers.push_back(ans);
    }

    for(auto ans:answers){
        printf("%lld\n", ans);
    }

    // printf("%lld\n", sieve(N));
    return 0;
}