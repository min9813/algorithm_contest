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

vector<ll> H(max_n);
vector<ll> S(max_n);
vector<pair<ll, ll>> times_vec(max_n);
ll N;


bool is_ok(ll V){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    rep(i,N){
        ll val = V - H[i];
        if(val < 0){
            return false;
        }
        ll times = val / S[i] + 1;
        // if (val % S[i] != 0){
            // times ++;
        // }
        times_vec[i] = make_pair(times, i);
        // printf("time[%lld]=%lld\n", i, times_vec[i].first);
    }

    sort(times_vec.begin(), times_vec.begin()+N);
    rep(i,N){
        if(i>=times_vec[i].first){
            return false;
        }
    }

    return true;
}

int main(){
    // int u, v;
    // bool updated = alse;
    ll u;
    scanf("%lld", &N);
    rep(i, N){
        sll(u)
        H[i] = u;
        sll(u)
        S[i] = u;
    }
    // rep(i,N) printf("H[%lld]=%lld\n", i, H[i]);
    // printf("----------\n");
    // rep(i,N) printf("S[%lld]=%lld\n", i, S[i]);

    ll L = 0;
    ll R = max_value;
    while(R-L>1){
        ll mid = (R+L)/2;
        if(is_ok(mid)){
            R = mid;
        }else{
            L = mid;
        }
    }
    printf("%lld\n", R);

    return 0;

}