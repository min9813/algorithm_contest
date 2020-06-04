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
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 100010;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;

ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll K, A, B;
    sll(K);
    sll(A);
    sll(B);
    bool is_ok = false;
    for(ll i=A;i<=B;i++){
        if(i % K ==0){
            is_ok = true;
            break;
        }
    }

    if (is_ok){
        printf("OK\n");
    }else{
        printf("NG\n");
    }


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}