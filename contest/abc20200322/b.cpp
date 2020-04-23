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
    string S;
    cin >> S;
    ll size = (ll)S.size();
    bool is_ok = true;
    for(ll idx=0;idx<size/2+1;idx++){
        // printf("idx = %lld, size - idx - 1 = %lld (size-1)/2 - idx - 1 = %lld\n", idx, size-idx-1, (size-1)/2-idx-1);
        // cout << S[idx] << ", " << S[size-idx-1] <<"," <<S[(size-1)/2-idx-1]<< endl;
        if(S[idx] != S[size-idx-1]){
            is_ok = false;
            break;
        }
        if((size-1)/2-idx-1>=0){
            // printf("hikaku!\n");
            if(S[idx] != S[(size-1)/2-idx-1]){
                is_ok = false;
                break;
            }
        }
    }
    if(is_ok){
        for(ll idx=(size+3)/2-1;idx<size;idx++){
            ll back_idx = idx - ((size+3)/2-1);
            // printf("idx=%lld, back idx=%lld\n", idx, back_idx);
            if(S[idx]!=S[size - back_idx -1]){
                is_ok = false;
                break;
            }
        }
    }
    if(is_ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;

    }

    // printf("%lld\n", total_num);


    return 0;

}