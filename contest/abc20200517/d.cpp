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
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 200010;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;
static const ll max_d = 10000000000;


vector<vector<ll>> edge_list(max_n);
vector<pair<ll, ll>> distance_table;

void dijkstra(ll st){
    priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll,ll>>>> PQ;

    fill(distance_table.begin(), distance_table.end(), make_pair(max_d, -1));
    distance_table[st] = make_pair(0, -1);
    for(auto &p:edge_list[st]){
        // distance_table[p.first] = p.second.first;
        PQ.push(make_pair(1, make_pair(p, st)));
    }

    


    while(!PQ.empty()){
        auto u = PQ.top(); PQ.pop();
        // cout << " u  = " << u.first << ", " << u.second.first << "p="<<u.second.second <<endl;
        if(u.first>distance_table[u.second.first].first){
            // cout << "continue, distance table = " << distance_table[u.second.first].first <<endl;
            continue;
        }
        distance_table[u.second.first] = make_pair(u.first, u.second.second);
        for(auto &p:edge_list[u.second.first]){
            // distance_table[p.first] = p.second.first;
            ll new_cost = 1 + u.first;
            if(new_cost < distance_table[p].first){
                // cout << "push to queue, new cost = " << new_cost << " p=" << p <<endl;
                distance_table[p] = make_pair(new_cost, u.second.first);
                PQ.push(make_pair(new_cost, make_pair(p, u.second.first)));
            }

        }

        
    }



}

void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, M, a, b;
    sll(N);
    sll(M);
    distance_table.resize(N);
    rep(i,M){
        sll(a);
        sll(b);
        -- a;
        -- b;
        edge_list[a].emplace_back(b);
        edge_list[b].emplace_back(a);
    }

    dijkstra(0);
    
    bool is_ok = true;
    rep(i,N){
        if(distance_table[i].first == max_d){
            is_ok = false;
            break;
        }
    }

    if(is_ok){
        printf("Yes\n");
        for(ll i=1;i<N;i++){
            printf("%lld\n", distance_table[i].second+1);
        }
    }else{
        printf("No\n");
    }
    // cout << junkan<<endl;

    // ll index = (K % junkan.size());
    // printf("%lld\n", junkan[index]+1);
    

    // printf("%lld\n", ans);


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}