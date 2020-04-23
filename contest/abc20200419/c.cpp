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
// static const ll max_n = 200010;



int main(){
    // int u, v;
    // bool updated = false;
    map<ll, ll> j_dict;
    ll N, A;
    scanf("%lld", &N);

    for(ll i=0;i<N-1;i++){
        scanf("%lld", &A);
        if(j_dict.find(A)==j_dict.end()){
            // printf("not found %lld\n", A);
            j_dict[A] = 1;
        }else{
            j_dict[A] += 1;
        }
    }

    for(ll i=1;i<=N;i++){
        if(j_dict.find(i)==j_dict.end()){
            printf("0\n");
        }else{
            printf("%lld\n", j_dict[i]);
        }
    }

    return 0;

}