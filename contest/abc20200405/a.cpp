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
// static const int max_n = 110;
// static const llong max_cost = 2000000000000000;
// // vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
// // vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
// vector<vector<pair<llong, int>>> adj_list(max_n);
// vector<llong> distance_table(max_n, max_cost);
// set<pair<llong, int>> points_sort_x;
// set<pair<llong, int>> points_sort_y;

// int N;



int main(){
    // int u, v;
    // bool updated = false;
    llong N, M, cost, total_num;
    scanf("%lld %lld", &N, &M);
    vector<llong> goods_list(N);
    for(int i=0;i<N;i++){
        scanf("%lld", &cost);
        // printf("i=%d cost = %lld\n", i, cost);
        goods_list[i] = cost;
        total_num += cost;
    }
    sort(goods_list.begin(), goods_list.end(), greater<llong>());
    // printf("ok3\n");
    llong last_num = goods_list[M-1];
    llong limit = last_num * 4 * M;
    if(limit >= total_num)printf("Yes\n");
    else printf("No\n");
    // double limit = 1. / (double)(4 * M);



    return 0;

}