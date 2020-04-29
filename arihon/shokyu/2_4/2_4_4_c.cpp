#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
typedef long long llong;
static const int max_n = 100010;
using namespace std;

vector<int> numbers(max_n);


class DisjointSet{
    public:
        vector<int> rank, p;

        DisjointSet(){}
        DisjointSet(int size){
            rank.resize(size, 0);
            p.resize(size, 0);
            for(int i=0;i<size;i++){
                makeSet(i);
            }
        }

        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }

        bool same(int x, int y){
            return findSet(x) == findSet(y);
        }

        void unite(int x, int y){
            link(findSet(x), findSet(y));
        }

        void link(int x, int y){
            if(rank[x]>rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y] ++;
                }
            }
        }

        int findSet(int x){
            if(x!=p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};



int main(){
    int N, M, p, a;
    scanf("%d %d", &N, &M);
    DisjointSet DS(N);
    for(int i=0;i<N;i++){
        scanf("%d ", &p);
        numbers[i] = p-1;
    }

    for(int i=0;i<M;i++){
        scanf("%d %d", &p, &a);
        DS.unite(p-1, a-1);
    }

    int ans = 0;
    for(int i=0;i<N;i++){
        ans += (int)DS.same(i, numbers[i]);
    }

    printf("%d\n", ans);

}
