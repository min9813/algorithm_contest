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
#define vll vector<ll>
typedef long long ll;
typedef double lf;
typedef short int si;
static const ll MAXH = 2010;
static const ll MAXW = 2010;

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

string S[MAXH];
ll C[MAXH][MAXW];

void Main(){
    ll H, W;
    cin >> H >> W;
    ll num_k = 0;
    rep(i, H){
        cin >> S[i];
        rep(j, W){
            C[i][j] = 0;
            if(S[i][j] == '.'){
                ++ num_k;
            }
        }
    }

    rep(i, H){
        ll now_num = 0;
        ll now_l = 0;
        bool found = false;
        rep(j, W){
            if(S[i][j] == '.' && !found){
                found = true;
                now_num = 1;
                now_l = j;
            }else if(S[i][j] == '.' && found){
                ++now_num;
            }else if(S[i][j] == '#' && found){
                for(ll k=now_l;k<j;++k){
                    C[i][k] += now_num;
                }
                now_num = 0;
                found = false;
            }
        }
        if(found && now_num > 0){
            for(ll k=now_l;k<W;++k){
                C[i][k] += now_num;
            }
        }
    }

    // rep(i, H){
    //     rep(j, W){
    //         cout << C[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    rep(j, W){
        ll now_num = 0;
        ll now_l = 0;
        bool found = false;
        rep(i, H){
            if(S[i][j] == '.' && !found){
                found = true;
                now_num = 0;
                now_l = i;
            }else if(S[i][j] == '.' && found){
                ++now_num;
            }else if(S[i][j] == '#' && found){
                for(ll k=now_l;k<i;++k){
                    C[k][j] += now_num;
                }
                now_num = 0;
                found = false;
            }
        }
        if(found && now_num > 0){
            for(ll k=now_l;k<H;++k){
                C[k][j] += now_num;
            }
        }
    }
    // cout << "------ num_k=" << num_k << " ------------" <<endl;
    // rep(i, H){
    //     rep(j, W){
    //         cout << C[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    mint ans = 2;
    ans = ans.pow(num_k) * num_k;
    // cout << " total:" << ans <<endl;
    rep(i, H){
        rep(j, W){
            if(S[i][j] == '#') continue;
            mint dec_n = 2;
            dec_n = dec_n.pow(num_k - C[i][j]);
            // cout << "i,j=" << i << "," << j << " = " << dec_n <<endl;
            ans -= dec_n;
        }
    }

    cout << ans <<endl;
}

int main(){
    Main();
}