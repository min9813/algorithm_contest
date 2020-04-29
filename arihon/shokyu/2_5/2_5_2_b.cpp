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
static const int max_n = 110;
static const llong max_cost = 2000000000000000;
using namespace std;
// vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
vector<llong> distance_table(max_n, max_cost);
vector<vector<llong>> distance_table_cache(max_n, vector<llong>(max_n, -1));
int N, K; 
int S, T;


void dijkstra(int st){
    int v;
    llong min_cost;
    // priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> PQ;
    vector<bool> used(N, false);
    
    fill(distance_table.begin(), distance_table.end(), max_cost);
    distance_table[st] = 0;
    used[st] = true;

    for(int i=0;i<N;i++){
        if(adj_matrix[st][i]<max_cost){
            distance_table[i] = adj_matrix[st][i];
        }
    }

    while(true){
        v = -1;
        min_cost = max_cost;
        for(int i=0;i<N;i++){
            if(distance_table[i]<min_cost && !used[i]){
                v = i;
                min_cost = distance_table[i];
            }
        }

        if(v == -1){
            break;
        }
        used[v] = true;
        
        for(int i=0;i<N;i++){
            llong edge_cost = adj_matrix[v][i];
            if(edge_cost<max_cost && edge_cost + min_cost < distance_table[i]){
                distance_table[i] = edge_cost + min_cost;
            }
        }
    }

    distance_table_cache[st] = distance_table;

}

int main(){
    int index, u, v, num=0;
    bool updated = false;
    llong cost;
    scanf("%d %d", &N, &K);

    for(int i=0;i<K;i++){
        scanf("%d ", &index);
        if (index){
            scanf("%d %d %lld", &u, &v, &cost);
            if (adj_matrix[u-1][v-1] > cost){
                adj_matrix[u-1][v-1] = cost;
                adj_matrix[v-1][u-1] = cost;
                num ++;
                updated = true;
            }

        }else{
            scanf("%d %d", &S, &T);
            if (num>1){
                llong distance;
                if(updated){
                    for(int i=0;i<N;i++){
                        distance_table_cache[i] = vector<llong>(max_n, -1);
                    }
                    dijkstra(S-1);
                    distance = distance_table[T-1];
                }else if(distance_table_cache[S-1][T-1]==-1){
                    dijkstra(S-1);
                    distance = distance_table[T-1];
                }else{
                    distance = distance_table_cache[S-1][T-1];
                }
                if(distance < max_cost){
                    printf("%lld\n", distance);
                }else{
                    printf("%lld\n", (llong)-1);
                }
            }else if(adj_matrix[S-1][T-1]!=max_cost){
                printf("%lld\n", adj_matrix[S-1][T-1]);
            }else{
                printf("%lld\n", (llong)-1);
            }
            updated = false;
        }
    }


    return 0;

}