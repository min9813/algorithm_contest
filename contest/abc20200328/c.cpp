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
// static const ll max_n = 200010;



int main(){
    // int u, v;
    // bool updated = false;
    ll N, K, cost, total_num;
    scanf("%lld %lld", &K, &N);
    vector<ll> house(N, 0);
    for(ll i=0;i<N;i++){
        scanf("%lld", &house[i]);
    }
    sort(house.begin(), house.end());
    ll max_diff = 0;
    for(ll i=0;i<N-1;i++){
        max_diff = max(house[i+1]-house[i], max_diff);
    }
    max_diff = max(house[0] + K - house[N-1], max_diff);

    printf("%lld\n", K - max_diff);


    return 0;

}