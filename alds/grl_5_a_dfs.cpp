#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
    int to, from, w;
};

static const int MAX = 100010;
static const int INFTY = (1<<30);
int N;
int d[MAX];
vector<vector<Edge>> edge_list(MAX);
vector<bool>searched;
vector<int> distance_list(MAX, 0);

void dfs(int st, int dist){
    // printf("dfs start at st = %d dist=%d !\n", st, dist);

    distance_list[st] = dist;
    searched[st] = true;
    for(auto edge:edge_list[st]){
        if(searched[edge.to]) continue;
        dfs(edge.to, dist+edge.w);
    }
}



int main(){
    int c, i, u, v, max_dist, max_i;
    scanf("%d", &N);
    if(N>1){
        searched.resize(N);
        for(int i=0;i<N-1;i++){
            scanf("%d %d %d", &u, &v, &c);
            edge_list[u].push_back((Edge){v, u, c});
            edge_list[v].push_back((Edge){u, v, c});
        }

        // printf("input ok !\n");
        fill(searched.begin(), searched.end(), false);
        dfs(0, 0);
        // printf("dfs ok !\n");

        max_i = -1, max_dist=-1;
        for(int i=0;i<N;i++){
            if(distance_list[i] > max_dist){
                max_dist = distance_list[i];
                max_i = i;
            }
        }
        fill(searched.begin(), searched.end(), false);
        dfs(max_i, 0);
        max_i = -1, max_dist=-1;
        for(int i=0;i<N;i++){
            if(distance_list[i] > max_dist){
                max_dist = distance_list[i];
                max_i = i;
            }
        }
    }else{
        max_dist = 0;
    }
        
    printf("%d\n", max_dist);



    return 0;
}