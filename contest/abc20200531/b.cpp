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
static const ll max_value2 = 1000000000000000000;
// vector<vector<vector<ll>>> dp(max_n, vector<vector<ll>>(max_n, vector<ll>(max_n*max_n, 0)));



void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, a, ans = 1;
    sll(N);
    bool is_ok = true;
    bool has_zero = false;
    rep(i, N){
        sll(a);
        ll res = max_value2 % a;
        ll baisu = max_value2 - res;
        if(a == 0 || ans == 0){
            ans = 0;
            has_zero = true;
            is_ok = true;
        }else{
            if(max_value2 / a < ans){
                is_ok = false;
            }else if(is_ok){
                ans *= a;
            }
        }

    }

    if(is_ok){
        cout << ans <<endl;
    }else{
        cout << "-1" <<endl;
    }




    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}