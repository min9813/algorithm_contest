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

struct trip{
    ll l; ll r; char m;
    trip(ll l, ll r, char m): l(l), r(r), m(m){}
    bool operator<(const trip& n1){
        return l < n1.l;
    }
};

static const ll max_n = 200010;
vector<vector<vector<ll>>> dp(max_n, vector<vector<ll>>(2, vector<ll>(2, 0)));

void Main(){
    string S;
    vector<ll> answers;
    while(cin>>S){
        if(S=="#") break;
        fill(dp.begin(), dp.end(), vector<vector<ll>>(2, vector<ll>(2, 0)));
        // dp[0][0] = 1;
        // dp[0][1] = 0;
        ll start_i = 0;
        char first_c = S[start_i];
        while(first_c == r && start_i < S.size()){
            start_i += 1;
            first_c = S[start_i];
            dp[start_i+1][0][0] = 0;
            dp[start_i+1][0][1] = 0;
            dp[start_i+1][1][0] = 0;
            dp[start_i+1][1][1] = 0;
        }
        ll add_num = (start_i + 1) / 2 + (start_i + 1) % 2;
        for(ll i=start_i;i<S.size(); ++i){
            ll j = i + 1;
            if(S[i] == l){
                if(i==0){
                    dp[j][0][0] = 1;
                    dp[j][0][1] = 2;
                    dp[j][1][0] = 0;
                    dp[j][1][1] = 0;
                }else{
                    dp[j][0][0] = min(dp[j-1][0][0] + 1, dp[j-1][1][0] + 1);
                    dp[j][0][1] = max(dp[j-1][0][1] + 2, dp[j-1][1][1] + 2);
                    if(S[i] == S[i-1]){
                        dp[j][1][0] = min(dp[j-2][0][0] + 1, dp[j-2][1][0] + 1);
                        dp[j][1][1] = max(dp[j-2][0][1] + 2, dp[j-2][1][1] + 2);
                    }
                }
            }else{
                if(i==0){
                    continue;
                }else{
                    dp[j][0][0] = min(dp[j-1][0][0]-2, dp[j-1][1][0]-2);
                    dp[j][0][1] = max(dp[j-1][0][1]-1, dp[j-1][1][1]-1);
                    if(S[i] == S[i-1]){
                        dp[j][1][0] = min(dp[j-2][0][0]-2, dp[j-2][1][0]-2);
                        dp[j][1][1] = max(dp[j-2][0][1]-1, dp[j-2][1][1]-1);
                    }
                }
            }

        }

    }

    rep(i, answers.size()){
        cout << answers[i] <<endl;
    }
    

}

int main(){
    Main();
}