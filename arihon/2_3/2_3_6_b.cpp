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
static const int max_n = 100010;
static const int max_v = 10000000;
vector<int> num_array(max_n);
vector<int> dp(max_n, max_v);

int main(){
    int N, a;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &a);
        num_array[i] = a;
    }

    for(int i=0;i<N;i++){
        *lower_bound(dp.begin(), dp.end(), num_array[i]) = num_array[i];
    }

    auto num_lis = lower_bound(dp.begin(), dp.end(), N+1) - dp.begin();
    printf("%ld\n", N - num_lis);



}