#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
// #include <prettyprint.hpp>
using namespace std;
typedef long long llong;
static const int max_n = 310;
// static const int max_e = 2010;
static const llong max_cost = 2000000000000000;
static const string negative_cicle = "NEGATIVE CIRCLE";
// vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
// vector<vector<llong>> adj_matrix_town(8, vector<llong>(8, max_cost));
struct Edge{
    int from;
    int to;
    llong cost;
};
// vector<vector<pair<llong, int>>> adj_list(max_n);
// vector<vector<llong>> distance_table(max_n, vector<llong>(max_n, max_cost));
// vector<Edge> edge_list(max_e);
// vector<pair<llong, int>> points_sort_y;

int N, M, R;


void warshall_floyd(vector<vector<llong>> &adj_matrix, int N){
    for(int i=0;i<N;i++){
        // distance_table[i][i] = 0;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                adj_matrix[j][k] = min(adj_matrix[j][k], adj_matrix[j][i]+adj_matrix[i][k]);
            }
        }
    }
}

llong prim(vector<vector<llong>> &adj_matrix, int st, int matrix_size){
    vector<llong> distance_table(matrix_size, max_cost);
    vector<bool> used(matrix_size, false);
    llong min_value, total_weight = 0;

    distance_table[st] = 0;

    while(true){
        int u = -1;
        min_value = max_cost;
        for(int i=0;i<matrix_size;i++){
            if(!used[i] && min_value > distance_table[i]){
                min_value = distance_table[i];
                u = i;
            }
        }
        if(u == -1){
            break;
        }
        used[u] = true;
        total_weight += min_value;
        for(int i=0;i<matrix_size; i++){
            if(!used[i]){
                distance_table[i] = min(distance_table[i], adj_matrix[u][i]);
            }
        }

    }

    return total_weight;
}

llong dfs(vector<vector<llong>> &adj_matrix, int depth, int next, vector<int> visited){

    int size = int(adj_matrix[next].size());
    if(depth==size-1){
        // printf("out\n");
        return 0;
    }
    // printf("--- depth == %d  size = %d ---\n", depth, size);
    // cout << "visited:" << visited << "\n";
    llong now_value = max_cost;
    for(int i=0;i<size;i++){
        bool find = false;
        for(auto &p:visited){
            if(p == i){
                find = true;
                break;
            }
        }
        if(find){
            continue;
        }
        visited.push_back(i);
        // printf("adj matrix[%d][%d]=%lld\n", next, i, adj_matrix[next][i]);
        now_value = min(now_value, adj_matrix[next][i] + dfs(adj_matrix, depth+1, i, visited));
        visited.pop_back();
    }

    return now_value;
}

int main(){
    int u, v;
    // bool updated = false;
    llong cost;
    // printf("ok3\n");

    // S = 0;
    scanf("%d %d %d", &N, &M, &R);
    vector<llong> visit_towns(R);
    vector<vector<llong>> adj_matrix_town(R, vector<llong>(R, max_cost));

    // vector<llong> ans(N);
    for(int i=0;i<R;i++){
        scanf("%d ", &u);
        visit_towns[i] = u - 1;
    }
    for(int i=0;i<M;i++){
        scanf("%d %d %lld", &u, &v, &cost);
        adj_matrix[u-1][v-1] = cost;
        adj_matrix[v-1][u-1] = cost;
    }

    for(int i=0;i<N;i++){
        adj_matrix[i][i] = 0;
    }

    warshall_floyd(adj_matrix, N);

    // for(int i=0;i<N;i++){
    //     printf("i = %d [", i);
    //     for(int j=0;j<N;j++){
    //         printf("%lld", adj_matrix[i][j]);
    //     }
    //     printf("]\n");
    // }

    for(int i=0;i<R;i++){
        for(int j=0;j<R;j++){
            adj_matrix_town[i][j] = adj_matrix[visit_towns[i]][visit_towns[j]];
            adj_matrix_town[j][i] = adj_matrix[visit_towns[j]][visit_towns[i]];
        }
    }
    // for(int i=0;i<R;i++){
    //     // printf("i = %d [", i);
    //     // // for(int j=0;j<R;j++){
    //     // //     printf("%lld", adj_matrix_town[i][j]);
    //     // // }
    //     // printf("]\n");
    //     cout << "i = " <<i <<" " << adj_matrix_town[i] << "\n";
    // }
    // exit(0);
    llong ans = max_cost;
    for(int i=0;i<(int)adj_matrix_town.size();i++){
        vector<int> visited = {i};
        ans = min(ans, dfs(adj_matrix_town, 0, i, visited));
    }

    printf("%lld\n", ans);
    


    return 0;

}