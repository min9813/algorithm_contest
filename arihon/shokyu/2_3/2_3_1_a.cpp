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
static const int max_score = 10001;
static const int max_n = 100;

vector<vector<int>> dp(max_n+1, vector<int>(max_score, 0));
vector<int> ps(max_n, 0);

int main(){
    int N, s, max_s=0;

    scanf("%d", &N);
    for(int i=0;i<N+1;i++){
        dp[i][0] = 1;
    }
    for(int i=0;i<N;i++){
        scanf("%d", &s);
        ps[i] = s;
        max_s += s;
    }
    // printf("N=%d, max_s=%d", N, max_s);

    for(int i=0;i<N;i++){
        int new_w = ps[i];
        for(int j=1;j<=max_s;j++){
            // printf("dp[%d][%d]=%d\n", i, j ,dp[i][j]);
            if(j-new_w>=0){
                if(dp[i][j-new_w]>=1){
                    dp[i+1][j] = 1;
                }
            }
            if(dp[i][j]>=1){
                dp[i+1][j] = 1;
            }
            // printf("next dp[%d][%d]=%d\n", i+1, j ,dp[i+1][j]);

        }
    }
    int ans = 0;
    for(int j=0;j<=max_s;j++){
        ans += dp[N][j];
    }

    printf("%d\n", ans);

    return 0;
}