#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

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
        void makeSet(int i){
            rank[i] = 0;
            p[i] = i;
        }


        int findSet(int u){
            while(u!=p[u]){
                u = p[u];
            }
            return u;
        }

        void unite(int u, int v){
            link(findSet(u), findSet(v));
        }

        void link(int x, int y){
            if(rank[x]>rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x]==rank[y]){
                    rank[y] ++;
                }
            }
        }
};

class Edge{
    public:
        int s,t, w;
        Edge(){}
        Edge(int s, int t, int w): s(s), t(t), w(w){}
        bool operator < (const Edge &e) const{
            return w < e.w;
        }
};

static const int MAX = 100000;
static const int INFTY = (1<<30);
bool searched[MAX];
int N;
int d[MAX];
vector<Edge> G;


int kruskal(){
    int total_cost = 0;
    sort(G.begin(), G.end());
    vector<Edge> ans;
    DisjointSet ds(N);    

    for(auto e:G){
        if(ds.findSet(e.s) != ds.findSet(e.t)){
            ans.push_back(e);
            total_cost += e.w;
            ds.unite(e.s, e.t);
        }
    }


    return total_cost;
    
}



int main(){
    int k, c, i, u, v, total_cost;
    scanf("%d %d", &N, &k);
    for(int i=0;i<k;i++){
        scanf("%d %d %d", &u, &v, &c);
        G.push_back(Edge(u,v,c));
    }

    total_cost = kruskal();

    printf("%d\n", total_cost);

    return 0;
}