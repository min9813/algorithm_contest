#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
    int to, w, type;
};

static const int MAX = 100010;
static const int INFTY = (1<<30);
vector<vector<Edge>> edge_list(MAX);
// vector<vector<int>> tree_dp(MAX, vector<int>(MAX, -INFTY)); 
vector<int> dist(MAX);
vector<int> weight(MAX);
vector<int> all_dist(MAX);
int answer=0, N, D;

void dfs1(int st, int parent){
    dist[st] = 0;
    weight[st] = 0;
    for(auto edge:edge_list[st]){
        if(edge.to==parent) continue;
        dfs1(edge.to, st);
        dist[st] = max(dist[st], edge.w + dist[edge.to]);
        weight[st] += weight[edge.to] + edge.type;
    }
}

int dfs2(int st, int d_parent, int d_weight, int parent){
    vector<pair<int, int>> d_child;
    d_child.emplace_back(0, -1);
    int n_change = 0;

    for(auto edge:edge_list[st]){
        // if(edge.to==parent)d_child.emplace_back(d_parent+edge.type,edge.to);
        if(edge.to==parent){
            n_change += d_weight + edge.type;
            d_child.emplace_back(d_parent+edge.w,edge.to);
        } 
        else{
            n_change += edge.type + weight[edge.to];
            d_child.emplace_back(dist[edge.to] + edge.w,edge.to);
        }
    }
    sort(d_child.rbegin(), d_child.rend());
    int ret = INFTY;
    if(d_child[0].first <= D){
        ret = n_change;
    }
    // all_dist[st] = n_change;
    // printf("------------\n");
    // printf("d_parent = %d\n", d_parent);
    // printf("d child size=%d\n",(int)d_child.size());
    // printf("%d max dist = %d\n", st, ret);
    for(auto edge:edge_list[st]){
        if(edge.to==parent) continue;
        ret = min(ret, dfs2(edge.to, d_child[d_child[0].second==edge.to].first, n_change-weight[edge.to]-edge.type, st));
    }
    return ret;
}

int main(){
    int c, i, u, v, max_dist, max_i;
    scanf("%d %d", &N, &D);
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d", &u, &v, &c);
        edge_list[u-1].push_back((Edge){v-1, c, 1});
        edge_list[v-1].push_back((Edge){u-1, c, 0});
    }

    dfs1(0, -1);
    int ans = dfs2(0, 0, 0, -1);
    
    if(ans == INFTY) printf("-1\n");
    else printf("%d\n", ans);



    return 0;
}