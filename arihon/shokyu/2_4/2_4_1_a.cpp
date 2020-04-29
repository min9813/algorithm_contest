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
static const llong max_n = 10010;
priority_queue<pair<llong, llong>, std::vector<pair<llong, llong>>, std::greater<pair<llong, llong>>> Q;


int main(){
    llong N, K, a ,b;
    scanf("%lld %lld", &N, &K);
    for(int i=0;i<N;i++){
        scanf("%lld %lld", &a, &b);
        Q.push(make_pair(a, b));
    }

    llong ans = 0;
    for(int i=1;i<=K;i++){
        auto machine = Q.top(); Q.pop();
        ans += machine.first;
        machine.first += machine.second;
        Q.push(machine);
    }

    printf("%lld\n", ans);


}