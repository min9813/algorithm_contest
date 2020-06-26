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


void Main(){
    ll N, Q;
    ll a, b, c;
    sll(N);
    vector<ll> as(N, 0);
    // vector<ll> bs(N, 0);
    // vector<ll> cs(N, 0);

    map<ll, ll> counter;
    ll sum = 0;
    rep(i, N){
        sll(as[i]);
        ++ counter[as[i]];
        sum += as[i];
    }
    sll(Q);
    rep(i, Q){
        sll(b);
        sll(c);
        ll inc_num = (c- b) * counter[b];
        sum += inc_num;
        printf("%lld\n", sum);
        counter[c] += counter[b];
        counter[b] = 0;
    }
    


}

int main(){
    Main();
}