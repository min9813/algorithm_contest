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
static const ll max_h = 12;
static const ll max_w = 1010;
static const ll max_value = -10000000000;
static const ll max_num = 2010;
// static const ll mod = 1000000007;
// vector<vector<ll>> F(max_h, vector<ll>(max_w, 0));
vector<pair<ll, ll>> infant_list(max_num);
vector<vector<ll>> dp(max_num, vector<ll>(max_num, 0));
ll ans = 0;
ll N;


int main(){
    // int u, v;
    // bool updated = false;
    // ll ans = 0;
    ll A;
    scanf("%lld", &N);
    for(ll i=0;i<N;i++){
        scanf("%lld", &A);
        infant_list[i] = make_pair(i+1, A);
    }

    sort(
        infant_list.begin(), 
        infant_list.begin()+N,
        [](const pair<ll,ll>& x, const pair<ll,ll>& y){return x.second > y.second;}
    );

    dp[0][0] = 0;
    for(ll i=1;i<=N;i++){
        for(ll x=0;x<=i;x++){
            ll y = i - x;
            pair<ll, ll> last_infant = infant_list[i-1];
            ll value_add_to_y = max_value, value_add_to_x = max_value;
            if(y>0){
                value_add_to_y = last_infant.second * (N-y+1 - last_infant.first) + dp[x][y-1];
            }
            if(x > 0){
                value_add_to_x = last_infant.second * (last_infant.first - x) + dp[x-1][y];
            }
            // cout << last_infant <<"N-y+1=" << N-y+1<< endl;
            // printf("x+y = %lld, x=%lld, y=%lld, value y=%lld, value x = %lld\n", i, x, y, value_add_to_y, value_add_to_x);
            dp[x][y] = max(value_add_to_x, value_add_to_y);
        }
    }

    ll ans = max_value;
    for(ll i=0;i<=N;i++){
        ans = max(dp[i][N-i], ans);
    }
    printf("%lld\n", ans);
    
    // double limit = 1. / (double)(4 * M);



    return 0;

}