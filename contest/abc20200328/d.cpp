#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
static const ll max_n = 2010;
static const ll max_dist = 10000000;
vector<vector<ll>> distance_table(max_n, vector<ll>(max_n, max_dist));
vector<ll> distance_list(max_n);

ll N, X, Y;

void dijkstra(ll st){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;
    PQ.push(make_pair(0, st));
    fill(distance_list.begin(), distance_list.begin()+N, max_dist);

    while (!PQ.empty()){
        pair<ll, ll> u = PQ.top(); PQ.pop();
        if(u.first > distance_list[u.second]){
            continue;
        }
        distance_list[u.second] = u.first;

        if(u.second > 0 && distance_list[u.second-1]>u.first+1){
            distance_list[u.second-1] = u.first + 1;
            PQ.push(make_pair(u.first + 1, u.second-1));
        }

        if(u.second+1 < N && distance_list[u.second+1]>u.first+1){
            distance_list[u.second+1] = u.first + 1;
            PQ.push(make_pair(u.first + 1, u.second+1));
        }

        if(u.second == X && distance_list[Y]>u.first+1){
            distance_list[Y] = u.first + 1;
            PQ.push(make_pair(u.first + 1, Y));
        }

        if(u.second == Y && distance_list[X] > u.first + 1){
            distance_list[X] = u.first + 1;
            PQ.push(make_pair(u.first + 1, X));
        }

    }

    for(ll i=0;i<N;i++){
        distance_table[st][i] = distance_list[i];
    }

}

int main(){
    // int u, v;
    // bool updated = false;
    scanf("%lld %lld %lld", &N, &X, &Y);
    vector<ll> distance_result(N, 0);

    // distance_list.resize(N);
    X = X - 1;
    Y = Y - 1;
    
    for(ll i=0;i<N;i++){
        // printf("dfs i = %lld\n", i);
        dijkstra(i);
    }
    // printf("dfs finish!\n");
    for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            // printf("distance[%lld][%lld] = %lld\n", i, j, distance_table[i][j]);
            distance_result[distance_table[i][j]] ++;
        }
    }

    ll idx = 0;
    for(ll i=1;i<N;i++){
        printf("%lld\n", distance_result[i]);
    }
    return 0;

}