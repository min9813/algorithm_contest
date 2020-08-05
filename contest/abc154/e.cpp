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
typedef long long ll;
typedef double lf;
typedef short int si;
v(v(v(ll))) dp(101, v(v(ll))(4, v(ll)(3, 0)));

// vector<vector<ll>> comb(101, vector<ll>(4, 1));

// void calc_comb(){
//     rep(n, comb.size()){
//         ll max_k = min(n, (ll)comb[n].size());
//         rep(k, max_k){
//             ll d = 1;
//             ll m = 1;
//             rep(i, k){
//                 d *= k-i;
//                 m *= n - i;
//             }
//             comb[n][k] = m / d;
//         }
//     }
// }


void Main(){
    string S;
    ll K;
    cin >> S;
    sll(K);
    // cout << "ok "<<endl;
    ll N = S.size();
    if(K>N){
        cout << 0 <<endl;
    }else{
        if(N==1){
            // k = 1
            cout << S[0] <<endl;
        }else{
            // N - 1 C k
            ll now_num_nzero = 1;
            dp[0][1][2] = 1;
            dp[0][1][1] = S[0] - '1';
            dp[0][0][0] = 1;
            // for(ll k=0;k<=K;k++){
                // rep(j, 3){
                    // printf("dp[%lld][%lld][%lld]=%lld\n", 0LL, k, j, dp[0][k][j]);
                // }
            // }
            for(ll i=1;i<N;++i){
                bool is_prev_zero = S[i-1] == '0';
                now_num_nzero += (S[i] != '0');
                ll max_k = min(now_num_nzero, K);
                if(now_num_nzero>K){
                    dp[i][K][2] = 0;
                }else{
                    dp[i][now_num_nzero][2] = 1;
                }
                for(ll k=1;k<=K;++k){
                    dp[i][k][1] = (dp[i-1][k-1][0] + dp[i-1][k-1][1]) * 9;
                    dp[i][k][0] = dp[i-1][k][1];
                    if(i>1){
                        dp[i][k][0] += dp[i-1][k][0];
                    }
                    // if(!is_prev_zero){
                        ll mid_num;
                        if(now_num_nzero > K){
                            mid_num = S[i] - '0';
                        }else{
                            mid_num = S[i] - '1';
                            mid_num = max(0LL, mid_num);
                        }
                        // cout << "mid num =" << mid_num << " k=" << k <<endl;
                        // printf("dp[%lld][%lld][%lld]=%lld\n", i, k, 1LL, dp[i][k][1]);

                        dp[i][k][1] += dp[i-1][k-1][2] * mid_num;

                    // }
                    if(S[i] != '0' || now_num_nzero > K){
                        dp[i][k][0] += dp[i-1][k][2];
                    }                    
                }
                dp[i][0][0] = 1;
                dp[i][0][2] = 0;
                // for(ll k=0;k<=K;k++){
                //     rep(j, 3){
                //         printf("dp[%lld][%lld][%lld]=%lld\n", i, k, j, dp[i][k][j]);
                //     }
                // }

            }
            ll ans = 0;
            rep(i, 3){
                ans += dp[N-1][K][i];
            }
            cout << ans <<endl;            

        }
    }
}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}