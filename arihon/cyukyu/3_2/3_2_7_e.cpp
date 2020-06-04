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
static const ll max_subset_num = (1<<20)+10;

vector<bool> dp_v1(max_subset_num, true);
vector<bool> dp_v2(max_subset_num, true);
vector<ll> dp_v12(max_subset_num, 0);
vector<ll> dp_v2_cover(max_subset_num, 0);


void Main(){
    ll N, M, a, b;
    sll(N);
    sll(M);
    // vector<vector<ll>> edge_list(N);
    set<pll> edges;

    rep(i, M){
        sll(a);
        sll(b);
        -- a;
        -- b;
        // ll bit = (1 << a) | (1 << b);
        // edge_list[a].push_back(b);
        // edge_list[b].push_back(a);
        edges.insert(make_pair(a,b));
    }

    ll n2 = N / 2;
    ll left_n = N - n2;

    rep(i, n2){
        rep(j, n2){
            if(i==j) continue;
            if(edges.find(make_pair(i,j))!=edges.end()){
                dp_v1[(1<<i)|(1<<j)] = false;
            }
        }
    }

    for(ll i=0;i<(1<<n2);i++){
        // ちゃんと小さい順に埋められていく
        if(dp_v1[i]) continue;
        for(ll j=0;j<n2;j++){
            dp_v1[i|(1<<j)] = false;
        }
    }

    // printf("")

    dp_v12[0] = (1<<left_n) - 1;
    // printf("dp_v12[0]=%lld\n", dp_v12[0]);
    rep(i,n2){
        for(ll j=n2;j<N;j++){
            // ll bit = i | j;
            pll p = make_pair(i, j);
            if(edges.find(p) == edges.end()){
                dp_v12[(1<<i)] |= 1 << (j-n2);
            }
        }
    }

    for(ll i=0;i<(1<<n2);i++){
        // cout << "find v12, i = " << bitset<20>(i) <<endl;
        // ちゃんと小さい順に埋められていく
        // if(dp_v1[i]) continue;
        for(ll j=0;j<n2;j++){
            ll bit_j = 1 << j;
            dp_v12[i|bit_j] = dp_v12[i] & dp_v12[bit_j];
        }
    }

    rep(i, left_n){
        rep(j, left_n){
            if(i==j) continue;
            // ll bit = (1<<i) | (1 << j);
            ll idx_i = i + n2;
            ll idx_j = j + n2;
            pll p = make_pair(idx_i, idx_j);
            if(edges.find(p) != edges.end()){
                dp_v2[(1<<i) | (1<<j)] = false;
            }
        }
    }
    // printf("dp_v2[0]=%lld\n", (ll)dp_v2[0]);
    for(ll i=0;i<(1<<left_n);i++){
        // ちゃんと小さい順に埋められていく
        if(dp_v2[i]) continue;
        for(ll j=0;j<left_n;j++){
            dp_v2[i|(1<<j)] = false;
        }
    }

    for(ll i=0;i<(1<<left_n);i++){
        if(dp_v2[i]){
            ll num = 0;
            for(ll j=0;j<left_n;j++){
                num += (ll)(bool)((i>>j) & 1);
            }
            dp_v2_cover[i] = num;
        }
    }

    for(ll i=0;i<(1<<left_n);i++){
        for(ll j=0;j<left_n;j++){
            dp_v2_cover[i|(1<<j)] = max(dp_v2_cover[i|(1<<j)], dp_v2_cover[i]);
        }
    }

    ll ans = 0;
    for(ll i=0;i<(1<<n2);i++){
        if(dp_v1[i]){
            // cout << "find final, i="<<bitset<20>(i) <<endl;
            ll num = 0;
            for(ll j=0;j<n2;j++){
                num += (ll)(bool)((i>>j) & 1);
            }
            ll v2_size = dp_v2_cover[dp_v12[i]];
            // printf("num=%lld, v2size=%lld\n", num, v2_size);
            ans = max(ans, num+v2_size);
        }
    }
    
    printf("%lld\n", ans);

}

int main(){
    Main();

    return 0;

}