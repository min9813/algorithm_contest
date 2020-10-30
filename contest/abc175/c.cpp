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
    ll X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    ll num_0 = X / D;
    if(num_0>K){
        cout << X - K * D <<endl;
    }else{
        ll left_k = K - num_0;
        if(left_k%2){
            cout << abs((X % D) - D) <<endl;
        }else{
            cout << X % D <<endl;
        }
    }
}

int main(){
    Main();
}