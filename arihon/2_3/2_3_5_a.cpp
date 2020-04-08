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
static const llong max_c = 100000000;
static const int max_x = 10010;
vector<vector<llong>> dp(2, vector<llong>(max_x, max_c));
vector<llong> tank(max_x, 0);

int main(){
    llong X, a, c, d, prev_stop;
    int index, prev_index, N, M, L;
    scanf("%d %d %d %lld", &N, &M, &L, &X);
    for(int i=0;i<N;i++){
        scanf("%lld", &a);
        tank[i] = a;
    }
    dp[0][0] = 1;

    for(int i=1;i<=N;i++){
        a = tank[i-1];
        c = a / (llong)M;
        d = a % (llong)M;
        index = i % 2;
        prev_index = (i+1) % 2;
        // printf("i=%d, c=%lld, d=%lld\n", i, c, d);
        for(llong j=0;j<d;j++){
            prev_stop = M - (d - j);
            dp[index][j] = min(dp[prev_index][j], dp[prev_index][prev_stop]+c+1);
            // printf("prev dp[%lld]=%lld, dp[%lld]=%lld\n", j, dp[prev_index][j], prev_stop, dp[prev_index][prev_stop]);
        }
        for(llong j=d;j<M;j++){
            dp[index][j] = min(dp[prev_index][j], dp[prev_index][j-d]+c);
            // printf("prev dp[%lld]=%lld, dp[%lld-%lld]=%lld\n", j, dp[prev_index][j], j, d, dp[prev_index][j-d]);
        }
    }

    // printf("answer dp[%d][%d]=%lld\n", N%2, L, dp[N%2][L]);
    if(dp[N%2][L] <= X){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

}