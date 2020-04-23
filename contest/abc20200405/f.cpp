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
llong N;

vector<llong> search_division(llong n){
    vector<llong> divisions;
    llong num = 1;
    llong i = 2;
    while(i*i < n){
        if(n % i == 0){
            divisions.push_back(i);
            divisions.push_back(n/i);
        }
        i ++;
    }

    if(i*i == n){
        divisions.push_back(i);
    }
    sort(divisions.begin(), divisions.end());

    return divisions;
}

llong search_division_num(llong n){
    vector<llong> divisions;
    llong num = 1;
    llong i = 2;
    while(i*i < n){
        if(n % i == 0){
            num += 2;
        }
        i++;
    }
    // for(i=2;i*i<n;i++){
    //     if(n%i==0){
    //         num += 2;
    //     }
    // }

    if(i*i == n){
        // divisions.push_back(i);
        num ++;
    }
    // sort(divisions.begin(), divisions.end());

    return num;
}

llong search_division_res(llong n){
    llong num = 1;
    llong i = 2;
    while(i*i < n){
        // printf("i=%lld, i*i=%lld\n", i, i*i);
        if(n % i == 0){
            llong m = n;
            while(m % i == 0){
                m = m / i;
            }
            if(m % i == 1) num ++;
        }
        i ++;
    }

    if(i*i == n){
        num ++;
    }


    return num;
}



int main(){
    // int u, v;
    // bool updated = false;
    llong ans;
    scanf("%lld", &N);

    // ans = search_division(N-1).size();
    if(N==2){
        printf("%d\n", 1);
    }else{
        ans = search_division_num(N-1);
        // printf("N-1 = %lld\n", ans);
        ans += search_division_res(N);

        printf("%lld\n", ans);
    }



    // double limit = 1. / (double)(4 * M);



    return 0;

}