#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
// #include <prettyprint.hpp>
using namespace std;
typedef long long ll;
struct edge{
    ll to;
    ll w;
};
static const ll max_n = 3010;
// static const ll max_abs_value = 1000000010;
static const ll mod = 998244353;
// vector<vector<ll>>dp(max_n, vector<ll>(max_n, 0));
vector<ll>dp(max_n, 0);
vector<ll> value_list(max_n);
// int N;
ll N, S;

inline ll log3(ll v){
    ll ans = 0;
    v = v / 3;
    while(v>0){
        v = v / 3;
        ans ++;
    }
    return ans;
}

pair<ll, ll> dfs(ll coord){
    ll log_value = log3(coord-1);
    ll left_edge = pow(3, log_value);
    ll right_edge = left_edge + left_edge;
    left_edge = left_edge + 1;

    // printf("------ coords:%lld -------\n", coord);
    // printf("left edge:%lld, right edge:%lld log value:%lld\n", left_edge, right_edge, log_value);
    if(coord > right_edge+1 && log_value>0){
        auto range = dfs(coord - right_edge);
        if(range.first == -1){
            return range;
        }
        left_edge = right_edge + range.first;
        right_edge += range.second;
    }else if(coord==right_edge+1 || coord == 1){
        return make_pair(-1, -1);
    }

    return make_pair(left_edge, right_edge);
}

bool check_ok(ll coords1, ll coords2,pair<ll, ll>range_1, pair<ll, ll> range_2){
    bool is_ok = true;
    if(range_1.first == -1 || range_2.first ==-1){
        is_ok = true;
        return is_ok;
    }

    if(coords1 >= range_2.first && coords1 <= range_2.second){
        is_ok = false;
    }

    if(coords2 >= range_1.first && coords2 <= range_1.second){
        is_ok = false;
    }
    return is_ok;

}

int main(){
    // int u, v;
    // bool updated = false;
    ll ans, Q, a,b,c,d;
    scanf("%lld", &Q);
    for(ll i=0;i<Q;i++){
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        auto x1_range = dfs(a);
        // cout << "x1 range:" << x1_range <<endl;

        auto y1_range = dfs(b);
        // cout << "y1 range:" << y1_range <<endl;

        auto x2_range = dfs(c);
        // cout << "x2 range:" << x2_range <<endl;

        auto y2_range = dfs(d);
        // cout << "y2 range:" << y2_range <<endl;

        ll x_manhattan, y_manhattan;
        if(check_ok(a,c, x1_range, x2_range)){
            // printf("ok! x1=%lld, x2=%lld ",a, c);
            // cout << "x1 range:" << x1_range << " x2 range:" << x2_range <<endl;
            x_manhattan = abs(c - a);
        }else{
            ll edge_dist = min(abs(c-x2_range.first), abs(c-x2_range.second))+1;
            ll edge_dist2 = min(abs(a-x1_range.first), abs(a-x1_range.second))+1;
            edge_dist = min(edge_dist, edge_dist2);
            // printf("ng, edge dist = %lld\n", edge_dist);
            x_manhattan = edge_dist * 2 + abs(c- a);
        }
        if(check_ok(b, d, y1_range, y2_range)){
            // printf("ok! x1=%lld, x2=%lld ",b, d);
            // cout << "y1 range:" << y1_range << " y2 range:" << y2_range <<endl;
            y_manhattan = abs(d - b);
        }else{
            ll edge_dist = min(abs(d-y2_range.first), abs(d-y2_range.second))+1;
            ll edge_dist2 = min(abs(b-y1_range.first), abs(b-y1_range.second))+1;
            edge_dist = min(edge_dist, edge_dist2);
            y_manhattan = edge_dist * 2 + abs(d-b);
        }
        // printf("x dist:%lld, y_dist:%lld\n", x_manhattan, y_manhattan);
        printf("%lld\n", x_manhattan+y_manhattan);
        // value_list[i] = u;


    }


    // printf("%lld\n", ans);


    return 0;

}