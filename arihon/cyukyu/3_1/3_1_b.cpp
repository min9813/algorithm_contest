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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,n) for(ll i=n-1;i>=0;i--)
#define sll(n) scanf("%lld", &n);
typedef long long ll;
static const ll max_n = 100010;
static const ll mod = 2019;
static const ll max_value = 1000000000;
static const ll max_x = max_value * max_value;

vector<ll> A;
vector<ll> B;
ll N, K;


ll get_lower_num(ll V){
    ll num = 0;
    for(ll i=N-1;i>=0;i--){
        ll temp_num = distance(B.begin(), upper_bound(B.begin(), B.end(), V/A[i]));
        num += temp_num;
        if(temp_num>=N){
            num += i * N;
            break;
        }
    }

    return num;
}

int main(){
    // int u, v;
    // bool updated = alse;
    ll u;
    scanf("%lld %lld", &N, &K);
    A.resize(N);
    B.resize(N);
    rep(i, N){
        sll(u);
        A[i] = u;
    }

    rep(i, N){
        sll(u);
        B[i] = u;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll L = -1, R = max_x; 
    // ll idx = 0;
    while(R-L>1){
        ll mid = (R + L)/2;
        ll num = get_lower_num(mid);
        if(num<K){
            L = mid;
        }else{
            R = mid;
        }
        // printf("R=%lld, L=%lld, num=%lld\n", R, L, num);
        // idx ++;
        // if(idx > 100) exit(1);
    }

    printf("%lld\n", R);

    return 0;

}