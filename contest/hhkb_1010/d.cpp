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
const int mod = 1000000007;
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
    ll T, N, A, B;
    cin >> T;
    rep(i, T){
        cin >> N >> A >> B;
        if(A + B > N){
            cout << 0 <<endl;
            continue;
        }
        if(B > A){
            ll tmp = A;
            A = B;
            B = tmp;
        }
        ll max_b = min(B, N - A);
        ll other_b = N - 2*B - A + 1;
        mint x_e = N - A - B + 1;
        x_e = x_e * max_b - max_b * (max_b-1) / 2;
        mint y_e = A;
        y_e = y_e * max_b + (max_b * (max_b - 1) / 2);
        mint x_n = (N - B + 1) * max_b;
        mint edge_n = x_e * y_e + x_e * x_n;
        cout << "edge_n:" << edge_n << " xe, ye,xn:" << x_e << "," << y_e << "," <<x_n  << " b,a="<<B << "," << A << endl;
        edge_n *= 4;

        mint ans = edge_n;
        cout << ans <<endl;
        if(2*B + A <= N){
            // cout << "adding !" << "r=" << 2+B+A << ", N=" << N <<endl;
            mint mid_edge_n = x_e * A + (N - B + 1) * (N - A - B + 1) * other_b;
            mid_edge_n *= 4;
            mint mid_mid_n = (N - A - B + 1);
            mid_mid_n = mid_mid_n * mid_mid_n * other_b * other_b;
            ans += mid_mid_n + mid_edge_n;
            cout << "mid_edge_n:" << mid_edge_n << " mid mid n:" << mid_mid_n <<endl;

        }else{
            if((N - A) % 2 == 0){
                mint toom = x_e * (B - 1 + A) + max((ll)0, (N - B - (B - 1) - A + 1)) * (N - B + 1) * max_b;
                ans -= toom * 3;
            }
        }
        cout << ans <<endl;
    }

}

int main(){
    Main();
}