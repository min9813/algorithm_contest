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

void dfs(int s){
    int i = 0;
    searched[s] = true;
    for(i=0;i<G[s].size();i++){
        if(!searched[G[s][i]]) dfs(G[s][i]);
    }

    out.push_front(s);
}

void tsort(){
    for(int u=0;u<N;u++){
        if(!searched[u]) dfs(u);
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