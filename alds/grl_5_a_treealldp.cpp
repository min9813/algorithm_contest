#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
    int to, w;
};

static const int MAX = 100010;
static const int INFTY = (1<<30);
vector<vector<Edge>> edge_list(MAX);
// vector<vector<int>> tree_dp(MAX, vector<int>(MAX, -INFTY)); 
vector<int> dist(MAX);
vector<int> all_dist(MAX);
int answer=0, N;

void dfs1(int st, int parent){
    dist[st] = 0;
    for(auto edge:edge_list[st]){
        if(edge.to==parent) continue;
        dfs1(edge.to, st);
        dist[st] = max(dist[st], edge.w + dist[edge.to]);
    }
}

int dfs2(int st, int d_parent, int parent){
    vector<pair<int, int>> d_child;
    d_child.emplace_back(0, -1);

    for(auto edge:edge_list[st]){
        if(edge.to==parent)d_child.emplace_back(d_parent+edge.w,edge.to);
        else{
            d_child.emplace_back(edge.w + dist[edge.to], edge.to);
        }
    }
    sort(d_child.rbegin(), d_child.rend());
    int ret = 0;
    if(d_child.size()>1){
        ret = d_child[0].first + d_child[1].first;
    }else if(d_child.size()>0){
        ret = d_child[0].first;
    }

    all_dist[st] = ret;
    // printf("------------\n");
    // printf("d_parent = %d\n", d_parent);
    // printf("d child size=%d\n",(int)d_child.size());
    // printf("%d max dist = %d\n", st, ret);
    for(auto edge:edge_list[st]){
        if(edge.to==parent) continue;
        ret = max(ret, dfs2(edge.to, d_child[d_child[0].second==edge.to].first, st));
    }

    return ret;
}

int main(){
    int c, i, u, v, max_dist, max_i;
    scanf("%d", &N);
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d", &u, &v, &c);
        edge_list[u].push_back((Edge){v, c});
        edge_list[v].push_back((Edge){u, c});
    }

    dfs1(0, -1);
        
    printf("%d\n", dfs2(0, 0, -1));



    return 0;
}