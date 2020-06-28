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

ll func(string S){
    ll N = S.size();
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    dp[0][0][0] = 1;
    rep(i, N){
        rep(j, 2){
            ll max_d;
            if(j==0){
                max_d = S[i] - '0';
            }else{
                max_d = 9;
            }
            rep(k, 2){
                rep(d, max_d+1){
                    dp[i+1][j||(d<S[i]-'0')][k||(d==4 || d==9)] += dp[i][j][k];
                }
            }
        }
    }

    return dp[N][0][1] + dp[N][1][1];
}


void Main(){
    ll A, B;
    cin >> A;
    cin >> B;
    string As = to_string(A-1);
    string Bs = to_string(B);
    // A = '0' + (A-'0'-1);
    // ll n = A - "0";
    // ll An = A.size();
    // ll Bn = B.size();

    cout << func(Bs) - func(As) <<endl;

}

int main(){
    Main();
}