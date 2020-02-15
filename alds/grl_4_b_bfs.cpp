#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<queue>
using namespace std;
const int MAX = 10000;

vector<int> G[MAX];
list<int> out;
bool searched[MAX];
int N;
int indeg[MAX];

void bfs(int s){
    int i = 0, u, v;
    queue<int> Q;
    Q.push(s);
    searched[s] = true;
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        out.push_back(u);

        for(i=0;i<G[u].size();i++){
            v = G[u][i];
            indeg[v] --;
            if(indeg[v]==0 && !searched[v]){
                searched[v] = true;
                Q.push(v);
            }
        }
    }
}

void tsort(){
    int i, j, v;
    for(i=0;i<N;i++){
        indeg[i] = 0;
    }

    for(i=0;i<N;i++){
        for(j=0;j<G[i].size();j++){
            v = G[i][j];
            indeg[v] ++;
        }
    }

    for(int u=0;u<N;u++){
        if(indeg[u]==0 && !searched[u]) bfs(u);
    }

    for(auto it:out){
        printf("%d\n", it);
    }
}

int main(){
    int s, t, M, i;
    scanf("%d %d", &N, &M);
    for(i=0;i<M;i++){
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
    }

    for(i=0;i<N;i++) searched[i] = false;

    tsort();
    return 0;
}