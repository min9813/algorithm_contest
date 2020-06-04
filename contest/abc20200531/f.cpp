#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 3010;
// static const ll mod = 1000000007;
static const ll max_value = 100000000000100;


// const int mod = 1000000007;
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

vector<vector<mint>> dp(max_n, vector<mint>(max_n, 0));
vector<ll> as(max_n, 0);
// vector<string> Qs(max_n);
ll N, M;

void Main(){
    ll N, S, a;
    sll(N);
    sll(S);

    rep(i, N){
        sll(a);
        as[i] = a;
    }

    dp[0][0] = 1;
    for(ll i=1;i<=N;i++){
        rep(j, S+1){
            dp[i][j] += dp[i-1][j] * 2;
            if(j >= as[i-1]){
                dp[i][j] += dp[i-1][j-as[i-1]];
            }
        }
    }

    // rep(i, N+1){
    //     printf("dp[%lld] = ", i);
    //     rep(j, S+1){
    //         printf("%lld ", dp[i][j].x);
    //     }
    //     printf("\n");
    // }

    cout << dp[N][S] << endl;

}

int main(){
    Main();

    return 0;

}