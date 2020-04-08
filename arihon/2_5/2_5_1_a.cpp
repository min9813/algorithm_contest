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
typedef long long llong;
static const int max_n = 100010;
using namespace std;
// vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
vector<vector<pair<llong, llong>>> adj_list(max_n);
vector<llong> tree_dist(max_n, 0);
llong N;

void dfs(llong u, llong prev, llong d){
    // printf("input %lld\n", u);
    tree_dist[u] = d;
    // if((int)adj_list[u].size()==1){
    //     return;
    // }
    for(int i=0;i<(int)adj_list[u].size();i++){
        auto adj_node = adj_list[u][i];
        // printf("adj node = %lld, dist = %lld", adj_node.first, adj_node.second);
        if(adj_node.first != prev){
            llong dist = adj_node.second + d;
            dfs(adj_node.first, u, dist);
        }
    }
}

int main(){
    llong u, v, w;
    scanf("%lld", &N);
    for(int i=0;i<N-1;i++){
        scanf("%lld %lld %lld", &u, &v, &w);
        adj_list[u-1].push_back(make_pair(v-1, w));
        adj_list[v-1].push_back(make_pair(u-1, w));
    }

    dfs(0, -1, 0);

    for(int i=0;i<N;i++){
        // printf("tree dist i = %lld\n", tree_dist[i]);
        printf("%lld\n", tree_dist[i] % 2);
    }


}