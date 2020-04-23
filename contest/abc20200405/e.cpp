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
typedef long long llong;
// static const llong max_n = 200010;
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
llong N, K, C;
string S;
vector<llong> ok_days_ordered;
vector<llong> ok_days_reverse;

// template<typename T>
// void print_vec(vector<pair<llong, llong> vec){
//     cout << "[";
//     for(int i=0;i<vec.size();i++){
//         cout << vec[i] << " ";
//     }
//     cout << "]\n"
// }


int main(){
    // int u, v;
    // bool updated = false;
    llong no_work_day=0;
    scanf("%lld %lld %lld", &N, &K, &C);
    cin >> S;
    llong i = 0;
    while(i<N && ok_days_ordered.size() < K){
        if(S[i]=='x'){
            i ++;
            continue;
        } 
        if(S[i]=='o'  && no_work_day == 0){
            ok_days_ordered.push_back(i);
            i = i + C + 1;
        }
    }

    // print_vec(ok_days_ordered);
    // cout << ok_days_ordered <<"\n";
    i = N-1;

    while(i>=0 && ok_days_reverse.size() < K){
        if(S[i]=='x'){
            i --;
            continue;
        } 
        if(S[i]=='o'){
            ok_days_reverse.push_back(i);
            i = i - C - 1;
        }
    }
    // cout << ok_days_reverse <<"\n";


    llong j = 0;
    vector<llong> ans;
    for(i=K-1;i>=0;i--){
        j = K - 1 - i;
        // cout << "ordered i = " << i << " " << ok_days_ordered[i] << "\n";
        // cout << "ordered j = " << j << " " << ok_days_reverse[j] << "\n";
        if(ok_days_ordered[i] == ok_days_reverse[j]){
            ans.push_back(ok_days_ordered[i]);
        }

    }

    if(ans.size()>0){
        for(int k=ans.size()-1;k>=0;k--){
            printf("%lld\n", ans[k]+1);
        }
    }else{
        printf("\n");
    }

        



    // double limit = 1. / (double)(4 * M);



    return 0;

}