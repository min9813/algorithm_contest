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
#include <assert.h>
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

static const ll max_n = 50010;
static const ll max_v = 1e15;
vector<ll> ns[max_n];

void Main(){
    ll n, a;
    ll num_d;
    rep(i, max_n){
        cin >> n;
        if(n == 0){
            num_d = i;
            break;
        }
        vector<ll> as(n);
        rep(j, n){
            cin >> a;
            as[j] = a;
        }
        sort(as.begin(), as.end());
        ns[i] = as;
    }

    rep(i, num_d){
        n = ns[i].size();
        auto as = ns[i];
        ll ans = max_v;
        rep(j, n-1){
            ans = min(ans, as[j+1] - as[j]);
        }
        cout << ans <<endl;
    }


}

int main(){
    Main();
}