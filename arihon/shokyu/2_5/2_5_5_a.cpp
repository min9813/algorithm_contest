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
struct Edge{
    int from;
    int to;
    llong cost;
};
// vector<vector<pair<llong, int>>> adj_list(max_n);
vector<vector<llong>> distance_table(max_n, vector<llong>(max_n, max_cost));
// vector<Edge> edge_list(max_e);
// vector<pair<llong, int>> points_sort_y;

int N, M;


void warshall_floyd(){
    for(int i=0;i<N;i++){
        // distance_table[i][i] = 0;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                adj_matrix[j][k] = min(adj_matrix[j][k], adj_matrix[j][i]+adj_matrix[i][k]);
            }
        }
    }
}

int main(){
    int u, v;
    // bool updated = false;
    llong cost;
    // printf("ok3\n");

    // S = 0;
    scanf("%d %d", &N, &M);
    // vector<llong> ans(N);
    for(int i=0;i<M;i++){
        scanf("%d %d %lld", &u, &v, &cost);
        adj_matrix[u-1][v-1] = cost;
        adj_matrix[v-1][u-1] = cost;
    }

    for(int i=0;i<N;i++){
        adj_matrix[i][i] = 0;
    }

    warshall_floyd();

    // for(int i=0;i<N;i++){
    //     printf("i = %d [", i);
    //     for(int j=0;j<N;j++){
    //         printf("%lld ,", adj_matrix[i][j]);
    //     }
    //     printf("] \n");

    // }

    llong min_time = max_cost;
    for(int i=0;i<N;i++){
        llong max_time = 0;
        for(int j=0;j<N;j++){
            // if(j==i) continue;
            max_time = max(max_time, adj_matrix[i][j]);
        }
        min_time = min(min_time, max_time);
    }

    printf("%lld\n", min_time);

    return 0;

}