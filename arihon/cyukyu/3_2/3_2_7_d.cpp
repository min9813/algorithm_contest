#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <iomanip>
#include <complex>
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<ii,ii>
typedef long long ll;
typedef double lf;

static const ll INF = 1000000000000000;



void Main(){
    ll N, X, w;
    sll(N);
    sll(X);
    vector<ll> w_list(N);
    unordered_map<ll,ll> counter;
    rep(i, N){
        sll(w);
        w_list[i] = w;
    }

    ll n2 = N / 2;

    for(ll i=0;i<(1<<n2);i++){
        ll wt = 0;
        for(ll j=0;j<n2;j++){
            if((i>>j)&1){
                wt += w_list[j];
            }
        }
        counter[wt] ++;
    }

    // counter[0] ++ ;

    // for(auto p:counter){
    //     printf("%lld:%lld \n", p.first, p.second);
    // }

    ll ans = 0;
    for(ll i=0;i<(1<<(N-n2));i++){
        ll wt = 0;
        for(ll j=0;j<(N-n2);j++){
            if((i>>j)&1){
                wt += w_list[n2+j];
            }
        }

        ll left_w = X - wt;
        // cout << bitset<8>(i) << ": w="<< wt<<" left w = "<<left_w << endl;
        if(left_w >= 0){
            ans += counter[left_w];
        }
    }
    
    printf("%lld\n", ans);

}

int main(){
    Main();

    return 0;

}