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
    ll A, B, V, W, T;
    sll(A);
    sll(V);
    sll(B);
    sll(W);
    sll(T);

    if(A==B){
        cout << "YES" <<endl;
    }else if(V<=W){
        cout << "NO"<<endl;
    }else{
        ll diff = abs(A-B);
        ll max_diff = (V - W) * T;
        if(max_diff>= diff){
            cout << "YES" <<endl;
        }else{
            cout << "NO" <<endl;
        }

    }

    


}

int main(){
    Main();
}