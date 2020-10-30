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

static const ll max_n = 310;
vector<vector<bool>> take(max_n, vector<bool>(max_n, false));
vector<vector<ll>> dp(max_n, vector<ll>(max_n, 0));

void Main(){
    ll n, w;
    vector<ll> ans;
    while(cin>>n){
        if(n==0) break;
        fill(take.begin(), take.end(), vector<bool>(max_n, false));
        fill(dp.begin(), dp.end(), vector<ll>(max_n, 0));
        vector<ll> ws(n);
        rep(i, n){
            cin >> w;
            ws[i] = w;
        }
        rep(i, n){
            // if(i==0) continue;
            rep(j, n-i){
                ll s = j;
                ll t = j+i;
                ll len = i + 1;
                if(len==2){
                    if(abs(ws[s]-ws[t])<=1){
                        take[s][t] = true;
                    }
                }else{
                    for(ll k=s;k<t;++k){
                        if(take[s][k] && take[k+1][t]){
                            take[s][t] = true;
                            break;
                        } 
                    }
                }
                if(take[s][t]){
                    ll s2 = s - 1;
                    ll t2 = t + 1;
                    // cout << "s2=" << s2 << " t2=" << t2 <<endl;
                    while(s2>=0 && t2<n){
                        if(abs(ws[s2] - ws[t2]) <= 1){
                            take[s2][t2] = true;
                            -- s2;
                            ++ t2;
                            // cout << "ok, next=s2=" << s2 << " t2=" << t2 <<endl;
                        } else{
                            break;
                        }
                    }
                }

            }
        }

        rep(i, n){
            for(ll j=i+1;j<n;++j){
                if(take[i][j]) dp[i][j] = j-i+1;
            }
        }
        // rep(i, n){
        //     rep(j, n){
        //         cout << take[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        rep(i, n){
            rep(j, n-i){
                ll s = j;
                ll t = j + i;
                for(ll k=s;k<t;++k){
                    dp[s][t] = max(dp[s][t], dp[s][k]+dp[k+1][t]);
                }
            }
        }
        ll ans_tmp = dp[0][n-1];
        ans.emplace_back(ans_tmp);
    }
    rep(i, ans.size()){
        cout << ans[i] <<endl;
    }

}

int main(){
    Main();
}