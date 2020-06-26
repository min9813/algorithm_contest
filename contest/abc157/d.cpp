#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <complex>
#include <random>
#include <bitset>
#include <list>
// #include <prettyprint.hpp>
using namespace std;
#define repi(i,n) for(int i=0;i<n;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repinvi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
typedef long long ll;
typedef double lf;
typedef short int si;


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

void Main(){
    ll M, N, K, a, b;
    sll(N);
    sll(M);
    sll(K);

    DisjointSet DS(N);
    map<ll, set<ll>> friends;
    map<ll, set<ll>> blocks;

    rep(i, M){
        sll(a);
        sll(b);
        -- a;
        -- b;
        DS.unite(a, b);
        friends[a].insert(b);
        friends[b].insert(a);
    }

    rep(j, K){
        sll(a);
        sll(b);
        -- a;
        -- b;
        blocks[a].insert(b);
        blocks[b].insert(a);
    }

    map<ll,ll> group;
    map<ll, set<ll>> childlen;
    rep(i, N){
        ll parent = DS.findSet(i);
        ++group[parent];
        childlen[parent].insert(i);
    }
    // printf("ok\n");
    ll ans = 0;
    rep(i, N){
        ll parent = DS.findSet(i);
        // cout <<"i=" << i << ", parent=" << parent <<endl;
        ll union_size = group[parent];
        ll this_ans = 0;
        for(auto _friend:friends[i]){
            this_ans += (ll)(childlen[parent].find(_friend) != childlen[parent].end());
        }

        for(auto _block:blocks[i]){
            this_ans += (ll)(childlen[parent].find(_block) != childlen[parent].end());
        }

        if(i!=N-1){
            printf("%lld ", union_size-this_ans-1);

        }else{
            printf("%lld",  union_size-this_ans-1);
        }
    }
    printf("\n");


}

int main(){
    Main();
}