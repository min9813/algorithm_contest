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

static const ll max_n = 1000010;

vector<ll> primes(max_n);
vector<bool> is_prime(max_n, true);

ll sieve(ll N){
    // fill(is_prime.begin(), is_prime.end(), true);
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

void Main(){
    ll N, a;
    sll(N);
    vector<ll> as(N,0);
    map<ll, ll> counter;
    bool has_one = false;
    rep(i, N){
        sll(a);
        as[i] = a;
        has_one = has_one || (a == 1);
        ++counter[a];
    }

    sort(as.begin(), as.end());
    // sieve;
    ll one_num = counter[1];
    if(one_num==1){
        cout << "1" <<endl;
        return;
    }else if(one_num>1){
        cout << "0" <<endl;
        return;
    }
    ll num_p = 0;
    for(ll i=one_num;i<N;i++){
        // printf("i=%lld a=%lld\n", i, as[i]);
        a = as[i];
        if(is_prime[a]){
            primes[num_p++] = a;
            for(ll j=a;j<=max_n;j+=a){
                is_prime[j] = false;
            }
        }
    }

    // cout << counter <<endl;
    // cout << primes[0] << " " <<primes[1] << " "<<primes[2] <<endl;

    ll dup = 0;
    rep(i, num_p){
        // printf("primes %lld=%lld\n", i, primes[i]);
        if(counter[primes[i]]>1){
            ++ dup;
        }
    }

    // cout << "num p = " << num_p << " dup:" <<dup <<endl;
    cout << num_p - dup <<endl;

}

int main(){
    Main();
}