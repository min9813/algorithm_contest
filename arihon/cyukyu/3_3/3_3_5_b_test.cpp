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
static const ll max_n = 200010;

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

void Main(){
    // construct backet
    ll a, b, p;
    sll(a);
    sll(b);
    sll(p);
    ll num_b = ceil(sqrt(p));
    mint ma(a);
    // mint ma(a);
    vector<pair<mint, ll>> a_pows(num_b);
    set<ll> a_pows_set;
    rep(i, num_b){
        a_pows[i] = make_pair(ma.pow(i), i);
    }
    rep(i, num_b){
        a_pows_set.insert(a_pows[i].first.x);
    }
    cout << "okok" <<endl;
    mint base_inv = ma.pow(num_b);
    mint base(1);
    base /= base_inv;
    cout << "okok2" <<endl;
    mint gamma(b);
    cout << "okok3" <<endl;
    ll found = 0;
    ll found_j = 0;
    rep(i, num_b){
        cout << "i="<<i << ", gamma=" << gamma <<endl;
        auto it = a_pows_set.find(gamma.x);
        if(it != a_pows_set.end()){
            found = *it;
            rep(j, num_b){
                if(found == a_pows[j].first.x){
                    found_j = j;
                    break;
                }
            }
            found_j += num_b * i;
            break;
        }
        gamma = gamma * base;

    }

    cout << found_j << endl;


}

int main(){
    Main();
}