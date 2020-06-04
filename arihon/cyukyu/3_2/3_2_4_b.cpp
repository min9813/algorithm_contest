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

ll next_combination(ll comb){
    ll x = (comb & -comb); // 最下位の1ビットを取得, 10011110 -> 00000010
    ll y = comb + x; // 最下位から連続する1ビットが全て0になり、連続が終わった次の桁に繰り上げされる。上の例だと 10100000になる。
    return (((comb & ~y) / x) >> 1 ) | y;
}


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, M, P, Q, R, x, y, z;
    map<ll, map<ll, ll>> g2b_data;
    sll(N);
    sll(M);
    sll(P);
    sll(Q);
    sll(R);
    rep(i, R){
        sll(x);
        sll(y);
        sll(z);
        x --;
        y --;
        g2b_data[x][y] += z;
    }
    ll comb = (1 << P) - 1;
    ll ans = -1;
    while(comb < (1<<N)){
        map<ll,ll> b_score;
        rep(i, N){
            if(comb & (1 << i)){
                for(auto &p:g2b_data[i]){
                    b_score[p.first] += p.second;
                }
            }
        }
        set<pair<ll, ll>, greater<pair<ll,ll>>> score2b;
        for(auto &p:b_score){
            score2b.insert(make_pair(p.second, p.first));
        }
        ll idx = 0;
        ll this_score = 0;
        for(auto &p:score2b){
            this_score += p.first;
            ++idx;
            if(idx >= Q){
                break;
            }
        }
        ans = max(ans, this_score);
        comb = next_combination(comb);
    }

    printf("%lld\n", ans);
}

int main(){
    Main();

    return 0;

}