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
    ll N, M, K, a, b;
    sll(N);
    sll(M);
    sll(K);
    DisjointSet ds(N);
    map<ll, set<ll>> friends;
    map<ll, set<ll>> blocks;
    rep(i, M){
        sll(a);
        sll(b);
        -- a;
        -- b;
        ds.unite(a, b);
        friends[a].insert(b);
        friends[b].insert(a);
    }
    rep(i, K){
        sll(a);
        sll(b);
        -- a;
        -- b;
        blocks[a].insert(b);
        blocks[b].insert(a);
    }

    set<ll> ok;
    map<ll, set<ll>> groups;
    rep(i, N){
        ll parent = ds.findSet(i);
        groups[parent].insert(i);
    }

    map<ll,ll> ans;

    for(auto p:groups){
        // ll t_size = p.second.size() * (p.second.size() - 1) / 2;

        for(auto c:p.second){
            ll friend_num = 0;
            ll block_num = 0;
            for(auto c2:friends[c]){
                friend_num += p.second.find(c2) != p.second.end();
            }
            for(auto c2:blocks[c]){
                block_num += p.second.find(c2) != p.second.end();
            }
            ans[c] = p.second.size() - (friend_num + block_num) - 1;
        }
    }

    rep(i, N){
        printf("%lld", ans[i]);
        if(i< N-1){
            printf(" ");
        }
    }
    printf("\n");


}

int main(){
    Main();
}