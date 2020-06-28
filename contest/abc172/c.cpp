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
#include <list>
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


void Main(){
    ll N, M, K;
    sll(N);
    sll(M);
    sll(K);
    vector<ll> ns(N,0);
    vector<ll> cumsum_n(N+1,0);
    vector<ll> ms(M,0);
    vector<ll> cumsum_m(M+1,0);

    rep(i, N){
        sll(ns[i]);
        cumsum_n[i+1] = ns[i] + cumsum_n[i];
        cumsum_n[i+1] = min(cumsum_n[i+1], K+1);
    }

    rep(i, M){
        sll(ms[i]);
        cumsum_m[i+1] = ms[i] + cumsum_m[i];
        cumsum_m[i+1] = min(cumsum_m[i+1], K+1);
    }

    // cout << "cumsum m =" << cumsum_m <<endl;
    // cout << "cumsum n =" << cumsum_n <<endl;
    ll ans = 0;
    rep(i, N+1){
        ll left_k = K - cumsum_n[i];
        if(left_k<0){
            break;
        }
        auto max_mit = lower_bound(cumsum_m.begin(), cumsum_m.end(), left_k);
        ll max_m = *max_mit;
        ll this_m = max_mit - cumsum_m.begin() - 1;
        if(max_m==left_k){
            this_m ++;
        }
        // cout << "i=" <<i<<", this_m=" << this_m<<", left_k=" << left_k <<" maxm=" << max_m  << endl;;
        if(this_m+i > ans){
            ans = this_m + i;
        }
    }

    cout << ans <<endl;
}

int main(){
    Main();
}