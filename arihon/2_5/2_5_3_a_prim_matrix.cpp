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
static const int max_n = 100010;
// static const int max_e = 2010;
static const llong max_cost = 2000000000000000;
static const string negative_cicle = "NEGATIVE CIRCLE";
// vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));

int N, E;

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


int main(){
    int u, v;
    bool updated = false;
    llong cost, ans;
    scanf("%d %d", &N, &E);

    for(int i=0;i<E;i++){
        scanf("%d %d %lld", &u, &v, &cost);
        adj_matrix[u][v] = cost;
        adj_matrix[v][u] = cost;
    }

    printf("ok1\n");
    ans = prim(adj_matrix, 0, N);

    printf("%lld\n", ans);


    return 0;

}