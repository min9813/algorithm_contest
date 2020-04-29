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
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,n) for(ll i=n-1;i>=0;i--)
#define sll(n) scanf("%lld", &n);
typedef long long ll;
static const ll max_n = 100010;
static const ll mod = 2019;
static const ll max_value = 100000000000100;
// static const ll max_x = max_value * max_value;

vector<ll> mans(max_n);
// vector<ll> S(max_n);
// vector<pair<ll, ll>> times_vec(max_n);
ll N, M, X;

bool is_ok(ll V){
    ll max_now = 0;
    // printf("------ V = %lld ----\n", V);
    rep(i,M){
        // printf("max now = %lld\n", max_now);
        ll past_diff = max(mans[i]-max_now-1, (ll)0);
        // printf("max now = %lld, past diff=%lld, now man[%lld]=%lld\n", max_now, past_diff, i, mans[i]);
        if (V< past_diff){
            return false;
        }
        max_now = max(V-past_diff*2, (V-past_diff)/2) + mans[i];
    }
    return max_now >= N;
}


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    sll(N);
    sll(M);
    rep(i, M){
        sll(X)
        mans[i] = X;
    }

    ll L = -1;
    ll R = 2*N;
    while(R-L>1){
        ll mid = (R+L)/2;
        if(is_ok(mid)){
            R = mid;
        }else{
            L = mid;
        }
    }
    printf("%lld\n", R);

}

int main(){
    Main();

    return 0;

}