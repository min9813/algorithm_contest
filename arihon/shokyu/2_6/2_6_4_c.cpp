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
    for(ll i=2;i<=N;i++){
        if(is_prime[i]){
            primes[num_p++] = i;
            for(ll j=2*i;j<=N;j+=i){
                is_prime[j] = false;
            }
        }
    }
    return num_p;
}

int main(){
    ll N, gcd_num;
    char c[10];
    sieve(max_n);
    while(cin >> N){
        printf("%lld\n", sieve(N));
    }

    // printf("%lld\n", sieve(N));
    return 0;
}
// int main() {
//     vector<bool> is_prime(1000000, true);
//     vector<int> prime;
//     is_prime[0] = is_prime[1] = false;
//     for(int i=2; i<is_prime.size(); ++i) {
//         if(is_prime[i]) {
//             prime.push_back(i);
//             for(int j=i+i; j<is_prime.size(); j+=i) {
//                 is_prime[j] = false;
//             }
//         }
//     }
//     int n;
//     while(cin >> n) {
//         cout << upper_bound(prime.begin(), prime.end(), n) - prime.begin() << endl;
//     }
// }