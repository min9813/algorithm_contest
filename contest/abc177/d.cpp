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
    ll N, M, a, b;
    cin >> N >> M;

    DisjointSet ds(N);
    rep(i, M){
        cin >> a >> b;
        -- a; -- b;
        ds.unite(a, b);
    }

    map<ll, ll> counter;

    rep(i, N){
        ll p = ds.findSet(i);
        counter[p] ++;
    }

    ll ans = 0;
    for(auto p:counter){
        ans = max(ans, p.second);
    }

    cout << ans <<endl;

}

int main(){
    Main();
}