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
#include <iomanip>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 100010;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;



void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, a;
    map<ll, ll> data;
    sll(N);
    ll ans = 0;
    rep(i, N){
        sll(a);
        ll input = a + i + 1;
        ll query = i + 1 - a;
        data[input] ++;
        if(data.find(query) != data.end()){
            ans += data[query];
        }
    }

    printf("%lld\n", ans);


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}