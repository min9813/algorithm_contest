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
vector<ll> A(max_n);
// vector<ll> cards(max_n);
// vector<ll> S(max_n);
// vector<pair<ll, ll>> times_vec(max_n);
// ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, a;
    sll(N);
    // sll(K);
    // bool has_zero = false;
    rep(i,N){
        sll(a);
        A[i] = a;
        // has_zero = (a == 0) || has_zero;
    }
    ll num = 0;;
    ll temp = 0;
    // ll now_prod = 1;
    ll j = 0;
    for(ll i=1;i<N;i++){
        // printf("i=%lld, j=%lld, A[%lld]=%lld, num=%lld\n", i, j, i, A[i], num);
        if(A[i]>A[i-1]){
            num += (i-j);
        }else{
            j = i;
        }
    }
    // length = max(length, temp);
    printf("%lld\n", num+N);

}

int main(){
    Main();

    return 0;

}