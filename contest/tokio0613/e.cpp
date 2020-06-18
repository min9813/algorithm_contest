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
#include <complex>
#include <random>
#include <bitset>
// #include <prettyprint.hpp>
using namespace std;
#define repi(i,n) for(int i=0;i<n;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repinvi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
typedef long long ll;
typedef double lf;
typedef short int si;

static const ll max_n = 51;
vector<ll> as(max_n,0);

void Main(){
    map<ll,map<ll,ll>> left_p;
    map<ll,map<ll,ll>> left_s;
    map<ll,ll> right;
    ll N, K, S, T, a;
    sll(N);
    sll(K);
    sll(S);
    sll(T);

    rep(i, N){
        sll(a);
        as[i] = a;
    }

    ll n1 = N/2;
    ll n2 = N - n1;
    for(ll i=0;i<(1<<n1);++i){
        ll this_p = (1<<18)-1;
        ll this_s = 0;
        ll num = 0;
        for(ll j=0;j<n1;++j){
            if(i&(1<<j)){
                this_p &= as[i];
                this_s |= as[i];
                ++num;
            }
        }
        if (num > K){
            continue;
        }
        ++left_p[this_p][num];
        ++left_s[this_s][num];
    }

    for(ll i=0;i<(1<<n2);i++){
        ll this_p = (1<<18)-1;
        ll this_s = 0;
        ll num = 0;
        for(ll j=0;j<n1;++j){
            if(i&(1<<j)){
                this_p &= as[i];
                this_s |= as[i];
                ++num;
            }
        }
        if(num>K){
            continue;
        }
        ~this_p

        
    }



}

int main(){
    Main();
}