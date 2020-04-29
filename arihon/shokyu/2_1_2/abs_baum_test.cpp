#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;
static const int MAX = 100;
vector<vector<int>>adj_mat(MAX, vector<int>(MAX, 0));
vector<int> nodes(MAX, 0);
int N, M, num;

int solve(int u, int prev){
    if(nodes[u]){
        // printf("node %d , return 0\n", u);
        return 0;
    }else{
        nodes[u] = 1;
    }
    for(int i=0;i<N;i++){
        // printf("max[%d][%d]= %d \n", u,i,adj_mat[u][i]);
        if(adj_mat[u][i] && i!=prev){
            if(nodes[i]){
                return 0;
            }else{
                int re = solve(i, u);
                if(re){
                    continue;
                }else{
                    return re;
                }
            }
        }
    }
    // printf("node %d , return 1\n", u);
    return 1;
}

int main(){
    int u,v;
    scanf("%d %d", &N, &M);

    for(int i=0;i<M;i++){
        scanf("%d %d", &u, &v);
        adj_mat[u-1][v-1] = 1;
        adj_mat[v-1][u-1] = 1;
    }

    num = 0;
    for(int i=0;i<N;i++){
        num += solve(i, i);
    }

    printf("%d\n", num);
}