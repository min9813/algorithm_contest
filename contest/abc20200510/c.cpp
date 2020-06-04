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
#include <unordered_set>
// #include <prettyprint.hpp>
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
// vector<ll> height(max_n, -1);
// vector<pair<ll,ll>> edge_list(max_n);

ll N, M, Q;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, M, X, c, a;
    sll(N);
    sll(M);
    sll(X);
    vector<ll> prices(N);
    vector<vector<ll>> skills(N, vector<ll>(M));
    rep(i, N){
        sll(c);
        prices[i] = c;
        rep(j, M){
            sll(a);
            skills[i][j] = a;
        }
    }

    ll min_cost = max_value;
    bool is_ok = false;
    for(ll i=0;i<(1<<N);++i){
        vector<ll> get_skills(M, 0);
        ll cost = 0;
        for(ll j=0; j<N;j++){
            if(i & (1<<j)){
                rep(k, M){
                    get_skills[k] += skills[j][k];
                }
                cost += prices[j];
            }
        }

        bool this_ok = true;
        for(auto s:get_skills){
            if(s < X){
                this_ok = false;
                break;
            }
        }

        if(this_ok){
            min_cost = min(min_cost, cost);
        }

        is_ok = (is_ok || this_ok);

    }

    if(is_ok){
        printf("%lld\n", min_cost);
    }else{
        printf("-1\n");
    }

    // printf("%lld\n", N-(ll)low_set.size());


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}