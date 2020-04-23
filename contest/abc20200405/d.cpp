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
static const llong max_n = 30;
vector<vector<llong>> dp(max_n, vector<llong>(10, 0));
// static const int max_n = 110;
// static const llong max_cost = 2000000000000000;
// // vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
// // vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
// vector<vector<pair<llong, int>>> adj_list(max_n);
// vector<llong> distance_table(max_n, max_cost);
// set<pair<llong, int>> points_sort_x;
// set<pair<llong, int>> points_sort_y;

// int N;
llong K;

llong dfs(int digit, int last_digit, llong now_num){
    // printf("dfs digit=%d, last_digit=%d, now_num=%lld\n", digit, last_digit, now_num);
    llong upper_value = last_digit * pow(10, digit);
    llong next_digit = -1;

    if(digit==1){
        bool is_break = false;
        for(int i=last_digit+1;i>=last_digit-1;i--){
            if(i<0||i>=10) continue;
            if(now_num == K){
                // now_num = now_num + dp[digit-1][i];
                next_digit = i;
                is_break = true;
                break;
            }
            now_num = now_num - dp[digit-1][i];

        }
        if(now_num == K && !is_break){
            // now_num = now_num + dp[digit-1][i];
            next_digit = last_digit - 1;
        }
        return upper_value + next_digit * pow(10, digit-1);

    }else{
        for(int i=last_digit+1;i>=last_digit-1;i--){
            if(i<0||i>=10) continue;
            now_num = now_num - dp[digit-1][i];
            if(now_num < K){
                now_num = now_num + dp[digit-1][i];
                next_digit = i;
                break;
            }else if(now_num==K){
                next_digit = i - 1;
            }
        }
        upper_value = upper_value + dfs(digit-1, next_digit, now_num);
        return upper_value;
    }

    // printf("before add upper value:%lld", upper_value);

}


int main(){
    // int u, v;
    // bool updated = false;
    llong last_digit, now_num = 0;
    scanf("%lld", &K);
    int now_digit = 0;
    dp[now_digit][0] = 1;
    for(int i=1;i<10;i++){
        dp[now_digit][i] = 1;
        now_num += 1;
        if(now_num>=K){
            last_digit = i;
            break;
        }
    }

    if(now_num >= K){
        printf("%lld\n", last_digit);
    }else{
        while(now_num < K){
            now_digit ++;
            // printf("now digit=%d\n", now_digit);
            dp[now_digit][0] = dp[now_digit-1][1] + dp[now_digit-1][0];
            for(int i=1;i<9;i++){
                // printf("i=%d, dp=%lld %lld %lld\n", i, dp[now_digit-1][i-1], dp[now_digit-1][i], dp[now_digit-1][i+1]);
                dp[now_digit][i] = dp[now_digit-1][i-1] + dp[now_digit-1][i] + dp[now_digit-1][i+1];
                // printf("now num = %lld \n", now_num);
                now_num += dp[now_digit][i];
                // printf("after add now num = %lld \n", now_num);

                if(now_num >= K){
                    last_digit = i;
                    break;
                }
            }
            if(now_num >= K){
                break;
            }
            dp[now_digit][9] = dp[now_digit-1][9] + dp[now_digit-1][8];
            now_num += dp[now_digit][9];
            if(now_num >= K){
                last_digit = 9;
                break;
            }
        }
        llong ans = dfs(now_digit, last_digit, now_num);
        printf("%lld\n", ans);
    }


    // double limit = 1. / (double)(4 * M);



    return 0;

}