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
// static const int max_n = 110;
// static const llong max_cost = 2000000000000000;
// // vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
// // vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
// vector<vector<pair<llong, int>>> adj_list(max_n);
// vector<llong> distance_table(max_n, max_cost);
// set<pair<llong, int>> points_sort_x;
// set<pair<llong, int>> points_sort_y;

// int N;



int main(){
    // int u, v;
    // bool updated = false;
    ll N, M, cost, total_num;
    scanf("%lld", &N);
    string n_s = to_string(N);
    bool is_ok = false;
    for(int i=0;i<3;i++){
        if(n_s[i] == '7'){
            is_ok = true;
        }
    }

    if(is_ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }


    return 0;

}