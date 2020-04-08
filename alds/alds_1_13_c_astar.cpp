#include<cstdio>
#include<string>
#include<cmath>
#include <stdlib.h>
#include<queue>
#include<set>
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
    int MD, cost;

    bool operator < (const Puzzle &p) const{
        for(int i=0;i<N2;i++){
            if(f[i]==p.f[i]) continue;
            return f[i] < p.f[i];
        }
        return false;
    }
};

struct State{
    Puzzle puzzle;
    int estimated;
    bool operator < (const State &s) const{
        return estimated > s.estimated;
    }
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

int astar(Puzzle s){
    priority_queue<State> PQ;
    s.MD = get_manhattan_distance(s);
    s.cost = 0;
    set<Puzzle> S;
    Puzzle u,v;
    State initial, st;
    bool is_new;
    initial.puzzle = s;
    initial.estimated = s.MD;
    S.insert(s);
    PQ.push(initial);
    while(!PQ.empty()){
        st = PQ.top();PQ.pop();
        u = st.puzzle;
        // printf("--------------\n");
        // print_puzzle(u);
        if(u.MD==0) return u.cost;
        int sx = u.space / N;
        int sy = u.space % N;
        for(int r=0;r<4;r++){
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if(tx<0||ty<0||tx>=N||ty>=N) continue;
            v = u;
            v.MD -= MDT[tx*N+ty][v.f[tx*N+ty]-1];
            v.MD += MDT[sx*N+sy][v.f[tx*N+ty]-1];
            swap(v.f[tx*N+ty], v.f[sx*N+sy]);
            v.space = tx * N + ty;
            is_new = S.find(v) == S.end();
            if(is_new){
                v.cost ++;
                State new_s;
                new_s.puzzle = v;
                new_s.estimated = v.cost + v.MD;
                S.insert(v);
                PQ.push(new_s);
            }
        }
    }
    return -1;
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

    int dist = astar(p);
    printf("%d\n", dist);
    return 0;
}