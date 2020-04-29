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
static const llong MAX_N = 2010;
static const llong MAX_WIN = 2000000000;
vector<llong> game_num(MAX_N);
vector<vector<llong>> dp(MAX_N, vector<llong>(MAX_N, MAX_WIN));

int main(){

    llong N, a, K, minimum_win, sum_game_num=0;
    double win_rate, raw_minimum_win_num, decimal_part;

    scanf("%lld %lld", &N, &K);

    for(int i=0;i<N;i++){
        scanf("%lld", &a);
        game_num[i] = a;
        sum_game_num += a;
    //     dp[i][0] = 0;
    }
    if(sum_game_num == K){
        printf("1\n");
    }else{
        sum_game_num = 0;
    // dp[N][0] = 0;
        dp[0][0] = 0;

        for(int i=1;i<=N;i++){
            a = game_num[i-1];
            for(int j=1;j<=i;j++){
                // printf("i=%d, j=%d\n", i, j);
                // printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
                // printf("dp[%d][%d]=%lld\n", i-1, j, dp[i-1][j]);
                // printf("dp[%d][%d]=%lld\n", i-1, j-1, dp[i-1][j-1]);
                if(sum_game_num>0){
                    win_rate = (double)dp[i-1][j-1] / (double)sum_game_num;
                    raw_minimum_win_num = win_rate * (double)(sum_game_num + a);
                    decimal_part = raw_minimum_win_num - floor(raw_minimum_win_num);
                    if(decimal_part == 0){
                        minimum_win = (llong)raw_minimum_win_num + 1;
                    }else{
                        minimum_win = ceil(raw_minimum_win_num);
                    }
                    // printf("decimal:%f, win rate:%f, sum_game:%lld, a:%lld", decimal_part, win_rate, sum_game_num, a);
                    // printf("minimum win:%lld raw:%f\n", minimum_win, raw_minimum_win_num);
                    dp[i][j] = min(dp[i-1][j], minimum_win);
                }else{
                    dp[i][j] = 1;
                }

                // printf("## after dp[%d][%d]: %lld\n", i, j, dp[i][j]);
            }
            sum_game_num += a;
        }

        int ans = 0;
        for(int i=1;i<=N;i++){
            // printf("dp[N][%d]=%lld\n", i, dp[N][i]);
            if(dp[N][i]<=K){
                ans = i;
            }
        }

        printf("%d\n", ans);
    }
    
    return 0;

}
