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
#include <assert.h>
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

static const ll max_n = 500200;
static const ll max_v = 1e15;
static const ll N = 7368800;
static const string TIE = "TIE";
vector<char> ns[max_n];

// vector<ll> primes(max_n);
vector<bool> is_prime(N, true);

ll sieve(ll l, ll k){
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = false;
    is_prime[1] = false;
    ll num_p=0;
    ll num = 0;
    for(ll i=l;num<k;i++){
        if(is_prime[i]){
            is_prime[i] = false;
            // primes[num_p++] = i;
            for(ll j=2*i;j<N;j+=i){
                is_prime[j] = false;
            }
            ++num;
        }
    }
    return num_p;
}

void Main(){
    ll m, n;
    vector<ll> ms, ns;
    while(true){
        cin >> m >> n;
        if(m==0 && n==0) break;
        ms.emplace_back(m);
        ns.emplace_back(n);
    }

    ll size = ms.size();
    rep(i, size){
        n = ns[i];
        m = ms[i];
        fill(is_prime.begin(), is_prime.end(), true);
        sieve(m, n);
        ll ans;
        // cout << "m=" << m <<", n+m+1=" << n + m <<endl;;
        for(ll j=m;j<=N;j++){
            if(is_prime[j]){
                ans = j;
                break;

            }
        }
        cout << ans <<endl;
    }


}

int main(){
    Main();
}