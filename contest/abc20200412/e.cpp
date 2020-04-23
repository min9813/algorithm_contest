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
static const llong max_n = 100010;
static const llong mod = 1000000007;
vector<llong> result(max_n);

// template<typename T>
// void print_vec(vector<pair<llong, llong> vec){
//     cout << "[";
//     for(int i=0;i<vec.size();i++){
//         cout << vec[i] << " ";
//     }
//     cout << "]\n"
// }

inline llong power_mod(llong n, llong k){
    if(k > 1 && n > 1){
        llong ans = n;
        llong power_num = 1;
        vector<llong> power_result(k, 1);
        power_result[0] = ans;
        while(power_num * power_num <= k){
            
            ans = ans * ans;
            ans = (ans % mod);


            power_num = power_num * 2;
            power_result[power_num-1] = ans;

        }
        llong now_power_num = power_num;
        // printf("k=%lld, power num = %lld\n", k, now_power_num);

        while(power_num < k){
            // printf("%lld")
            // printf("now power num = %lld\n", now_power_num);
            now_power_num = now_power_num / 2;
            // printf("after now power num = %lld\n", now_power_num);
            llong num_times = (k - power_num) / now_power_num;
            for(llong i=0;i<num_times;i++){
                ans = ans * power_result[now_power_num-1];
                ans = (ans % mod);
            }

            power_num += now_power_num * num_times;
        }

        return ans;

        

    }else{
        return n;
    }

}


int main(){
    // int u, v;
    llong N, K;
    // bool updated = false;
    llong ans = 0;
    scanf("%lld %lld", &N, &K);

    for(llong i=K;i>=1;i--){
        llong all_num = power_mod(K/i, N);
        // printf("power all num of i=%lld: %lld\n", i, all_num);
        for(llong j=2;j<=K/i;j++){
            all_num = (all_num - result[i*j-1] + mod) % mod;
            // if(n_all_num < 0){
            //     printf("all num = %lld, r = %lld, i=%lld, j=%lld\n", all_num, result[i*j-1], i, j);
            //     exit(0);
            // }
            // all_num = n_all_num;
        }
        result[i-1] = all_num;
        // if(all_num < 0){
        //     printf("all num = %lld\n", all_num);
        //     exit(0);
        // }
        ans = ans + ((all_num * i) % mod);
        ans = (ans % mod);
    }

    printf("%lld\n", ans);
    // double limit = 1. / (double)(4 * M);



    return 0;

}