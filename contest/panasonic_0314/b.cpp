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
    ll H, W, low_h, high_h, low_w, high_w;
    cin >> H >> W;

    if(H%2==0){
        low_h = H /2;
        high_h = H /2;
    }else{
        low_h = (H - 1) / 2;
        high_h = (H + 1)/2;
    }

    if(W % 2 == 0){
        low_w = W / 2;
        high_w = W / 2;
    }else{
        low_w = (W - 1) / 2;
        high_w = (W + 1)/ 2;
    }

    ll ans = low_w * low_h + high_w * high_h;
    if(H==1){
        ans = 1;
    }
    if(W==1){
        ans = 1;
    }
    printf("%lld\n", ans);


    return 0;

}