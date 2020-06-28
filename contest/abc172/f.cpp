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
#define chmax(a, b) a = max(a, b);
typedef long long ll;
typedef double lf;
typedef short int si;

static const int max_n = 43;
vector<vector<vector<ll>>> dp(max_n, vector<vector<ll>>(2, vector<ll>(2, -1)));



void Main(){
    ll N;
    sll(N);
    vector<ll> as(N, 0);
    ll X = 0;
    ll S;
    rep(i, N){
        cin >> as[i];
    }
    for(ll i=2;i<N;i++){
        X ^= as[i];
    }

    ll A = as[0];
    ll B = as[1];
    S = A + B;
    // cout << "S="<<S<<", A,B=" << A << "," << B <<endl;

    dp[0][0][0] = 0;
    ll v = 1;
    rep(i, max_n-1){
        ll cx = X&1;
        ll cs = S&1;
        ll ca = A&1;
        // cout << "cs, cx, ca = "<< cs << ", " << cx << "," << ca <<endl;
        rep(j, 2){
            rep(k, 2){
                if(dp[i][j][k]==-1){
                    continue;
                }
                rep(na, 2)rep(nb, 2){
                    ll ni = i + 1;
                    ll nk = 0, nj = j;
                    if((na^nb) != cx) continue;
                    ll ns = na + nb + k;
                    if(ns%2 != cs) continue;
                    if(ns>=2) nk = 1;
                    if(ca<na){
                        nj = 1;
                    }else if(ca == na){
                        nj = j;
                    }else{
                        nj = 0;
                    }

                    chmax(dp[ni][nj][nk], dp[i][j][k]|(v*na));

                }
            }
            // int k = 0;
            // printf("dp[%lld][%lld][%lld]=%lld\n", i, j, k, dp[i][j][k]);

        }
        X >>= 1;
        S >>= 1;
        A >>= 1;
        v <<= 1;
    }

    // ll i = max_n-1, j=0, k = 0;
    // printf("dp[%lld][%lld][%lld]=%lld\n", i, j, k, dp[i][j][k]);


    ll a = dp[max_n-1][0][0];
    if(a==0 || a==-1){
        cout << "-1" <<endl;
    }else{
        cout << as[0]-a << endl;
    }


}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}