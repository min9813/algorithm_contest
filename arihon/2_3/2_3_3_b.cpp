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
static const int max_num = 1001;
static const int max_hp = 10010;
static const int max_b = 200000000;
vector<pair<int, int>> magic(max_num);
vector<int> dp(2*max_hp, max_b);

int main(){
    int H, N, a, b;
    scanf("%d %d", &H, &N);
    // printf("max b = %d", max_b);
    int max_magic = 0;
    for(int i=0;i<N;i++){
        scanf("%d %d", &a, &b);
        magic[i] = make_pair(a,b);
        max_magic = max(max_magic, a);
    }
    dp[0] = 0;

    for(int j=1;j<=H+max_magic;j++){
            // printf("dp[%d]=%d\n", j, dp[j]);
        for(int i=0;i<N;i++){
            if(j>=magic[i].first){
                dp[j] = min(dp[j], dp[j-magic[i].first]+magic[i].second);
            }
        }
    }



    int ans = max_b;
    for(int j=H;j<=H+max_magic;j++){
        ans = min(dp[j], ans);
    }

    printf("%d\n", ans);
    return 0;

}
