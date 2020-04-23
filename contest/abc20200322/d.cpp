#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
static const ll max_n = 200010;
// static const ll max_dist = 10000000;
// vector<vector<ll>> distance_table(max_n, vector<ll>(max_n, max_dist));
// vector<ll> distance_list(max_n);
vector<ll> combination_table(max_n, 0);
vector<ll> value_num(max_n, 0);
vector<ll> combination_minus1_table(max_n, 0);
vector<ll> balls(max_n);

ll N, X, Y;

int main(){
    // int u, v;
    // bool updated = alse;
    scanf("%lld", &N);
    for(ll i=0;i<N;i++){
        scanf("%lld", &X);
        balls[i] = X;
        value_num[X] ++;
    }
    // printf("ok!\n");

    ll sum_comb = 0;
    for(ll i=1;i<=N;i++){
        if(value_num[i]>1){
            ll comb = value_num[i] * (value_num[i] - 1) / 2;
            sum_comb += comb;
            combination_table[i] = comb;
            comb = (value_num[i] - 2) * (value_num[i] - 1) / 2;
            combination_minus1_table[i] = comb;
        }
    }

    for(ll i=0;i<N;i++){
        ll value = balls[i];
        ll ans = (sum_comb - combination_table[value] + combination_minus1_table[value]);
        printf("%lld\n", ans);
    }
    return 0;

}