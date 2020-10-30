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

static const char l = '(';
static const char r = ')';

// struct trip{
//     ll l; ll r; char m;
//     trip(ll l, ll r, char m): l(l), r(r), m(m){}
//     bool operator<(const trip& n1){
//         return l < n1.l;
//     }
// };

static const ll max_n = 200010;
// vector<vector<vector<ll>>> dp(max_n, vector<vector<ll>>(2, vector<ll>(2, 0)));
vector<vector<ll>> dp(max_n, vector<ll>(2, 0));

void Main(){
    string S;
    vector<ll> answers;
    while(cin>>S){
        if(S=="#") break;
        S = "#" + S + "#";
        // fill(dp.begin(), dp.end(), vector<vector<ll>>(2, vector<ll>(2, 0)));
        fill(dp.begin(), dp.end(), vector<ll>(2, 0));
        // dp[0][0] = 0;
        // dp[0][1] = 0;
        ll v = 0;
        ll min_v = 0;
        ll add_num = 0;
        rep(i, S.size()){
            if(i==0) continue;
            if(i==S.size()-1) continue;
            auto c = S[i];
            ll j = i + 1;
            // cout << "i=" << i <<" c=" << c << " min_v=" << min_v << " add num=" << add_num <<endl;
            if(c == l){
                dp[j][0] = max(dp[j-1][0] + 1, dp[j-1][1]+1);
                if(S[i] == S[i-1]){
                    // 2個取り
                    dp[j][1] = max(dp[j-2][0] + 1, dp[j-2][1]+1);
                }else if(i>1){
                    // min v のリセット
                    if(min_v < 0){
                        ll min_vv = abs(min_v);
                        // add_num += min_vv / 2 + min_vv % 2;
                        add_num += min_vv;
                        min_v = 0;
                        dp[j][0] = 1;
                    }
                    dp[j][1] = dp[j][0];
                }
            }else{
                dp[j][0] = max(dp[j-1][0]-1, dp[j-1][1]-1);
                if(S[i] == S[i-1]){
                    dp[j][1] = max(dp[j-2][0]-1, dp[j-2][1]-1);
                }else{
                    dp[j][1] = dp[j][0];
                }
                min_v = min(min_v, max(dp[j][0], dp[j][1]));
                // min_v = min(min_v, dp[j][1]);
            }
            // cout << " after min_v=" << min_v << " add_num" << add_num  << " dp[j][0]=" << dp[j][0] << " dp[j][1]=" <<dp[j][1]   << endl;  
            // cout << " after min_v=" << min_v << " add_num" << add_num  << " dp[j][0]=" << dp[j][0] << " dp[j][1]=" <<dp[j][1]   << endl;  
        }
        rep(i, S.size()+1){
            cout << dp[i][0] << " ";
        }
        cout << endl;
        rep(i, S.size()+1){
            cout << dp[i][1] << " ";
        }
        cout << endl;
        if(min_v < 0){
            ll min_vv = abs(min_v);
            add_num += min_vv / 2 + min_vv % 2;
        }
        // cout << "first add:" << add_num << " min_v=" << min_v <<endl;
        fill(dp.begin(), dp.end(), vector<ll>(2, 0));
        // dp[0][0] = 1;
        // dp[0][1] = 0;
        // ll v = 0;
        ll min_v2 = 0;
        rep(i, S.size()){
            ll si = S.size() - i - 1;
            if(si==0) continue;
            if(si==S.size()-1) continue;
            auto c = S[si];
            ll j = si + 1;
            // cout << "i=" << si <<" c=" << c << " min_v=" << min_v2 << " add num=" << add_num <<endl;
            if(c == r){
                dp[j][0] = max(dp[j+1][0] + 1, dp[j+1][1]+1);
                if(S[si] == S[si+1]){
                    // 2個取り
                    dp[j][1] = max(dp[j+2][0] + 1, dp[j+2][1]+1);
                }else if(i>1){
                    // min v のリセット
                    // dp[j][1] = dp[j][0];

                    if(min_v2 < 0){
                        ll min_vv = abs(min_v2);
                        // cout << "min_vv=" << min_vv <<endl;
                        // add_num += min_vv / 2 + min_vv % 2;
                        add_num += min_vv;
                        min_v2 = 0;
                        dp[j][0] = 1;
                    }
                    dp[j][1] = dp[j][0];
                }
            }else{
                dp[j][0] = max(dp[j+1][0]-1, dp[j+1][1]-1);
                if(S[si] == S[si+1]){
                    dp[j][1] = max(dp[j+2][0]-1, dp[j+2][1]-1);
                }else{
                    dp[j][1] = dp[j][0];
                }
                min_v2 = min(min_v2, max(dp[j][0], dp[j][1]));
                // min_v2 = min(min_v2, dp[j][0]);
                // min_v2 = min(min_v2, dp[j][1]);
            }
            // cout << " after min_v=" << min_v2 << " add_num" << add_num << endl; 
            cout << dp[j][0] << " ";

        }
        cout << endl;
        if(min_v2 < 0){
            ll min_v22 = abs(min_v2);
            add_num += min_v22;
            // min_v2 
        }
        cout << "second add:" << add_num << " min_v=" << min_v2 <<endl;

        answers.emplace_back(add_num);
    }

    rep(i, answers.size()){
        cout << answers[i] <<endl;
    }
    

}

int main(){
    Main();
}