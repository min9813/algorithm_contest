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
typedef long long ll;


ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    ll N, K, A;
    scanf("%lld %lld", &N, &K);
    ll min_gcd = -1;
    ll max_v = 0;
    for(ll i=0;i<N;i++){
        scanf("%lld", &A);
        max_v = max(max_v, A);
        if(min_gcd==-1){
            min_gcd = A;
        }else{
            min_gcd = gcd(min_gcd, A);
        }
    }
    if(K % min_gcd == 0 && max_v >= K){
        printf("POSSIBLE\n");
    }else{
        printf("IMPOSSIBLE\n");

    }

    return 0;
}