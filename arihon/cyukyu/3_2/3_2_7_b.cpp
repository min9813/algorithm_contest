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

static const ll INF = 1000000000000000;
static const ll max_n = 203;
static const ll cond_w = 1005;
static const ll cond_v = 1005;
static const ll cond_n = 32;

vector<ll> w_list(max_n, 0);
vector<ll> v_list(max_n, 0);


void Main(){
    ll N, W, v, w;
    sll(N);
    sll(W);
    ll max_w = 0;
    ll max_v = 0;
    rep(i, N){
        sll(v);
        sll(w);
        w_list[i] = w;
        v_list[i] = v;
        max_w = max(max_w, w);
        max_v = max(max_v, v);
    }

    ll ans = 0;
    if(max_w < cond_w){
        // printf("w\n");

        ll w_size = max_w*N+1;
        vector<vector<ll>> dp(N+1, vector<ll>(w_size, 0));
        for(ll i=1;i<=N;i++){
            ll prev = (i-1) % 2;
            ll now = i % 2;
            for(ll j=0;j<w_size;j++){
                ll m1 = 0;
                if(j-w_list[i-1]>=0){
                    m1 = dp[prev][j-w_list[i-1]] + v_list[i-1];
                }
                ll m2 = dp[prev][j];
                dp[now][j] = max(m1, m2);
            }
        }
        rep(i, W+1){
            ans = max(ans, dp[N%2][i]);
        }
    }else if(max_v < cond_v){
        // printf("v\n");

        ll v_size = max_v * N + 1;
        vector<vector<ll>> dp(2, vector<ll>(v_size, INF));
        dp[0][0] = 0;
        for(ll i=1;i<=N;i++){
            ll prev = (i-1) % 2;
            ll now = i % 2;
            for(ll j=0;j<v_size;j++){
                // printf("before dp[%lld][%lld]=%lld\n", i, j, dp[now][j]);
                ll m1 = INF;
                if(j-v_list[i-1]>=0){
                    m1 = dp[prev][j-v_list[i-1]] + w_list[i-1];
                }
                ll m2 = dp[prev][j];
                dp[now][j] = min(m1, m2);
            }
        }

        rep(i, v_size){
            // printf("dp[N2][%lld]=%lld \n", i, dp[N%2][i]);
            if(dp[N%2][i] <= W){
                // printf(" ok \n");
                ans = i;
            }
        }   

    }else{
        // printf("N\n");
        ll n2 = N / 2;
        ll n2_all = 1 << n2;
        vector<pll> ps_comb(n2_all);
        for(ll i=0;i<n2_all;i++){
            ll wt = 0, vt = 0;
            for(ll j=0;j<n2;j++){
                if((i>>j) & 1){
                    wt += w_list[j];
                    vt += v_list[j];
                }
            }
            ps_comb[i] = make_pair(wt, vt);
        }

        sort(ps_comb.begin(), ps_comb.end());
        ll m = 1;
        rep(i, n2_all){
            if(ps_comb[m-1].second < ps_comb[i].second){
                ps_comb[m++] = ps_comb[i];
            }
        }

        for(ll i=0;i<(1 << (N-n2));i++){
            ll wt = 0, vt = 0;
            for(ll j=0;j<N-n2;j++){
                if((i>>j) & 1){
                    wt += w_list[n2+j];
                    vt += v_list[n2+j];
                }
            }

            if(wt <= W){
                ll v = (lower_bound(ps_comb.begin(), ps_comb.end(), make_pair(W-wt, INF))-1) -> second;
                ans = max(ans, v + vt);
            }
        }
    }


    cout << ans << endl;

}

int main(){
    Main();

    return 0;

}