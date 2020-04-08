#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
static const int MAX = 60;
static const int INF = 10000;
static const int OK = 1;
static const int NG = 0;
vector<vector<int>> distance_mat(MAX, vector<int>(MAX, INF));
vector<vector<int>> field(MAX, vector<int>(MAX, NG));
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
pair<int, int> S;
pair<int, int> G;
int R, C;

int solve(){
    queue<pair<int, int>> Q;
    Q.push(S);
    distance_mat[S.first][S.second] = 0;
    field[S.first][S.second] = NG;

    while(!Q.empty()){
        pair<int, int> now_p = Q.front(); Q.pop();
        // printf("now p=(%d, %d)\n", now_p.first, now_p.second);
        for(int i=0;i<(int)dx.size();i++){
            int n_y = now_p.first + dy[i];
            int n_x = now_p.second + dx[i];
            if(n_y>R-1 || n_y < 0){
                continue;
            }
            if(n_x>C-1 || n_x < 0){
                continue;
            }
            if(field[n_y][n_x]==OK){
                field[n_y][n_x] = NG;
                // printf("input n_y,n_x=(%d, %d) flag=%d\n", n_y, n_x, field[n_y][n_x]);
                distance_mat[n_y][n_x] = min(distance_mat[n_y][n_x], distance_mat[now_p.first][now_p.second]+1);
                if(n_y == G.first && n_x == G.second){
                    break;
                }
                Q.push(make_pair(n_y, n_x));
            }

        }

    }


    return distance_mat[G.first][G.second];
}


int main(){
    int u, v;
    scanf("%d %d", &R, &C);
    scanf("%d %d", &u, &v);
    S = make_pair(u-1, v-1);
    scanf("%d %d", &u, &v);
    G = make_pair(u-1, v-1);
    char input;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> input;
            // printf("input=%c", input);
            if(input=='#'){
                // printf("i,j=%d,%d=%d ng\n", i,j,NG);
                field[i][j] = NG;
            }else{
                // printf("i,j=%d,%d=%d ok\n", i,j,OK);

                field[i][j] = OK;
            }
        }
    }


    int num_step = solve();
    printf("%d\n", num_step);


}