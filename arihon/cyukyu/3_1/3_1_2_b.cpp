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
// static const ll max_n = 100010;
// static const ll mod = 2019;
// static const ll max_value = 10000000000;
// static const ll max_x = max_value * max_value;

// vector<ll> H(max_n);
// vector<ll> S(max_n);
// vector<pair<ll, ll>> times_vec(max_n);
ll R, B, x, y;


bool is_ok(ll V){
    ll nr = R - V;
    ll nb = B - V;
    if(nr < 0 || nb < 0) return false;

    return nr / (x - (ll)1) + nb / (y - (ll)1)>=V;
}

int main(){
    // int u, v;
    // bool updated = alse;
    ll u;
    sll(R);
    sll(B);
    sll(x);
    sll(y);
    // rep(i,N) printf("H[%lld]=%lld\n", i, H[i]);
    // printf("----------\n");
    // rep(i,N) printf("S[%lld]=%lld\n", i, S[i]);

    ll l = 0;
    ll r = B+1;
    while(r-l>1){
        ll mid = (r+l)/2;
        if(is_ok(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    // ll mid = (r+l)/2;
    // if(is_ok(mid)){
    //     l = mid;
    // }else{
    //     r = mid;
    // }
    printf("%lld\n", l);

    return 0;

}