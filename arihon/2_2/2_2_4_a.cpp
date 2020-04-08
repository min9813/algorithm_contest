#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

typedef long long llong;
llong st, ed, now;
int idx;

int main(){
    scanf("%lld %lld", &st, &ed);

    now = st;
    idx = 0;
    while(now <= ed){
        now = now * 2;
        idx += 1;
    }

    printf("%d\n", idx);
}