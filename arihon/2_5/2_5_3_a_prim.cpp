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
vector<llong> distance_table(max_n, max_cost);

int N, E;

class DisjointSet{
    public:
        vector<int> rank, p;

        DisjointSet(){}
        DisjointSet(int size){
            rank.resize(size, 0);
            p.resize(size, 0);
            for(int i=0;i<size;i++){
                makeSet(i);
            }
        }

        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }

        bool same(int x, int y){
            return findSet(x) == findSet(y);
        }

        void unite(int x, int y){
            link(findSet(x), findSet(y));
        }

        void link(int x, int y){
            if(rank[x]>rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y] ++;
                }
            }
        }

        int findSet(int x){
            if(x!=p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};


llong prim(int st){
    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> PQ;
    vector<bool> used(N, false);
    PQ.push(make_pair(0, st));

    llong total_weight = 0;

    while(!PQ.empty()){
        auto u = PQ.top(); PQ.pop();
        if(u.first>distance_table[u.second] || used[u.second]){
            continue;
        }
        used[u.second] = true;
        distance_table[u.second] = u.first;
        total_weight += u.first;
        for(auto &p:adj_list[u.second]){
            if(distance_table[p.second]>p.first && !used[p.second]){
                distance_table[p.second] = p.first;
                PQ.push(make_pair(p.first, p.second));
            }

        }

    }

    return total_weight;
}


void kruskal(){
    DisjointSet DS(N);
    
}

int main(){
    int u, v;
    bool updated = false;
    llong cost, ans;
    scanf("%d %d", &N, &E);

    for(int i=0;i<E;i++){
        scanf("%d %d %lld", &u, &v, &cost);
        adj_list[u].push_back(make_pair(cost, v));
        adj_list[v].push_back(make_pair(cost, u));
    }

    ans = prim(0);

    printf("%lld\n", ans);


    return 0;

}