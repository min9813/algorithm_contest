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
    ll N, D, A, x, h;
    cin >> N >> D >> A;
    vector<ll> xs(N);
    map<ll,ll> xhs;
    rep(i, N){
        sll(x);
        sll(h);
        xs[i] = x;
        xhs[x] = h;
    }

    sort(xs.begin(), xs.end());
    vector<ll> imos(N);

    ll now_num = 0, left_h, this_n;
    ll ans = 0;
    rep(i, N){
        x = xs[i];
        now_num += imos[i];
        h = xhs[x];
        left_h = (h - 1) / A + 1;
        this_n = left_h / A;
        imos[i] = this_n;
        ans += this_n;
    }
    cout << ans <<endl;
}

int main(){
    Main();
}