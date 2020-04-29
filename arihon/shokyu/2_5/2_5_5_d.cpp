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
static const int max_n = 210;
// static const int max_e = 2010;
static const llong max_cost = 2000000000000000;
static const string negative_cicle = "NEGATIVE CIRCLE";
// vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
vector<vector<llong>> adj_matrix(10, vector<llong>(10, max_cost));
struct Edge{
    int from;
    int to;
    llong cost;
};
// vector<vector<pair<llong, int>>> adj_list(max_n);
// vector<vector<llong>> distance_table(max_n, vector<llong>(max_n, max_cost));
vector<vector<int>> wall(max_n, vector<int>(max_n));
// vector<Edge> edge_list(max_e);
// vector<pair<llong, int>> points_sort_y;

int H, W;


void warshall_floyd(){
    for(int i=0;i<10;i++){
        // distance_table[i][i] = 0;
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
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
    scanf("%d %d", &H, &W);
    // vector<llong> ans(N);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf("%lld ", &cost);
            adj_matrix[i][j] = cost;
        }
    }
    warshall_floyd();

    llong ans = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf("%d", &u);
            if(u==-1) continue;
            ans += adj_matrix[u][1];
        }
    }


    // for(int i=0;i<N;i++){
    //     printf("i = %d [", i);
    //     for(int j=0;j<N;j++){
    //         printf("%lld ,", adj_matrix[i][j]);
    //     }
    //     printf("] \n");

    // }

    printf("%lld\n", ans);

    return 0;

}