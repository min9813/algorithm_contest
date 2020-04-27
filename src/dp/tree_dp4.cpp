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
vector<double> expect(MAX);
vector<double> all_expect(MAX);
int answer=0, N;

void dfs1(int st, int parent){
    // expect[st] = 0.;
    // double division = (double)edge_list[st].size();
    double ret = 0.;
    int child = 0;
    for(auto edge:edge_list[st]){
        if(edge.to==parent) continue;
        dfs1(edge.to, st);
        // expect[st] += (expect[edge.to] + 1.) / division;
        ret += expect[edge.to] + 1.;
        child ++;
    }

    ret = ret / max(1, child);
    // printf("%d's expect = %lf\n",st, ret);
    expect[st] = ret;
}

void dfs2(int st, int d_parent, int parent){
    vector<pair<double, int>> d_child;
    d_child.emplace_back(0, -1);
    // int n_change = 0;
    double this_expect = 0.;
    double num_child = (double)edge_list[st].size();
    int num_size = (int)edge_list[st].size();
    for(auto edge:edge_list[st]){
        // if(edge.to==parent)d_child.emplace_back(d_parent+edge.type,edge.to);
        double temp;
        if(edge.to==parent){
            temp = (d_parent+1.) / num_child;
            d_child.emplace_back(temp,edge.to);
        } 
        else{
            // n_change += edge.type + weight[edge.to];
            temp = (expect[edge.to] + 1.) / num_child;
            d_child.emplace_back(temp,edge.to);
        }
        this_expect += temp;
    }
    // sort(d_child.rbegin(), d_child.rend());
    all_expect[st] = this_expect;

    // all_dist[st] = n_change;
    // printf("------------\n");
    // printf("d_parent = %d\n", d_parent);
    // printf("d child size=%d\n",(int)d_child.size());
    // printf("%d max dist = %d\n", st, ret);
    for(int i=0;i<num_size;i++){
        auto edge = edge_list[st][i];
        if(edge.to==parent) continue;
        dfs2(edge.to, (this_expect*num_child-expect[edge.to]-1)/max(1,num_size-1), st);
        // ret = min(ret, dfs2(edge.to, d_child[d_child[0].second==edge.to].first, n_change-weight[edge.to]-edge.type, st));
    }
    // return ret;
}

int main(){
    int c, i, u, v, max_dist, max_i;
    scanf("%d", &N);
    for(int i=0;i<N-1;i++){
        scanf("%d %d", &u, &v);
        edge_list[u-1].push_back((Edge){v-1, 1});
        edge_list[v-1].push_back((Edge){u-1, 1});
    }

    dfs1(0, -1);
    dfs2(0, 0, -1);
    
    for(int i=0;i<N;i++){
        printf("%lf\n", all_expect[i]);
    }



    return 0;
}