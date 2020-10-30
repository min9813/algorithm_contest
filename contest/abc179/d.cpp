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
typedef long long ll;
typedef double lf;
typedef short int si;

typedef long long ll;
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

void Main(){
    ll N, K, l, r;
    cin >> N >> K;
    vector<mint> dp1(N, 0);
    vector<mint> dp_sum(N, 0);
    vector<pll> lrs(K);
    rep(i, K){
        cin >> l >> r;
        // --l; -- r;
        lrs[i] = make_pair(l, r);
    }

    dp_sum[0] = 1;
    dp1[0] = 1;
    for(ll i=1;i<N;i++){
        dp_sum[i] += dp_sum[i-1];
        for(auto lr:lrs){
            l = lr.first;
            r = lr.second;
            mint add_v = 0;
            if(i>=l){
                add_v = dp_sum[i-l];
                // cout << "dp_sum[i-l]=" << dp_sum[i-l] << endl;
            }
            if(i>r){
                add_v -= dp_sum[i-r-1];
                // cout << "dp_sum[i-r-1]=" << dp_sum[i-r-1] << endl;
            }
            // cout << "i=" << i << " lr="<< lr << " add_v=" << add_v <<endl;
            dp1[i] += add_v;
            dp_sum[i] += add_v;
            // cout << "dp_sum[" << i <<"]=" << dp_sum[i] <<endl;
        }
    }

    cout << dp1[N-1] <<endl;


}

int main(){
    Main();
}