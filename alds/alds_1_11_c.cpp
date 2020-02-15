#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int INFTY = (1<<21);
int color[N], d[N], f[N], tt;

void bfs(int s){
    int i, u, v;
    queue<int> Q;
    Q.push(s);
    color[s-1] = GRAY;
    for(i=0;i<n;i++){
        d[i] = INFTY;
    }
    d[s-1] = 0;
    while(!Q.empty()){
        u = Q.front();Q.pop();
        for(v=0;v<n;v++){
            if(M[u-1][v]==0){
                continue;
            }
            if(color[v]==WHITE){
                Q.push(v+1);
                d[v] = d[u-1] + 1;
                color[v] = GRAY;
            }
        }
    }
}


int main(){
    int i,j,u,v,k;
    tt = 0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        color[i] = WHITE;
        for(j=0;j<n;j++){
            M[i][j] = 0;
        }
    }

    for(i=0;i<n;i++){
        scanf("%d %d", &u, &k);
        for(j=0;j<k;j++){
            scanf("%d", &v);
            M[u-1][v-1] = 1;
        }
    }

    // for(i=0;i<n;i++){
    //     for(j=0;j<n-1;j++){
    //         cout << M[i][j] << " ";
    //     }
    //     cout << M[i][j] << "\n";
    // }
    bfs(1);



    int dist;
    for(i=0;i<n;i++){
        if(d[i]==INFTY){
            dist = -1;
        }else{
            dist = d[i];
        }
        printf("%d %d\n", i+1,dist);
    }


    return 0;

}
