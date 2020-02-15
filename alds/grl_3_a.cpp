#include <cstdio>
#include <set>
#include <vector>
using namespace std;

static const int MAX = 100000;
bool searched[MAX];
int prenum[MAX], lowest[MAX], parent[MAX], N, np;
vector<int> G[MAX];
set<int> ans;

void dfs(int current, int prev){
    int next;
    searched[current] = true;
    prenum[current] = lowest[current] = np;
    np ++;
    for(int i=0;i<G[current].size();i++){
        next = G[current][i];
        if(!searched[next]){
            parent[next] = current;
            dfs(next, current);
            lowest[current] = min(lowest[current], lowest[next]);
        }else if(next != prev){
            // 無向辺なのでprev　は自然とG[u]にある。
            // 下の子のlowestだけを使う
            lowest[current] = min(lowest[current], prenum[next]);
        }
    }
}

void art_points(){
    int i;
    for(i=0;i<N;i++) searched[i] = false;
    np = 1;
    parent[0] = -1;
    dfs(0, -1);

    int root_chil_num = 0;

    for(i=0;i<N;i++){
        int p = parent[i];
        if(p==0) root_chil_num ++;
        else if(p!=-1 && prenum[p]<=lowest[i]){
            ans.insert(p);
            // printf("%d ", p);
        } 
    }

    if(root_chil_num>1) ans.insert(0);
    for(auto it:ans){
        printf("%d\n", it);
    }
}

int main(){
    int k, i, u, v;
    scanf("%d %d", &N, &k);
    for(int i=0;i<k;i++){
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    art_points();

    return 0;
}