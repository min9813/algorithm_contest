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
#include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;

static const ll max_row = 10;
static const ll max_col = 10000;
ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll n = 7;
    ll k = 3;
    ll comb = (1 << 4) - 1;

    while(comb < (1 << n)){
        ll x = (comb & -comb); // 最下位の1ビットを取得, 10011110 -> 00000010
        ll y = comb + x; // 最下位から連続する1ビットが全て0になり、連続が終わった次の桁に繰り上げされる。上の例だと 10100000になる。
        vector<ll> s;
        rep(i, n){
            if((comb >> i) & 1){
                s.emplace_back(i);
            }
        }
        cout << s << endl;
        comb = (((comb & ~y) / x) >> 1 ) | y;
    }
    

}

int main(){
    Main();

    return 0;

}