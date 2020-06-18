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
    ll X, N;
    sll(X);
    sll(N);
    set<ll> ps;
    rep(i, N){
        ll a;
        sll(a);
        ps.insert(a);
    }

    bool not_found = true;
    ll diff = 0;
    ll ans;
    while(not_found){
        ans = X - diff;
        if(ps.find(ans)==ps.end()){
            break;
        }
        ans = X + diff;
        if(ps.find(ans)==ps.end()){
            break;
        }
        diff += 1;
    }

    cout << ans <<endl;

}

int main(){
    Main();
}