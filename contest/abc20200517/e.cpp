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
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
typedef long long ll;
const int max_n = 200010;
const int mod = 1000000007;
// const int mod = 998244353;

vector<ll> a_list(max_n);
vector<ll> b_list(max_n);

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
// vector<string> Qs(max_n);
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    // assert(n < mod);
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

combination comb(max_n);

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, a, b;
    sll(N);
    mint total = 0;
    map<pair<ll,ll>, ll> ds;
    rep(i,N){
        sll(a);
        sll(b);
        a_list[i] = a;
        b_list[i] = b;
        ll ag, bg;
        if(a==0 && b != 0){
          ag = 0;
          bg = 1;
        }else if(a != 0 && b==0){
          ag = 1;
          bg = 0;
        }else if(a == 0 && b == 0){
          ag = 0;
          bg = 0;
        }else{
          ll tg = gcd(a, b);
          ag = a / tg;
          bg = b / tg;
          if(bg < 0){
            bg = - bg;
            ag = - ag;
          }
        }

        ++ ds[make_pair(ag, bg)];
        // cout << "i="<<i<<" " << total << endl;
    }

    // for(auto p:ds){
    //   cout << "key = " <<p.first.first << "," <<p.first.second << ":" << p.second <<endl;

    // }

    mint tk = 1;
    mint zero_n = 0;
    bool is_zero = false;
    mint base = 2;
    set<pair<ll,ll>> searched;
    for(auto p:ds){
      // cout << "--------" <<endl;
      // cout << "key = " <<p.first.first << "," <<p.first.second << ":" << p.second <<endl;
      if (searched.find(p.first) != searched.end()){
        continue;
      }

      if(p.first.first == 0 && p.first.second == 0){
        zero_n = p.second;
        is_zero = true;
        continue;
      }
      auto invp2 = make_pair(p.first.second, -p.first.first);
      searched.insert(invp2);
      // 2^N + 2 ^M - 1
      tk *= base.pow(p.second) + base.pow(ds[invp2]) - 1;
    } 

    tk = tk - 1;
    if(is_zero){
      tk += zero_n;
    }

    
    cout << tk << endl;
    // M * (M-1)^(N-k-1) * nCk

}

int main(){
    Main();

    return 0;

}