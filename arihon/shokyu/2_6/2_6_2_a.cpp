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

void extgcd(ll a, ll b, ll &x, ll &y){
    if(b==0){
        x = 1, y = 0;
    }else{
        extgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

int main(){
    ll a, b, x, y;
    scanf("%lld %lld", &a, &b);
    extgcd(a, b, x, y);
    printf("%lld %lld\n", x, y);
}