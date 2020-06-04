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
static const ll max_n = 200010;
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
    rep(i,N){
        sll(a);
        A[i] = a;
    }

    // ll now_xor = A[0];
    ll now_sum = 0;
    ll r = 0;
    ll num = 0;
    for(ll l=0;l<N;l++){
        while(r<N && (now_sum+A[r])==(now_sum ^ A[r])){
            now_sum += A[r];
            r++;
        }
        num += (r - l);
        if(l==r) r++;
        else now_sum -= A[l];
    }
    printf("%lld\n", num);

}

int main(){
    Main();

    return 0;

}