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


void Main(){
    ll K;
    sll(K);
    ll now_mod = 7 % K;
    ll base10_mod = 1;
    ll n = 1;
    bool is_found = false;
    while(now_mod != 0 && n < K*2){
        base10_mod *= 10;
        base10_mod %= K;
        now_mod += (base10_mod * 7);
        now_mod %= K;
        ++ n;
    }
    if(now_mod != 0){
        n = -1;
    }

    cout << n <<endl;

}

int main(){
    Main();
}