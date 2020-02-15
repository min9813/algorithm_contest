#include <cstdio>
#include <algorithm>
using namespace std;

static const int MAX = 100;
static const long long INFTY = (1LL<<32);

long long D[MAX][MAX];
int n;

void floyd(){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(D[j][i]==INFTY) continue;
            for(k=0;k<n;k++){
                if(D[i][k]==INFTY) continue;
                D[j][k] = min(D[j][k], D[j][i]+D[i][k]);
            }
        }
    }
}



int main(){
    int e, i, j, u, v;
    long long d;
    scanf("%d %d", &n, &e);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            D[i][j] = INFTY;
        }
        D[i][i] = 0;
    }

    for(i=0;i<e;i++){
        scanf("%d %d %lld", &u, &v, &d);
        D[u][v] = d;
    }
    floyd();


    bool is_negative_loop = false;
    for(i=0;i<n;i++){
        if(D[i][i]<0){
            is_negative_loop = true;
            break;
        }
    }

    if(is_negative_loop){
        printf("NEGATIVE CYCLE\n");
        return 0;
    }else{
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j!=0) printf(" ");
                if(D[i][j]==INFTY) printf("INF");
                else printf("%lld", D[i][j]);
                if(j==n-1) printf("\n");
            }
        }
    }

}