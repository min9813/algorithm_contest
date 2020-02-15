#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N], d[N], f[N], tt;

int next(int u){
    for(int i=0;i<n;i++){
        if(color[i]==WHITE && M[u-1][i]){
            return i+1;
        }
    }
    return -1;

}

void dfs(){
    int v,w,i;
    stack<int> S;
    for(i=1;i<n+1;i++){
        if(color[i-1]==WHITE){
            S.push(i);
            color[i-1] = GRAY;
            d[i-1] = ++tt;
            while (!S.empty()){
                v = S.top();
                w = next(v);
                if(w==-1){
                    S.pop();
                    color[v-1] = BLACK;
                    f[v-1] = ++tt;
                }else{
                    S.push(w);
                    color[w-1] = GRAY;
                    d[w-1] = ++tt;
                }
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
    dfs();



    for(i=0;i<n;i++){
        printf("%d %d %d\n", i+1,d[i],f[i]);
    }




}
