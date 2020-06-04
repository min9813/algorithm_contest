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
static const ll mod = 2019;
static const ll max_value = 100000000000100;
// vector<vector<vector<ll>>> dp(max_n, vector<vector<ll>>(max_n, vector<ll>(max_n*max_n, 0)));
// static const ll max_x = max_value * max_value;
vector<ll> A(max_n);
// vector<ll> cards(max_n);
// vector<ll> S(max_n);
// vector<pair<ll, ll>> times_vec(max_n);
ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, a, S;
    map<ll,ll> counter;
    sll(N);
    rep(i,N){
        sll(a);
        A[i] = a;
    }

    ll r = 0, l = 0;
    ll length = 0;
    for(;;){
        // printf("l=%lld, r=%lld, counter[A[l](=%lld)]=%lld, counter[A[r](=%lld)]=%lld\n", l, r, A[l], counter[A[l]], A[r], counter[A[r]]);
        while(counter[A[r]]++ == 0 && r < N){
            r ++;
        }
        length = max(length, r - l);
        if(r==N || l == N) break;
        while(counter[A[r]]!=1){
            -- counter[A[l]];
            ++ l;
        }
        r = r + 1;
    }

    printf("%lld\n", length);


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}