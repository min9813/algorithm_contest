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
vector<vector<pair<int, pair<llong, llong>>>> adj_list(max_n);
vector<llong> total_cost_money(max_n, max_cost);
vector<llong> distance_table_en(max_n, max_cost);
vector<llong> distance_table_snuke(max_n, max_cost);
llong N, M; 
int S, T;


void dijkstra(int st, bool is_en){
    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> PQ;

    if (is_en){
        fill(distance_table_en.begin(), distance_table_en.end(), max_cost);
        distance_table_en[st] = 0;
        for(auto &p:adj_list[st]){
            // distance_table[p.first] = p.second.first;
            PQ.push(make_pair(p.second.first, p.first));
        }

    }else{
        fill(distance_table_snuke.begin(), distance_table_snuke.end(), max_cost);
        distance_table_snuke[st] = 0;
        for(auto &p:adj_list[st]){
            // distance_table[p.first] = p.second.second;
            PQ.push(make_pair(p.second.second, p.first));
        }
    }


    while(!PQ.empty()){
        auto u = PQ.top(); PQ.pop();
        
        if (is_en){
            if(u.first>distance_table_en[u.second]){
                continue;
            }
            distance_table_en[u.second] = u.first;
            for(auto &p:adj_list[u.second]){
                // distance_table[p.first] = p.second.first;
                llong new_cost = p.second.first + u.first;
                if(new_cost < distance_table_en[p.first]){
                    distance_table_en[p.first] = new_cost;
                    PQ.push(make_pair(new_cost, p.first));
                }

            }

        }else{
            if(u.first>distance_table_snuke[u.second]){
                continue;
            }
            distance_table_snuke[u.second] = u.first;
            for(auto &p:adj_list[u.second]){
                // distance_table[p.first] = p.second.first;
                llong new_cost = p.second.second + u.first;
                if(new_cost < distance_table_snuke[p.first]){
                    distance_table_snuke[p.first] = new_cost;
                    PQ.push(make_pair(new_cost, p.first));
                }

            }
        }
    }



}

int main(){
    int u, v;
    llong a, b, en_cost, snuke_cost;
    scanf("%lld %lld %d %d", &N, &M, &S, &T);

    for(int i=0;i<M;i++){
        scanf("%d %d %lld %lld", &u, &v, &a, &b);
        adj_list[u-1].push_back(make_pair(v-1, make_pair(a, b)));
        adj_list[v-1].push_back(make_pair(u-1, make_pair(a, b)));
    }

    dijkstra(S-1, true);
    // for(int i=0;i<N;i++){
        // printf("%d to %d min en cost=%lld\n", S-1, i, distance_table_en[i]);
    // }
    dijkstra(T-1, false);
    // for(int i=0;i<N;i++){
        // printf("%d to %d min snuke cost=%lld\n", T-1, i, distance_table_snuke[i]);
    // }

    llong min_value = max_cost;
    for(int i=N-1;i>=0;i--){
        llong get_ith_min_value = distance_table_en[i] + distance_table_snuke[i];
        // printf("%d th exchange:%lld, min_value=%lld \n", i, get_ith_min_value, min_value);
        min_value = min(min_value, get_ith_min_value);
        total_cost_money[i] = min_value;
    }

    for(int i=0;i<N;i++){
        printf("%lld\n", 1000000000000000-total_cost_money[i]);
    }


    return 0;

}