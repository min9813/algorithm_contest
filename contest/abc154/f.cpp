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

typedef long long ll;
const int mod = 1000000007;
// const int mod = 998244353;
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

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

static const ll max_n = 2*1e6+10;
combination comb(max_n);
// vector<mint> c1_col(max_n, 1);
// vector<mint> c1_1_col(max_n, 1);
// vector<mint> c2_col(max_n, 1);
// vector<mint> c2_1_col(max_n, 1);
// vector<mint> r1_row(max_n, 1);
// vector<mint> r1_1_row(max_n, 1);
// vector<mint> r1_acm(max_n, 1);
// vector<mint> r2_row(max_n, 1);
// vector<mint> r2_1_row(max_n, 1);
// vector<mint> r2_acm(max_n, 1);

void Main(){
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    // ++ r1;
    // ++ r2;
    // ++ c1;
    // ++ c2;
    
    // for(ll i=0;i<=c2;i++){
    //     // (r1-1, i);
    //     r1_1_row[i] = comb(r1-1+i, i);
    //     r2_1_row[i] = comb(r2-1+i, i);
    //     if(i>0){
    //         r1_row[i] = r1_row[i-1] + r1_1_row[i];
    //         r2_row[i] = r2_row[i-1] + r2_1_row[i];
    //         r1_acm[i] = r1_acm[i-1] + r1_row[i];
    //         r2_acm[i] = r2_acm[i-1] + r2_row[i];
    //     }
    // }

    mint c1_1r1_1 = comb(r1+c1, c1);
    mint c1_1r2 = comb(r2+c1+1, c1);
    mint c2r1_1 = comb(r1+c2+1, c2+1);
    mint c2r2 = comb(r2+c2+2, c2+1);
    // cout << c1_1r1_1 << "," << c1_1r2 << "," << c2r1_1 << "," << c2r2 <<endl;

    auto ans = c2r2 - c1_1r2 - c2r1_1 + c1_1r1_1;
    cout << ans << endl;

    // for(ll i=0;i<=r2;i++){
    //     c1_1_col[i] = comb(c1-1+i, i);
    //     c2_1_col[i] = comb(c2-1+i, i);
    //     if(i>0){
    //         c1_col[i] = c1_col[i-1] + c1_1_col[i];
    //         c2_col[i] = c2_col[i-1] + c2_1_col[i];
    //     }
    // }
}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}