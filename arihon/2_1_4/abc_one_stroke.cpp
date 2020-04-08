#include <cstdio>
#include <vector>
using namespace std;
static const int MAX = 10;
vector<vector<int>> adj_mat(MAX, vector<int>(MAX, 0));
vector<int> permutation(MAX);
vector<bool> used(MAX, false);
int N, M, num=0;

void solve(int pos, int v){
    // printf("pos=%d node=%d ", pos, v);
    if(pos==N-1){
        // printf("return\n");
        num ++;
        return;
    }
    // printf("no\n");
    for(int i=0;i<N;i++){
        if(used[i]){
            continue;
        }else if(adj_mat[v][i]){
            used[i] = true;
            solve(pos+1, i);
            used[i] = false;
        }
    }

}

int main(){
    scanf("%d %d", &N, &M);
    int u, v;
    for(int i=0;i<M;i++){
        scanf("%d %d", &u, &v);
        adj_mat[u-1][v-1] = 1;
        adj_mat[v-1][u-1] = 1;
    }
    used[0] = true;

    solve(0, 0);

    printf("%d\n", num);

}
