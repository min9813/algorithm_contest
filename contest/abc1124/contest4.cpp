#include <vector>
#include <stdio.h>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

int main(){
    int N, a, b, node, next_node, K=0, i, cur;
    scanf("%d", &N);
    vector<vector <int> > G(N);
    vector<pair <int, int>> edge;
    queue<int> que;
    for(int i=1;i<N;i++){
        scanf("%d %d", &a, &b);
        a --; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        edge.emplace_back(a,b);
    }

    vector<int> used(N,0);
    vector<int> node_c(N,0);
    map<pair<int,int>, int> Ans;

    que.emplace(edge[0].first);
    used[edge[0].first] = 1;
    while(! que.empty()){
        node = que.front(); que.pop();
        if(K<(int)G[node].size()) K = G[node].size();
        cur = 1;
        // cout << "---------------" << node << "---------------" << endl;
        for(int next_node:G[node]){
            // next_node = G[node][i];
            // cout << "cur:" << cur << endl;
            if(used[next_node]) continue;
            if(cur == node_c[node]) cur++;
            // cout << "ok"<< endl;

            node_c[next_node] = Ans[make_pair(next_node, node)] = Ans[make_pair(node, next_node)] = cur++;
            used[next_node] = 1;
            que.emplace(next_node);
        }
    }

    printf("%d\n", K);
    for(auto nodes:edge){
        printf("%d\n", Ans[nodes]);
    }

    return 0;

}