#include<set>
#include<vector>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;
static const int N = 3;
static const int N2 = 9;
static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char dir[4] = {'u','l', 'd', 'r'};

struct Puzzle{
    int f[N2];
    int space;
    string path;

    bool operator < ( const Puzzle &p) const{
        for(int i=0;i<N2;i++){
            if(f[i]==p.f[i]) continue;
            return f[i] > p.f[i];
        }
        return false;
    }
};

bool is_target(const Puzzle &p){
    for(int i=0;i<N2;i++){
        if(p.f[i]!=i+1) return false;
    }
    return true;
}

void print_puzzle(const Puzzle &p){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ", p.f[i*N+j]);
        }
        printf("\n");
    }
    printf("-------- \n");
}

string bfs(Puzzle s){
    s.path = "";
    queue<Puzzle> Q;
    set<Puzzle> S;
    Puzzle u, v;
    bool is_new;
    Q.push(s);
    S.insert(s);

    while(!Q.empty()){
        Puzzle u = Q.front();Q.pop();
        // print_puzzle(u);

        if(is_target(u)) return u.path;
        int sx = u.space / N;
        int sy = u.space % N;
        for(int i=0;i<4;i++){
            int tx = sx + dx[i];
            int ty = sy + dy[i];
            if(tx<0 || ty < 0 || tx >= N || ty >= N){
                continue;
            }
            v = u;
            swap(v.f[tx*N+ty], v.f[sx*N+sy]);
            is_new = S.find(v) == S.end();
            if(is_new){
                v.space = tx * N + ty;
                S.insert(v);
                v.path += dir[i];
                Q.push(v);
            }
        }
    }
    return "unsolvable";
}

int main(){
    Puzzle p;
    int v;
    string ans;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &v);
            if(v==0){
                p.space = i * N + j;
                v = N2;
            }
            p.f[i*N+j] = v;
        }
    }
    ans = bfs(p);
    printf("%d\n", (int)ans.size());
    return 0;
}