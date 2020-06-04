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
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;

ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N;
    ll x, a;
    sll(N);
    vector<ll> A(N);
    sll(x);
    rep(i,N){
        sll(a);
        A[i] = a;
    }

    ll num = 0;
    if(A[0]>x){
        num += A[0] - x;
        A[0] = x;
    }
    for(ll i=1;i<N;i++){
        if(A[i]+A[i-1] > x){
            ll new_n = A[i-1] + A[i] - x;
            A[i] -= new_n;
            num += new_n;
        }
    }

    printf("%lld\n", num);


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}