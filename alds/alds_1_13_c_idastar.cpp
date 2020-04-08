#include<cstdio>
#include<string>
#include<cmath>
#include <stdlib.h>
using namespace std;

static const int N = 4;
static const int N2 = 16;
static const int LIMIT = 100;

static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char dir[4] = {'r', 'u','l','d'};

int MDT[N2][N2];

struct Puzzle{
    int f[N2];
    int space;
    int MD;
};

Puzzle state;

int limit;
int Path[LIMIT];

void print_puzzle(const Puzzle &p){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ", p.f[i*N+j]);
        }
        printf("\n");
    }
    printf("-------- \n");
}

int get_manhattan_distance(Puzzle &p){
    int sum = 0;
    for(int i=0;i<N2;i++){
        if(p.f[i]==N2) continue;
        sum += MDT[i][p.f[i]-1];
    }
    return sum;
}

bool dfs(int depth, int prev){
    // printf("------ depth = %d limit=%d MD=%d ------\n", depth, limit, state.MD);
    // print_puzzle(state);
    if(state.MD == 0){
        return true;
    }
    if(depth + state.MD > limit) return false;
    int sx = state.space / N;
    int sy = state.space % N;

    Puzzle tmp;
    for(int r=0;r<4;r++){
        int tx = sx + dx[r];
        int ty = sy + dy[r];
        if(tx<0 || ty < 0 || tx >= N || ty >= N) continue;
        if(max(prev, r)-min(prev, r)==2) continue;
        tmp = state;
        // printf("-- tx,ty = %d,%d ,value=%d MD=%d --\n",tx*N, ty,state.f[tx*N+ty], MDT[tx*N+ty][state.f[tx*N+ty]-1]);
        // printf("-- sx,sy = %d,%d ,value=%d MD=%d --\n",sx*N, sy,state.f[tx*N+ty], MDT[sx*N+sy][state.f[tx*N+ty]-1]);
        state.MD -= MDT[tx*N+ty][state.f[tx*N+ty]-1];
        state.MD += MDT[sx*N+sy][state.f[tx*N+ty]-1];
        swap(state.f[tx*N+ty], state.f[sx*N+sy]);
        state.space = tx * N + ty;
        if(dfs(depth+1, r)) {
            Path[depth] = r;
            return true;
        }
        state = tmp;
    }
    return false;
}


string iterative_dfs(Puzzle &in){
    in.MD = get_manhattan_distance(in);
    // printf("md=%d", in.MD);
    for(limit = in.MD;limit<LIMIT;limit++){
        state = in;
        if(dfs(0, -100)){
            string ans;
            for(int i=0;i<limit;i++){
                ans += dir[Path[i]];
            }
            return ans;
        }

    }
    return "unsolvable";
}

int main(){
    int v;
    Puzzle p;
    for(int i=0;i<N2;i++){
        for(int j=0;j<N2;j++){
            MDT[i][j] = abs(i/N - j/N) + abs(i%N - j%N);
            // printf("%d ", MDT[i][j]);
        }
        // printf("\n");
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &v);
            if(v==0){
                v = N2;
                p.space = i*N + j;
            }
            p.f[i*N+j] = v;
        }
    }

    string ans = iterative_dfs(p);
    printf("%d\n", (int)ans.size());
    return 0;
}