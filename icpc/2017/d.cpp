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
#include <random>
#include <bitset>
#include <list>
#include <assert.h>
#include <unordered_set>
// #include <prettyprint.hpp>
using namespace std;
#define repi(i,n) for(int i=0;i<n;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repinvi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vvv(t) vector<vector<vector<t>>>
typedef long long ll;
typedef double lf;
typedef short int si;

static const ll max_m = 23;
static const ll max_n = 23;

// v(v(int)) dp_m(max_n+1, v(int)((1<<max_m), 0));
// v(v(ll)) info(max_n, v()(max_n, 0));
// v(ll) dp_n(1<<max_n, 0);

int bit_count(int n) {
	return n == 0 ? 0 : (n & 1) + bit_count(n >> 1);
}

void Main(){
    ll n, m;
    v(int) answers;
    while(cin >> n >> m){
        if(n == 0) break;
        int ans = 0;
        v(string) info(n);
        string s;
        rep(i, n){
            cin >> s;
            info[i] = s;
            // rep(j, s.size()){
            //     info[i][j] = s[j] - '0';
            // }
        }
        if(n<m){

            for(ll bit=1;bit<(1<<n);++bit){
                // v(int) use_bit;
                const int n_bit = bit_count(bit);

                if(n_bit>ans){
                    v(bool) is_even(m, false);
                    for(ll i=0;i<n;++i){
                        if((1<<i)&bit){
                            rep(j, m){
                                if(info[i][j] == '1'){
                                    is_even[j] = !is_even[j];
                                }
                            }
                        }
                    }
                    if(all_of(is_even.begin(), is_even.end(), [](bool b){return !b;})){
                        ans = n_bit;
                    }
                }
            }
        }else{
            v(v(int)) dp_m(2, v(int)(1<<m, -1));
            // fill(dp_m.begin(), dp_m.end(), v(int)(1<<max_m, -1));
            // cout << "ok" << endl;
            // rep(i, n){
            //     dp_m[i][0] = 0;
            // }
            dp_m[0][0] = 0;
            dp_m[1][0] = 0;
            // unordered_set<int> j_set;
            // j_set.insert(0);
            // cout << "start" <<endl;
            rep(i, n){
                int bit = 0;
                for(auto j = 0;j < m; ++j){
                    bit = (bit << 1) + info[i][j] - '0';
                }
                // cout <<"i=" << i << " bit=" << bitset<10>(info[i]) << endl;
                // unordered_set<int> j_set2 = j_set;
                // for(auto j:j_set2){
                rep(j, (1<<m)){
                    if(dp_m[i%2][j] < 0) continue;
                        // cout << "before dp["<<i << "][" << bitset<10>(j) << "]=" << dp_m[i][j] << endl;
                        // cout << (ll)(j^info[i]) << "," << dp_m[0].size() << "," << j << " dp_size=" << dp_m.size() <<endl;
                        // cout << "before  dp["<<i+1 << "][" << bitset<24>(j^info[i]) << "]"<< endl;
                    dp_m[(i+1)%2][j] = max(dp_m[(i+1)%2][j], dp_m[i%2][j]);
                    dp_m[(i+1)%2][j^bit] = max(dp_m[i%2][j] + 1, dp_m[(i+1)%2][j^bit]);
                        // cout << "after  dp["<<i+1 << "][" << bitset<24>(j^info[i]) << "]=" << dp_m[i][j^info[i]] << endl;
                    // j_set.insert(j^info[i]);
                }
            }

            ans = max(ans, dp_m[n%2][0]);
        }
        // cout << ans <<endl;
        // cout << "ans=" << ans <<endl;
        answers.emplace_back(ans);

    }

    rep(i, answers.size()){
        cout << answers[i] <<endl;
    }

}

int main(){
    Main();
}