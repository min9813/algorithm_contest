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
static const int max_n = 1010;
static const int max_e = 2010;
static const llong max_cost = 2000000000000000;
static const string negative_cicle = "inf";
// vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
// vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
struct Edge{
    int from;
    int to;
    llong cost;
};
// vector<vector<pair<llong, int>>> adj_list(max_n);
vector<llong> distance_table(max_n, max_cost);
vector<bool> negative_table(max_n, false);
vector<Edge> edge_list(max_e);
// vector<pair<llong, int>> points_sort_y;

int V, E, S;


void bellman_ford(int st){

    bool updated = true;
    // bool has_negative = false;
    llong update_num = 0;
    distance_table[st] = 0;

    for(int k=0;k<V;k++){
        updated = false;
        // printf("update %lld times\n", update_num);
        for(int i=0;i<E;i++){
            Edge edge = edge_list[i];
            if(distance_table[edge.from]!=max_cost && distance_table[edge.to]>distance_table[edge.from]+edge.cost){
                distance_table[edge.to] = distance_table[edge.from]+edge.cost;
                updated = true;
            }
        }
        if(!updated){
            break;
        }
    }
    // return has_negative;

}

void bellman_ford_negative_loop(int st){

    bool updated = true;
    // bool has_negative = false;
    llong update_num = 0;
    // distance_table[st] = 0;

    for(int k=0;k<V;k++){
        updated = false;
        // printf("update %lld times\n", update_num);
        for(int i=0;i<E;i++){
            Edge edge = edge_list[i];
            if(distance_table[edge.from]==max_cost){
                continue;
            }
            if(distance_table[edge.to]>distance_table[edge.from]+edge.cost){
                distance_table[edge.to] = distance_table[edge.from]+edge.cost;
                negative_table[edge.to] = true;
                updated = true;
            }
            if(negative_table[edge.from]){
                negative_table[edge.to] = true;
            }

        }
        if(!updated){
            break;
        }
    }
    // return has_negative;

}

int main(){
    int u, v;
    // bool updated = false;
    llong cost;
    bool has_negative = false;
    // printf("ok3\n");

    S = 0;
    scanf("%d %d", &V, &E);
    // printf("ok2\n");

    for(int i=0;i<E;i++){
        scanf("%d %d %lld", &u, &v, &cost);
        Edge edge = {u-1, v-1, -cost};
        edge_list[i] = edge;
        // points_sort_y.insert(make_pair(v, i));
    }


    // printf("ok1\n");

    // has_negative = bellman_ford(S);
    bellman_ford(S);
    llong ans = distance_table[V-1];
    bellman_ford_negative_loop(S);
    // fill(distance_table.begin(), distance_table.begin()+V);
    if(negative_table[V-1]){
        cout << negative_cicle << "\n";
    }else{
        printf("%lld\n",-ans);

    }



    return 0;

}