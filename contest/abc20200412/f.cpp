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
static const llong max_n = 200010;
static const llong max_abs_value = 1000000010;
vector<llong> seq(max_n);
vector<llong> diff_seq(max_n);
vector<llong> cum_diff_seq(max_n);
vector<vector<llong>> dp(max_n, vector<llong>(3, 0));
// vector<llong> dp(max_n, 0);
// vector<vector<llong>> dp(max_n, vector<llong>(10, 0));
// static const int max_n = 110;
// static const llong max_cost = 2000000000000000;
// // vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
// // vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
// vector<vector<pair<llong, int>>> adj_list(max_n);
// vector<llong> distance_table(max_n, max_cost);
// set<pair<llong, int>> points_sort_x;
// set<pair<llong, int>> points_sort_y;

// int N;
llong N;


int main(){
    // int u, v;
    // bool updated = false;
    llong ans = 0, value;
    scanf("%lld", &N);
    for(llong i=0;i<N;i++){
        scanf("%lld", &seq[i]);
    }

    dp[0][2] = seq[0];
    dp[1][1] = max(seq[0], seq[1]);
    dp[1][2] = max(seq[0], seq[1]);
    for(llong i=2;i<N;i++){
        // printf("--------------\n");
        for(int j=0;j<3;j++){
            // printf("dp[%lld][%d]=%lld\n", i-1, j, dp[i-1][j]);
        }
        if((i+1)%2==1){
            dp[i][0] = max(dp[i-2][0]+seq[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-2][1]+seq[i], dp[i-1][1]);
            dp[i][2] = dp[i-2][2] + seq[i];
        }else{
            dp[i][0] = max(dp[i-2][0]+seq[i], dp[i-1][1]);
            dp[i][1] = max(dp[i-2][1]+seq[i], dp[i-1][2]);
            dp[i][2] = dp[i][1];
        }
    }

    printf("%lld\n", dp[N-1][1]);
    // printf("ok input\n");



    // double limit = 1. / (double)(4 * M);



    return 0;

}