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
static const int max_n = 200010;
static const llong max_cost = 2000000000000000;
// vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
// vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
vector<vector<pair<llong, int>>> adj_list(max_n);
vector<llong> distance_table(max_n, max_cost);
vector<pair<llong, int>> points_sort_x;
vector<pair<llong, int>> points_sort_y;
// vector<pair<llong, int>> points_sort_y;

int N;


llong prim(int st){
    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> PQ;
    llong total_weight = 0;
    vector<bool>used(N, false);
    PQ.push(make_pair(0, st));

    
    while(!PQ.empty()){
        auto u = PQ.top(); PQ.pop();
        // cout << u << endl;
        if(u.first>distance_table[u.second]||used[u.second])continue;
        // printf("start push\n");
        total_weight += u.first;
        distance_table[u.second] = u.first;
        used[u.second] = true;

        for(auto &v:adj_list[u.second]){
            if(distance_table[v.second] > v.first && !used[v.second]){
                PQ.push(make_pair(v.first, v.second));
            }
        }

    }

    return total_weight;
}

int main(){
    // int u, v;
    // bool updated = false;
    llong cost, ans, u, v;
    // printf("ok3\n");

    scanf("%d", &N);
    // printf("ok2\n");

    for(int i=0;i<N;i++){
        scanf("%lld %lld", &u, &v);
        points_sort_x.push_back(make_pair(u, i));
        points_sort_y.push_back(make_pair(v, i));
        // points_sort_y.insert(make_pair(v, i));
    }

    sort(points_sort_x.begin(), points_sort_x.end());
    sort(points_sort_y.begin(), points_sort_y.end());

    for(int i=0;i<N-1;i++){
        auto x1 = points_sort_x[i];
        auto x2 = points_sort_x[i+1];
        llong x_length = x2.first - x1.first;
        adj_list[x1.second].push_back(make_pair(x_length, x2.second));
        adj_list[x2.second].push_back(make_pair(x_length, x1.second));
        x1 = points_sort_y[i];
        x2 = points_sort_y[i+1];
        x_length = x2.first - x1.first;
        adj_list[x1.second].push_back(make_pair(x_length, x2.second));
        adj_list[x2.second].push_back(make_pair(x_length, x1.second));
    }


    // printf("ok1\n");

    ans = prim(0);

    printf("%lld\n", ans);


    return 0;

}