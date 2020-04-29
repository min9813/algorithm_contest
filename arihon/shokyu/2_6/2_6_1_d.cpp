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
    ll N, M, K;
    scanf("%lld %lld %lld", &N, &M, &K);

    vector<pair<ll, ll>> points;
    for(ll i=0;i<=N;i++){
        for(ll j=0;j<=M;j++){
            points.emplace_back(i, j);
        }
    }

    ll size = (ll)points.size();

    ll ans = 0;
    for(ll i=0;i<size;i++){
        auto point1 = points[i];
        for(ll j=0;j<i;j++){
            auto point2 = points[j];
            // cout << "1:" << point1 << "2:"<<point2<<endl;
            ll num;
            if(point1.first == point2.first){
                num = abs(point2.second - point1.second);
            }else if(point1.second == point2.second){
                num = abs(point1.first - point2.first);
            }else{
                num = gcd(abs(point1.first-point2.first), abs(point1.second - point2.second));
            }
            
            // cout << "########## num = " <<num << endl;
            ans += (ll)(num == K - 1);
            // if(num == K - 1){
                // cout << "1:" << point1 << "2:"<<point2<<endl;
            // }
        }
    }
    printf("%lld\n", ans);

}