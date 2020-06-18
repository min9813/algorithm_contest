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
    ll X, Y;
    sll(X);
    sll(Y);

    bool is_ok = false;
    for(ll i=0;i<=X;i++){
        ll j = X - i;
        is_ok = is_ok || (i*2 + j*4 == Y);
    }

    if(is_ok){
        cout << "Yes" <<endl;
    }else{
        cout << "No" <<endl;

    }

    


}

int main(){
    Main();
}