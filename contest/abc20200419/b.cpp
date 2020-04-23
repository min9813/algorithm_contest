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
static const int max_n = 10010;
// static const llong max_cost = 2000000000000000;
// // vector<vector<llong>> matrix(max_n, vector<llong>(max_n, 0));
// // vector<vector<llong>> adj_matrix(max_n, vector<llong>(max_n, max_cost));
// vector<vector<pair<llong, int>>> adj_list(max_n);
// vector<llong> distance_table(max_n, max_cost);
// set<pair<llong, int>> points_sort_x;
// set<pair<llong, int>> points_sort_y;
vector<ll> homework_list(max_n);
// int N;



int main(){
    // int u, v;
    // bool updated = false;
    ll N, M, A;
    scanf("%lld %lld\n", &N, &M);
    // printf("%lld\n", total_num);
    ll total_home_work_day = 0;
    for(ll i=0;i<M;i++){
        scanf("%lld", &A);
        homework_list[i] = A;
        total_home_work_day += A;
    }

    if(total_home_work_day>N){
        printf("%lld\n", (ll)-1);
    }else{
        printf("%lld\n", N-total_home_work_day);
    }


    return 0;

}