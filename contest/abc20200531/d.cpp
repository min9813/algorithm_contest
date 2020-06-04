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
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 200010;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;
static const ll max_d = 10000000000;


vector<vector<ll>> edge_list(max_n);
vector<pair<ll, ll>> distance_table;

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
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N;
    sll(N);
    auto primes = prime_factor(N);

    ll ans = 0;
    for(auto prime_p: primes){
        ll prime = prime_p.first;
        ll power = prime_p.second;
        ll k;
        for(k=1;k*(k+1)<= 2*power;k++){
            continue;
        }
        // printf("prime = %lld, poewr = %lld\n", prime, k);
        ans += k - 1;
    }
    cout << ans <<endl;
    // cout << junkan<<endl;

    // ll index = (K % junkan.size());
    // printf("%lld\n", junkan[index]+1);
    

    // printf("%lld\n", ans);


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}