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
static const int max_e = 1000010;
static const llong max_cost = 2000000000000000;
using namespace std;
// vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
// vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
set<pair<llong, pair<int, int>>> edge_list;


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


llong kruskal(){
    DisjointSet DS(N);
    llong total_weight = 0;
    for(auto &edge:edge_list){
        if(DS.same(edge.second.first, edge.second.second)){
            continue;
        }else{
            DS.unite(edge.second.first, edge.second.second);
            total_weight += edge.first;
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
        edge_list.insert(make_pair(cost, make_pair(u, v)));
    }

    ans = kruskal();

    printf("%lld\n", ans);


    return 0;

}