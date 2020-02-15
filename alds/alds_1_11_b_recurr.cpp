#include<stdio.h>
#include<iostream>
using namespace std;
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N], d[N], f[N], tt;

void dfs(int u){
    color[u-1] = GRAY;
    d[u-1] = ++tt;
    int i;
    for(i=0;i<n;i++){
        if((M[u-1][i]) && (color[i]==WHITE)){
            dfs(i+1);
        }
    }
    f[u-1] = ++tt;
    color[u-1] = BLACK;
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

    for(i=1;i<n+1;i++){
        if(color[i-1]==WHITE){
            dfs(i);
        }
    }

    for(i=0;i<n;i++){
        printf("%d %d %d\n", i+1,d[i],f[i]);
    }




}
