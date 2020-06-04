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
#include <complex>
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;

static const ll max_row = 10;
static const ll max_col = 10000;
ll N, M;
vector<ll> row_state(max_row);
vector<ll> col_state(max_col);

vector<vector<ll>> state(max_col, vector<ll>(max_row, false));


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll R, C, a;
    sll(R);
    sll(C);
    rep(i, R){
        rep(j, C){
            sll(a);
            state[j][i] = a;
        }
    }


    ll ans = -1;
    ll max_bit, ans_2;
    for(ll i=0;i<(1<<R);i++){
        // for(ll j=0;j<R;j++){
        //     row_state[j] = (i >> j) & 1;
        // }
        ll this_max_num = 0;
        rep(j, C){
            ll count_up = 0;
            rep(k, R){
                count_up += (((i >> k) & 1) + state[j][k]) % 2;
                // printf("k=%lld, i>>%lld = %lld, state[%lld][%lld]=%lld\n", k, k, ((i >> k) & 1), j, k, state[j][k]);
            }
            // printf("j=%lld, count=%lld, R-count=%lld\n", j, count_up, R-count_up);
            this_max_num += max(count_up, R-count_up);
        }
        if(this_max_num > ans){
            max_bit = i;
            ans_2 = this_max_num;
        }
        // cout << bitset<10>(i) <<"  this_max:" << this_max_num << " total max:" << ans<< endl;

        ans = max(ans, this_max_num);
    }
    // cout << bitset<10>(max_bit) <<"  max:" << ans_2 << endl;

    printf("%lld\n", ans);
}

int main(){
    Main();

    return 0;

}