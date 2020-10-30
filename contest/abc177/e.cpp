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

static const string PAIR = "pairwise coprime";
static const string SET = "setwise coprime";
static const string NOT = "not coprime";

static const ll MAX_N = (1e6)+10;

ll as[MAX_N];


vector<ll> primes(MAX_N);
vector<ll> least_factors(MAX_N);
vector<bool> is_prime(MAX_N, true);

ll sieve(ll N){
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = false;
    is_prime[1] = false;
    least_factors[0] = 0;
    least_factors[1] = 1;
    ll num_p=0;
    for(ll i=2;i<N;i++){
        if(is_prime[i]){
            primes[num_p++] = i;
            for(ll j=2*i;j<N;j+=i){
                is_prime[j] = false;
                least_factors[j] = i;
            }
            least_factors[i] = i;
        }
    }
    return num_p;
}

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

map<ll, ll> factorize_fast(ll a){
    map<ll, ll> ans;
    while(least_factors[a] != a){
        ++ ans[least_factors[a]];
        a = a / least_factors[a];
    }
    // cout << "a=" << a << " fac:" << ans <<endl;
    ++ ans[a];

    return ans;
}

void Main(){
    ll num_p = sieve(MAX_N);
    ll N, a;
    cin >> N;

    ll prod = 1;
    set<ll> found_ps;
    bool is_pair = true;

    // cout << "num_p " << num_p <<endl;
    // rep(i, num_p){
    //     if(i<num_p-100)continue;
    //     cout << primes[i] << " ";
    // }
    // cout << endl;
    // exit(1);
    set<ll> unique_val;
    ll max_v = 0;
    ll min_v = MAX_N;
    rep(i, N){
        cin >> a;
        as[i] = a;
    }

    map<ll, ll> all_factors;
    rep(i, N){
        auto factors = factorize_fast(as[i]);
        ll before_length = all_factors.size();
        ll add_num = 0;
        for(auto p:factors){
            if(p.first == 1){
                continue;
            }
            all_factors[p.first] = p.second;
            add_num += 1;
        }
        // cout << factors << endl;
        ll after_length = all_factors.size();
        // cout << " b_l:" << before_length << " a_l:" << after_length << " add:" << add_num <<endl;

        if(after_length < before_length + add_num){
            is_pair = false;
            break;
        }
    }



    if(!is_pair){
        ll com_gcd = gcd(as[0], as[1]);
        bool is_set = com_gcd == 1;
        for(ll i=2;i<N && com_gcd;++i){
            com_gcd = gcd(com_gcd, as[i]);
            if(com_gcd == 1){
                is_set = true;
                break;
            }
        }
        if(is_set){
            cout << SET <<endl;
        }else{
            cout << NOT <<endl;
        }
    }else{
        cout << PAIR <<endl;
    }

}

int main(){
    Main();
}