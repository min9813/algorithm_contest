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
    ll N, M, a;
    sll(N);
    sll(M);
    set<ll> all_number;
    // rep(i, N){
    //     all_number.insert(i+1);
    // }
    ll num = 0;
    ll even_i = N, even_j = N-M+1;
    ll odd_i = 1, odd_j = M+1;
    while(num < M){
        num ++;
        if(num % 2 == 1){
            printf("%lld %lld\n", odd_i, odd_j);
            odd_i ++;
            odd_j --;
        }else{
            printf("%lld %lld\n", even_j, even_i);
            even_i --;
            even_j ++;
        }

    }

    // printf("%lld\n", );


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}