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
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,n) for(ll i=n-1;i>=0;i--)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 10010;
static const ll mod = 2019;
static const ll max_value = 100000000000100;
// static const ll max_x = max_value * max_value;
struct Edge{
    ll from, to;
    double cost, time;
};

struct Edge2{
    ll from, to;
    lf v;

    bool operator < (const Edge2 &e2) const {
        return this->v < e2.v;
    }

    bool operator > (const Edge2 &e2) const {
        return this->v > e2.v;
    }

};


class DisjointSet{
    public:
        vector<ll> rank, p;

        DisjointSet(){}
        DisjointSet(ll size){
            rank.resize(size, 0);
            p.resize(size, 0);
            for(ll i=0;i<size;i++){
                makeSet(i);
            }
        }

        void makeSet(ll x){
            p[x] = x;
            rank[x] = 0;
        }

        bool same(ll x, ll y){
            return findSet(x) == findSet(y);
        }

        void unite(ll x, ll y){
            link(findSet(x), findSet(y));
        }

        void link(ll x, ll y){
            if(rank[x]>rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y] ++;
                }
            }
        }

        ll findSet(ll x){
            if(x!=p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};


vector<Edge> edge_list(max_n);
// vector<vector<Edge2>> edge2_list(max_n);
// vector<Edge2> edge2_list(max_n);
vector<lf> distance_list;
// vector<ll> S(max_n);
// vector<pair<ll, ll>> times_vec(max_n);
ll N, M;

bool is_ok(lf V){
    lf total_v = 0;
    // vector<bool> ok_towns(N, false);
    DisjointSet DS(N);
    set<Edge2> edge2_set;
    rep(i, M){
        Edge v = edge_list[i];
        lf value = v.cost - V*v.time;
        if(value <= 0){
            // printf("value [%lld] = %lf >= 0, time[%lld], cost[%lld] = (%lf %lf)\n", i, value, i, i, v.time, v.cost);
            total_v += value;
            DS.unite(v.from, v.to);
        }else{
            // printf("value [%lld] = %lf < 0\n", i, value);
            edge2_set.insert(Edge2{v.from, v.to, value});
        }

    }

    ll st = 0;
    // priority_queue<Edge2> PQ;
    for(auto v:edge2_set){
        if(DS.same(v.from, v.to)) {
            // cout << v.from<< "  " << v.to<<" same" <<endl;
            continue;
        }
        total_v += v.v;
        DS.unite(v.from, v.to);
    }

    return total_v <= 0;    
}


int main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll a, b;
    lf c, t;
    sll(N);
    sll(M);
    rep(i, M){
        sll(a);
        sll(b);
        // a--;
        // b--;
        slf(c);
        slf(t);
        edge_list[i] = Edge{a,b,c, t};
    }

    lf L = 0;
    lf R = 1000100;

    rep(i, 100){
        lf mid = (L+R) * 0.5;
        bool ok = is_ok(mid);
        // printf("--- mid = %lf ---\n", mid);
        // cout << ok << endl;
        if(ok){
            R = mid;
        }else{
            L = mid;
        }
    }

    cout<<fixed<<setprecision(10)<<R<<endl;
    return 0;

}

// ll main(){
//     Main();

//     return 0;

// }