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
    ll N, K;
    sll(N);
    sll(K);
    vector<ll> ps(N);
    vector<ll> exp_double(N);
    vector<ll> exp_acm(N+1, 0);
    rep(i, N){
        sll(ps[i]);
        exp_double[i] = ps[i] + 1;
        exp_acm[i+1] = exp_acm[i] + exp_double[i];
    }

    ll max_e = 0;
    ll max_i = -1;
    for(ll i=K-1;i<N;i++){
        ll this_exp = exp_acm[i+1] - exp_acm[i+1-K];
        if(this_exp > max_e){
            max_i = i;
            max_e = this_exp;
        }
    }

    double ans = (double)max_e * 0.5;

    cout << fixed << setprecision(10) << ans << endl;


}

int main(){
    Main();
}