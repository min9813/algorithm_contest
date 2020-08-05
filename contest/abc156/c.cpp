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
    ll N, a;
    sll(N);
    vector<ll> xs(N,0);
    rep(i, N){
        sll(a);
        xs[i] = a;
    }

    sort(xs.begin(), xs.end());
    ll ans = 100000000000000;
    rep(i, 101){
        ll dist = 0;
        rep(j, N){
            dist += (i-xs[j]) * (i-xs[j]);
        }
        ans = min(ans, dist);
    }

    cout << ans <<endl;

}

int main(){
    Main();
}