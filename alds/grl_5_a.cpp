#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class Edge{
    public:
        int t, w;
        Edge(){}
        Edge(int t, int w): t(t), w(w){}
};

static const int MAX = 100000;
static const int INFTY = (1<<30);
bool searched[MAX];
int N;
int d[MAX];
vector<Edge> G[MAX];


void bfs(int u){
    for(int i=0;i<N;i++){
        d[i] = INFTY;
    }
    int v;
    queue<int> Q;
    Q.push(u);
    d[u] = 0;
    // printf("initialize bfs\n");
    while(!Q.empty()){
        v = Q.front(); Q.pop();
        // printf("size: %d\n", (int)Q.size());
        for(auto k:G[v]){
            // printf("d[%d]=%d d[%d]+k.w=%d\n", k.t, d[k.t], v, d[v]+k.w);
            if(d[k.t]>d[v]+k.w){
                d[k.t] = d[v] + k.w;
                Q.push(k.t);
            }
        }
    }
}



int main(){
    int c, i, u, v;
    scanf("%d", &N);
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d", &u, &v, &c);
        G[u].push_back(Edge(v, c));
        G[v].push_back(Edge(u, c));
    }

    bfs(0);
    int maxv = -1;
    int maxd = -1;

    for(i=0;i<N;i++){
        if (maxd < d[i]){
            maxv = i;
            maxd = d[i];
        }
    }

    bfs(maxv);
    maxd = -1;
    for(i=0;i<N;i++){
        if (maxd < d[i]){
            maxv = i;
            maxd = d[i];
        }
    }
    printf("%d\n", maxd);



    return 0;
}