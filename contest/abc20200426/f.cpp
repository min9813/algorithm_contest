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
typedef long long ll;
struct edge{
    ll to;
    ll w;
};
static const ll max_n = 2010;
// static const ll max_abs_value = 1000000010;
// static const ll mod = 998244353;
// vector<vector<ll>>dp(max_n, vector<ll>(max_n, 0));
vector<vector<ll>>dp(max_n, vector<ll>(max_n, 0));
vector<set<ll>> color_list(max_n);
vector<ll> node_colors(max_n);
vector<vector<ll>> edge_list(max_n);
// vector<ll> value_list(max_n);
// int N;
ll N, S;


int main(){
    // int u, v;
    // bool updated = false;
    scanf("%lld", &N);
    // ans = dp[S];

    // printf("%lld\n", ans);


    return 0;

}