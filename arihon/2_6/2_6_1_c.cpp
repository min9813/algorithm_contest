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


ll get_length(ll min_x, ll max_x){
    // printf("---- x_min=%lld, x_max=%lld ", min_x, max_x);
    ll length;
    if(min_x == 0){
        length = - max_x;
    }else{
        length = 2 * min_x * (max_x / min_x);
        // printf("mid length = %lld \n", length);
        length += get_length(max_x % min_x, min_x);
    }
    // printf("after length = %lld ----- \n", length);

    return length;
}

int main(){
    ll N, X, a, b;
    scanf("%lld %lld", &N, &X);
    a = min(X, N - X);
    b = N - a;
    ll ans = get_length(a, b) + N;
    printf("%lld\n", ans);
}