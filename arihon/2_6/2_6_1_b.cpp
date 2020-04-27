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
static const ll max_n = 110;
vector<ll> clocks(max_n);

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    g = b / g;
    return a * g;
}

int main(){
    ll N, t;
    scanf("%lld", &N);
    ll lcm_num = 1;
    for(ll i=0;i<N;i++){
        scanf("%lld", &t);
        clocks[i] = t;
        lcm_num = lcm(lcm_num, t);
        
    }
    ll ans = lcm_num;
    printf("%lld\n", ans);
}