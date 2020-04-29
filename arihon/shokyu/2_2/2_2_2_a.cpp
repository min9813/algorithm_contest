#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long llong;

vector<pair<llong, llong>> robot;
llong N;

bool cmp_terminate(pair<llong, llong> r1, pair<llong, llong> r2){
    return r1.first + r1.second < r2.first + r2.second;
}

int main(){
    scanf("%lld", &N);
    robot.resize(N);
    llong x, l;
    for(int i=0;i<N;i++){
        scanf("%lld %lld", &x, &l);
        robot[i] = make_pair(x, l);
    }
    sort(robot.begin(), robot.end(), cmp_terminate);

    llong now_t = -10000000000;
    llong num = 0;
    for(int i=0;i<N;i++){
        if(now_t <= robot[i].first - robot[i].second){
            now_t = robot[i].first + robot[i].second;
            num += 1;
        }else{
            continue;
        }
    }

    printf("%lld\n", num);

    return 0;

}