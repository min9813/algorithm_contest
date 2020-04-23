#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
struct edge{
    ll to;
    ll w;
};
static const ll max_n = 200010;
static const ll max_abs_value = 1000000010;
static const ll mod = 1000000007;
vector<ll>dp(max_n);
vector<vector<ll>>adj_list(max_n);
vector<ll> all_answer(max_n);
vector<ll> mod_inv(max_n);
vector<ll> mod_factorial_inv(max_n);
vector<ll> mod_factorial_power(max_n);
vector<ll> sub_tree_size(max_n);
// int N;
ll N;

ll mod_pow(ll base, ll power){
    if(power==0) return 1;
    ll u = mod_pow(base, power/2);
    u = (u * u) % mod;
    if(power % 2) u = (u * base) % mod;
    return u;
}

void init_mod_inv(ll N){
    for(ll i=N;i>=0;i--){
        mod_inv[i] = mod_pow(i, mod-2);
    }    
}

void init_mod_factorial(ll N){
    ll temp = 1;
    for(ll i=1;i<=N;i++){
        temp = (temp * mod_inv[i]) % mod;
        mod_factorial_inv[i] = temp;
    }
    mod_factorial_inv[0] = 1;
}

void init_mod_power(ll N){
    mod_factorial_power[0] = 1;
    mod_factorial_power[1] = 1;
    for(ll i=2;i<=N;i++){
        mod_factorial_power[i] = (mod_factorial_power[i-1] * i) % mod;
    }
}

void init_all(){
    // init_mod_inv(N);
    // init_mod_factorial(N);
    init_mod_power(N);
}

void dfs1(ll st, ll parent){
    // ll this_permute = 1;
    // ll num_child = 0;
    sub_tree_size[st] = 1;
    for(auto next:adj_list[st]){
        if(next == parent) continue;
        dfs1(next, st);
        // this_permute *= permute_num[next];
        // this_permute = this_permute % mod;
        sub_tree_size[st] += sub_tree_size[next];
        // this_permute = (this_permute * mod_factorial_inv[sub_tree_size[next]]) % mod ;
        // num_child ++;
    }

    dp[0] = (dp[0] * mod_pow(sub_tree_size[st], mod-2)) % mod;
}

void dfs2(ll st, ll parent){
    for(ll child: adj_list[st]){
        if(child == parent) continue;
        dp[child] = (dp[st] * sub_tree_size[child]) % mod;
        dp[child] = (dp[child] * mod_pow(N-sub_tree_size[child], mod-2)) % mod;
        dfs2(child, st);
    }

}

int main(){
    // int u, v;
    // bool updated = false;
    ll ans = 0, u, v;
    scanf("%lld", &N);
    init_all();
    // printf("input\n");

    for(ll i=0;i<N-1;i++){
        scanf("%lld %lld", &u, &v);
        u --;
        v --;
        adj_list[u].emplace_back(v);
        adj_list[v].emplace_back(u);
    }

    // printf("dfs1 start\n");
    dp[0] = mod_factorial_power[N];
    dfs1(0, -1);
    // printf("dfs2 end\n");
    // for(ll i=0;i<N;i++){
    //     printf("permute [%lld]=%lld\n", i, permute_num[i]);
    // }

    dfs2(0, -1);
    for(ll i=0;i<N;i++){
        printf("%lld\n", dp[i]);
    }

    return 0;

}