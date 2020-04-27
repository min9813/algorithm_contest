#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if(b!=0){
        d = extgcd(b, a%b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1, y = 0;
    }
    return d;
}

vector<ll> get_factor(ll value){
    vector<ll> ans;
    ll i;
    for(i=1;i*i<value;i++){
        if(value % i ==0){
            ans.emplace_back(i);
            ans.emplace_back(value / i);
        }
    }
    // printf("i=%lld , v = %lld\n", i, value);
    if(value % i==0){
        ans.emplace_back(i);
    }
    return ans;
}


int main(){
    ll N, a, b, c, gcd_num;
    scanf("%lld", &N);
    if(N == 2){
        scanf("%lld %lld", &a, &b);
        gcd_num = gcd(a, b);
    }else{
        scanf("%lld %lld %lld", &a, &b, &c);
        gcd_num = gcd(gcd(a, b), gcd(a, c));
    }
    // printf("gcd = %lld\n", gcd_num);
    vector<ll> factors = get_factor(gcd_num);
    sort(factors.begin(), factors.end());

    for(auto &f:factors){
        printf("%lld\n", f);
    }
    return 0;
}