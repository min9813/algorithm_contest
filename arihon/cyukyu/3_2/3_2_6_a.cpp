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
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;

static const ll max_n = 1010;
vector<ll> ps(max_n, 0);
vector<ll> ps_comb(max_n*max_n, 0);
// set<ll> ps;
// set<ll> ps_comb;
// static const ll max_col = 10000;
ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, M, p;
    sll(N);
    sll(M);
    rep(i, N){
        sll(p);
        // ps.insert(-p);
        ps[i] = -p;
    }
    // ps.insert(0);
    ps[N] = 0;
    sort(ps.begin(), ps.begin()+N+1);

    rep(i, N+1){
        rep(j,N+1){
            ps_comb[i*(N+1)+j] = ps[i] + ps[j];
        }
    }

    sort(ps_comb.begin(), ps_comb.begin()+(N+1)*(N+1));

    ll score = 0;
    // for(auto p:ps_comb){
    rep(i, (N+1)*(N+1)){
        // printf("p=%lld, M=%lld\n",p, M);
        ll p = ps_comb[i];
        if(-p>=M){
            continue;
        }else{
            ll left_point = M + p;
            // ll value = -*lower_bound(ps_comb.begin(), ps_comb.end(), -left_point);
            ll value = -*lower_bound(ps_comb.begin(), ps_comb.begin()+(N+1)*(N+1), -left_point);
            score = max(value - p, score);
        }
    }

    
    cout << score << endl;


}

int main(){
    Main();

    return 0;

}