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
#define pll pair<ll,ll>
#define pii pair<ii,ii>
typedef long long ll;
typedef double lf;

static const ll INF = 1 << 24;
static const ll max_n = 42;
vector<ll> w_list(max_n, 0);
vector<ll> v_list(max_n, 0);
vector<pll> ps(1<<(max_n/2));
// vector<ll> vs(max_n, 0);

void Main(){
    ll N, W, v, w;
    sll(N);
    sll(W);
    // vector<ll> ws;
    // vector<ll> vs;
    rep(i, N){
        sll(v);
        sll(w);
        v_list[i] = v;
        w_list[i] = w;
    }

    ll n2 = N / 2;
    ll half_n = 1 << n2;
    // printf("half n bit = %lld\n", half_n);
    for(ll i=0;i<half_n;i++){
        ll wt = 0, vt = 0;
        // printf("start it i=%lld\n", i);

        for(ll j=0;j<n2;j++){
            // printf("j=%lld ", j);
            if((i>>j)&1){
                vt += v_list[j];
                wt += w_list[j];
            }
        }

        ps[i] = make_pair(wt, vt);
        // printf("end it i=%lld\n", i);
    }
    // printf("sort start !\n");
    sort(ps.begin(), ps.begin()+half_n);
    // printf("sort end !\n");

    ll m = 1;
    rep(i, half_n){
        if(ps[m-1].second < ps[i].second){
            ps[m++] = ps[i];
        }
    }

    ll ans = 0;

    for(ll i=0;i<(1<<(N-n2));i++){
        ll wt = 0, vt = 0;
        for(ll j=0;j<N-n2;j++){
            if(i&(1 << j)){
                wt += w_list[n2+j];
                vt += v_list[n2+j];
            }
        }
        // printf("i=%lld, end bit set\n", i);
        if(wt <= W){
            ll left_w = W - wt;
            ll v = (lower_bound(ps.begin(), ps.begin()+m, make_pair(left_w, INF)) - 1) -> second;
            ans = max(vt+v, ans);
        }
    }

    cout << ans << endl;

}

int main(){
    Main();

    return 0;

}