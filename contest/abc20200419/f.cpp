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
static const ll max_n = 2010;
// static const ll max_abs_value = 1000000010;
// static const ll mod = 998244353;
// vector<vector<ll>>dp(max_n, vector<ll>(max_n, 0));
vector<vector<ll>>dp(max_n, vector<ll>(max_n, 0));
vector<set<ll>> color_list(max_n);
vector<ll> node_colors(max_n);
vector<vector<ll>> edge_list(max_n);
// vector<ll> value_list(max_n);
// int N;
ll N, S;

void dfs(ll st, ll prev){
    set<ll> this_color_list;
    this_color_list.insert(node_colors[st]);
    ll total_child_node = 1;
    for(ll &node:edge_list[st]){
        if(node == prev) continue;
        dfs(node, st);
        for(auto color:color_list[node]){
            this_color_list.insert(color);
        }
        total_child_node *= (dp[node][N] + 1);
    }
    ll total_path_num = 0;
    for(auto color:this_color_list){
        ll color_num = 0;
        if(color != node_colors[st]){
            for(ll i=0;i<edge_list[st].size();i++){
                ll node = edge_list[st][i];
                if(node == prev) continue;
                color_num += dp[node][color];
                ll this_color_num = dp[node][color];
                ll total_q = 0;
                ll q = 0;
                for(ll j=0;j<edge_list[st].size();j++){
                    ll node2 = edge_list[st][j];
                    if(node2 == prev || i ==j) continue;
                    ll add_num = dp[node2][N];
                    if(j<i){
                        add_num -= dp[node][color];
                    }
                    q = (q + 1) * add_num;
                    total_q += q;
                }
                color_num += this_color_num * total_q;
            }
            dp[st][color] = color_num;
            total_path_num += color_num;
        }else{
            dp[st][color] = total_child_node;
            total_path_num += total_child_node;
        }
    }
    dp[st][N] = total_path_num;
    color_list[st] = this_color_list;
}

int main(){
    // int u, v;
    // bool updated = false;
    ll N, c, u, v;
    scanf("%lld", &N);
    for(ll i=0;i<N;i++){
        scanf("%lld", &c);
        node_colors[i] = c-1;
    }
    printf("start input\n");
    for(ll i=0;i<N-1;i++){
        scanf("%lld %lld", &u, &v);
        u --;
        v --;
        edge_list[u].push_back(v);
        edge_list[v].push_back(u);
    }

    printf("start dfs\n");
    dfs(0, -1);
    printf("end dfs\n");
    for(ll i=0;i<N;i++){
        ll ans = 0;
        for(ll j=0;j<N;j++){
            ans += dp[j][i];
        }
        printf("%lld\n", ans);
    }
    // ans = dp[S];

    // printf("%lld\n", ans);


    return 0;

}