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


void Main(){
    ll A, B;
    cin >> A >> B;
    ll ans = -1;
    for(ll c=1;c<=10000;c++){
        // cout << ll(c * 0.08) << "," <<c * 0.1 <<endl;
        ll maybe_a = c * 8 / 100;
        if(maybe_a == A && c / 10 == B){
            ans = c;
            break;
        }
    }
    cout << ans <<endl;


}

int main(){
    Main();
}