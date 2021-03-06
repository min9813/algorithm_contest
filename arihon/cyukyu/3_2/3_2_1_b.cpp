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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,n) for(ll i=n-1;i>=0;i--)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 100010;
static const ll mod = 2019;
static const ll max_value = 100000000000100;
// vector<vector<vector<ll>>> dp(max_n, vector<vector<ll>>(max_n, vector<ll>(max_n*max_n, 0)));
// static const ll max_x = max_value * max_value;
vector<ll> S(max_n);
// vector<ll> cards(max_n);
// vector<ll> S(max_n);
// vector<pair<ll, ll>> times_vec(max_n);
ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, K, a;
    sll(N);
    sll(K);
    bool has_zero = false;
    rep(i,N){
        sll(a);
        S[i] = a;
        has_zero = (a == 0) || has_zero;
    }

    if(has_zero){
        printf("%lld\n", N);
    }else{
        ll length = 0;
        ll temp = 0;
        ll now_prod = 1;
        ll j = 0;
        rep(i,N){
            now_prod *= S[i];
            // printf("now prod=%lld, S[%lld]=%lld, j =%lld\n", now_prod, i, S[i], j);
            if(now_prod > K){
                // printf("max length = %lld, now length = %lld\n", length, i - j);
                length = max(temp, length);
                // temp_length = 0;
                // temp = 0;
                while(now_prod>K && j<=i){
                    now_prod /= S[j];
                    j ++;
                }
                temp = i - j + 1;
            }else{
                temp = i - j + 1;
            }
        }
        length = max(length, temp);
        printf("%lld\n", length);
    }

}

int main(){
    Main();

    return 0;

}