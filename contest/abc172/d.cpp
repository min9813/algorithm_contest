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

ll max_n = 10000010;


vector<ll> primes(max_n);
vector<bool> is_prime(max_n, true);
vector<bool> is_found(max_n, false);
vector<map<ll,ll>> prime_factors(max_n);

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

void Main(){
    ll N;
    sll(N);
    ll ans = 0;
    rep(i, N+1){
        ll j = i + 1;
        ll max_d = N / j;
        ll this_add = (1 + max_d) * max_d / 2;
        ans += this_add * j;
    }
    
    cout << ans << endl;
    


}

int main(){
    Main();
}