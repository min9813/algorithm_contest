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
static const ll max_n = 130;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;

ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll X;
    sll(X);
    
    for(ll A=-max_n;A<=max_n;A++){
        ll pow_a = A*A*A*A*A;
        // printf("pow_a:%lld\n", pow_a);
        bool is_find = false;
        for(ll B=-max_n;B<=max_n;B++){
            ll pow_b = B * B * B * B * B;
            if(X == pow_a - pow_b){
                printf("%lld %lld\n", A, B);
                is_find = true;
                break;
            }
        }
        if(is_find){
            break;
        }
    }

    // printf("%lld\n", ans);


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}