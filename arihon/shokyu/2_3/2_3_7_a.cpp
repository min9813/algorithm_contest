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
static const int max_n = 110;
static const int max_s = 20010;
static const int mod = 1000000007;
// static const int max_v = 10000000;
// vector<int> num_array(max_n);
vector<vector<int>> dp(max_n, vector<int>(max_s, 0));

int main(){
    int N, S, K;
    scanf("%d %d %d", &N, &S, &K);

    dp[0][0] = 1;
    // dp[1][0] = 1;/

    for(int i=0;i<N;i++){
        for(int j=0;j<=S;j++){
            // printf("i=%d, j=%d, N-j+1=%d\n", i, j, N-i+1);
            if(j>=(N-i)){
                dp[i][j] = (dp[i][j] + dp[i][j-(N-i)]) % mod;
                // printf("yes, dp[%d][%d]=%d\n", i, j, dp[i][j]);

            }

            if(j>=K*(N-i) && i >= 1){
                dp[i][j] = (dp[i][j] + dp[i-1][j-K*(N-i)]) % mod;
                // printf("no, dp[%d][%d]=%d\n", i, j, dp[i][j]);

            }
        }
    }

    printf("%d\n", dp[N-1][S]);

}