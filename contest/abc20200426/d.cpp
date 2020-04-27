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
static const ll max_n = 200010;
static const ll mod = 2019;
// static const ll max_dist = 10000000;
// vector<vector<ll>> distance_table(max_n, vector<ll>(max_n, max_dist));
// vector<ll> distance_list(max_n);
// vector<ll> combination_table(max_n, 0);
// vector<ll> value_num(max_n, 0);
// vector<ll> combination_minus1_table(max_n, 0);
// vector<ll> balls(max_n);
vector<ll> res(max_n);
vector<ll> residual_10(224, 1);
// vector<vector<ll>> res_reverse(mod);
vector<ll> res_backet(mod, 0);
// vector<ll> res_reverse(max_n);

ll N, K;


int main(){
    // int u, v;
    // bool updated = alse;
    string S;
    cin >> S;
    ll N = (ll)S.size();
    for(ll i=1;i<residual_10.size();i++){
        residual_10[i] = (residual_10[i-1] * 10)% mod;
    }
    
    res[N-1] = (ll)(S[N-1] - '0');
    res_backet[res[N-1]] ++;
    for(ll i=N-2;i>=0;i--){
        ll v = (ll)(S[i] - '0');
        v = (res[i+1] + v*residual_10[(N-i-1) % (ll)residual_10.size()]) % mod;
        res[i] = v;
        // printf("res [%lld] = %lld\n", i, res[i]);
        res_backet[v]++;
    }

    ll ans = res_backet[0];
    for(ll i=0;i<mod;i++){
        ans += res_backet[i] * (res_backet[i] - 1) / 2;
    }

    printf("%lld\n", ans);

    return 0;

}