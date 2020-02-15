#include<iostream>
#define MAX 100
#define INFTY 1<<21
#define WHITE 0
#define GLAY 1
#define BLACK 2
using namespace std;

int M[MAX][MAX], n, d[MAX];

void dijkstra(){
    int i,u, minv;
    int color[MAX], p[MAX];
    u=0;
    for(i=0;i<n;i++){
        color[i] = WHITE;
        p[i] = -1;
        d[i] = M[u][i];
    }
    // for(i=0;i<n;i++){
        // printf("i=%d, d=%d\n", i, d[i]);
    // }
    d[0] = 0;


    while(1){
        minv = INFTY;
        u = -1;

        for(i=0;i<n;i++){
            if(minv > d[i] && color[i] != BLACK){
                minv = d[i];
                u = i;
            }
        }

        if(u==-1) break;
        color[u] = BLACK;

        for(i=0;i<n;i++){
            if(color[i]!=BLACK && M[u][i] != INFTY){
                if(d[i]>M[u][i]+d[u]){
                    d[i] = M[u][i] + d[u];
                    p[i] = u;
                    color[i] = GLAY;
                }
            }
        }
    }

}


int main(){
    int i, j, e,k,u,v,c;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M[i][j] = INFTY;
        }
    }

    for(i=0;i<n;i++){
        cin >> u >> k;
        for(j=0;j<k;j++){
            cin >> v >> c;
            M[u][v] = c;
        }
    }
    dijkstra();

    for(i=0;i<n;i++){
        cout << i << " " <<d[i] <<"\n";
    }


    return 0;
}