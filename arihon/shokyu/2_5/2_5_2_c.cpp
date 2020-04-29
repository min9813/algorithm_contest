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
static const llong max_cost = 2000000000000000;
using namespace std;
// vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
// vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
vector<vector<pair<llong, int>>> adj_list(max_n);
vector<vector<pair<llong, int>>> inverse_adj_list(max_n);
vector<llong> distance_table_normal(max_n, max_cost);
vector<llong> distance_table_inverse(max_n, max_cost);
vector<llong> get_money(max_n, -1);
int N, M, T;


void dijkstra(int st, int inverse){
    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> PQ;
    // used[st] = true;

    if(inverse==1){
        distance_table_inverse[st] = 0;
        // for(auto &p:inverse_adj_list[st]){
        //     // if(adj_matrix[st][i]<max_cost){
        //     //     distance_table[i] = adj_matrix[st][i];
        //     // }
        //     PQ.push(p);
        // }
    }else{
        distance_table_normal[st] = 0;
        // for(auto &p:adj_list[st]){
        //     // if(adj_matrix[st][i]<max_cost){
        //     //     distance_table[i] = adj_matrix[st][i];
        //     // }
        //     PQ.push(p);
        // }
    }
    PQ.push(make_pair(0, 0));

    // printf(" -------- dijkstra %d start ----------\n", st);
    while(!PQ.empty()){
        auto p = PQ.top(); PQ.pop();
        // printf("point %d cost = %lld\n", p.second, p.first);


        if(inverse==1){
            if(p.first > distance_table_inverse[p.second]) continue;

            distance_table_inverse[p.second] = p.first;
            for(auto &q:inverse_adj_list[p.second]){
                auto cost = q.first + p.first;
                if(cost<distance_table_inverse[q.second]){
                    distance_table_inverse[q.second] = cost;
                    PQ.push(make_pair(cost, q.second));
                }
            }
        }else{
            if(p.first > distance_table_normal[p.second]) continue;

            distance_table_normal[p.second] = p.first;
            for(auto &q:adj_list[p.second]){
                auto cost = q.first + p.first;
                if(cost<distance_table_normal[q.second]){
                    distance_table_normal[q.second] = cost;
                    PQ.push(make_pair(cost, q.second));
                }
            }
        }

    }
    // distance_table_all[st] = distance_table;

}

int main(){
    int u, v;
    bool updated = false;
    llong cost, ans;
    scanf("%d %d %d", &N, &M, &T);
    // distance_table_all.resize(N);
    // get_money.resize(N);
    // adj_list.resize(N);
    // printf("ok1\n");
    for(int i=0;i<N;i++){
        scanf("%lld ", &cost);
        get_money[i] = cost;
        // printf("%d th money = %lld\n", i, get_money[i]);
        // distance_table_all[i].resize(N);

    }

    for(int i=0;i<M;i++){
        scanf("%d %d %lld", &u, &v, &cost);
        adj_list[u-1].push_back(make_pair(cost, v-1));
        inverse_adj_list[v-1].push_back(make_pair(cost, u-1));
    }

    dijkstra(0, 0);
    dijkstra(0, 1);

    ans = T * get_money[0];
    for(int i=1;i<N;i++){
        cost = distance_table_normal[i] + distance_table_inverse[i];
        if(T<cost) continue;
        ans = max(ans, (T-cost)*get_money[i]);
    }

    printf("%lld\n", ans);


    return 0;

}