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
typedef long long ll;
typedef double lf;
typedef short int si;
static const ll max_n = 18;
static const ll max_v = 1e18;

vector<vector<ll>> dp(max_n+1, vector<ll>(1<<max_n, -max_v));
vector<ll> dp2(1<<max_n);
vector<ll> xs(max_n);
vector<ll> xsum(max_n+1, 0);
vector<ll> cs(max_n);
vector<ll> vs(max_n);

void Main(){
    ll N, x, c, v;
    cin >> N;
    rep(i, N){
        cin >> x;
        xs[i] = x;
        xsum[i+1] = xsum[i] + xs[i];
    }
    rep(i, N){
        cin >> c;
        cs[i] = c;
    }

    rep(i, N){
        cin >> v;
        vs[i] = v;
    }


    for(ll i=(1<<N)-1;i>=0;--i){
        // set i が販売禁止になった時
        rep(k, N+1){
            ll total_s = 0;
            ll total_v = 0;
            // ll num = 0;
            rep(j, N){
                if(!((i>>j) & 1)){
                    total_s += cs[j];
                    total_v += vs[j];
                    // num += 1;
                }
            }
            // cout << std::bitset<18>(i) << " = " << total_s <<endl;
            // exit(0);
            if(total_s <= xsum[k]){
                dp[k][i] = total_v;
                continue;
            }
            rep(j, N){
                // if((i>>j &1)) continue;
                dp[k][i] = max(dp[k][i], dp[k][i|(1<<j)]);
            }
        }
    }

    // dp2[(1<<N)-1] = 0;

    for(ll i=(1<<N)-1;i--;){
        ll num = 0;
        rep(j, N){
            if((i>>j) & 1){
                ++ num;
            }
        }
        // cout << "ok, i=" << i <<" num="<<num <<" dp2[i]="<<dp2[i]<<endl;
        ll this_v = dp[num][i];
        ll now_v = max_v;
        rep(j, N){
            if((i>>j) & 1) continue;
            now_v = min(now_v, dp2[i|(1<<j)]);
            // cout << "######### now_v = "<< now_v << "####" <<endl;
        }
        // cout << "this_v=" << this_v << " now_v=" << now_v<<endl;
        dp2[i] = max(this_v, now_v);
    }

    cout << dp2[0] <<endl;


}

int main(){
    Main();
}