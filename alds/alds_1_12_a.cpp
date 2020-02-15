#include<iostream>
#define MAX 100
#define INFTY 1<<21
#define WHITE 0
#define GLAY 1
#define BLACK 2
using namespace std;

int M[MAX][MAX], n;

int prim(){
    int i,u, minv;
    int color[MAX], p[MAX], d[MAX];
    for(i=0;i<n;i++){
        color[i] = WHITE;
        p[i] = -1;
        d[i] = INFTY;
    }
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
                if(d[i]>M[u][i]){
                    d[i] = M[u][i];
                    p[i] = u;
                    color[i] = GLAY;
                }
            }
        }
    }

    int sum = 0;
    for(i=0;i<n;i++){
        if(p[i]!=-1) sum += M[i][p[i]];
    }

    return sum;
}


int main(){
    int i, j, e;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> e;
            M[i][j] = (e==-1) ? INFTY :e;
        }
    }

    cout << prim() <<endl;


    return 0;
}