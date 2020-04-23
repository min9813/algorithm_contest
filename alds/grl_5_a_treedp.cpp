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
vector<int> pass_length(MAX, 0);
vector<int> subtree_length(MAX, 0);

int answer=0, N;

void dfs(int V, int pV){
    vector<pair<int, int>> this_subtree;
    // printf("V = %d, pV=%d\n", V, pV);
    for(auto edge:edge_list[V]){
        if(edge.to==pV) continue;
        dfs(edge.to, V);
        this_subtree.push_back(make_pair(edge.w, subtree_length[edge.to]+edge.w));
    }

    int max_dist=-1, max_i=-1, max_edge=-1;
    for(int i=0;i<this_subtree.size();i++){
        if(this_subtree[i].second>=max_dist){
            max_dist = this_subtree[i].second;
            max_edge = this_subtree[i].first;
            max_i = i;
        }
    }

    int second_max_dist=-1, second_max_i=-1, second_max_edge=-1;
    for(int i=0;i<this_subtree.size();i++){
        if(this_subtree[i].second>=second_max_dist && i!=max_i){
            second_max_dist = this_subtree[i].second;
            second_max_edge = this_subtree[i].first;
            second_max_i = i;
        }
    }
    // printf("######## V = %d, pV = %d #####\n", V, pV);
    // printf("max length, id, edge=%d, %d, %d\n", max_dist, max_i, max_edge);
    // printf("second max length, id, edge=%d, %d, %d\n", second_max_dist, second_max_i, second_max_edge);
    subtree_length[V] = 0;
    if(this_subtree.size()>0){
        subtree_length[V] = max_dist;
    }
    // printf("sub treee length %d = %d\n", V, subtree_length[V]);
    if(this_subtree.size()>1){
        pass_length[V] = max_dist + second_max_dist;
    }
    // printf("pass length %d = %d\n", V, pass_length[V]);

    // printf("------------------------\n");
    

    answer = max(answer, max(subtree_length[V], pass_length[V]));
    
}



int main(){
    int c, i, u, v, max_dist, max_i;
    scanf("%d", &N);
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d", &u, &v, &c);
        edge_list[u].push_back((Edge){v, c});
        edge_list[v].push_back((Edge){u, c});
    }

    dfs(0, -1);
        
    printf("%d\n", answer);



    return 0;
}