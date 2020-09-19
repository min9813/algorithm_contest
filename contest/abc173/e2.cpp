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
// static const ll mod = 10000000007;

typedef long long ll;
const ll mod = 1000000007;
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

bool comp_abs(const ll &a, const ll &b){
    return abs(a) > abs(b);
}



void Main(){
    ll N, K;
    sll(N);
    sll(K);
    vector<ll> as(N);
    rep(i, N){
        cin >> as[i];
    }

    sort(as.begin(), as.end(), comp_abs);

    // K までで最小の負の数、正の数を記録
    // K まででの正負を記録
    ll num_m = 0;
    ll least_m = 1;
    ll least_mi = -1;
    ll least_pi = -1;
    ll least_p = -1;
    bool has_zero = false;
    rep(i, K){
        if(as[i]<0){
            ++num_m;
            least_m = as[i];
            least_mi = i;
        }else if(as[i]==0){
            has_zero = true;
            break;
        }else{
            least_p = as[i];
            least_pi = i;
        }
    }

    if(has_zero){
        cout << "0" <<endl;
    }else if(num_m%2==0){
        mint ans=1;
        rep(i, K){
            ans *= abs(as[i]);
        }
        cout << ans <<endl;
    }else if(K==N){
        mint ans = 1;
        rep(i, K){
            ans *= as[i];
        }
        cout << ans <<endl;
    }else{
        if(K<N && as[K]==0){
            cout << "0" <<endl;
        }else{
            bool found_p = false;
            bool found_m = false;
            ll big_p = -1;
            ll big_m = 1;
            // vector<ll> use_vs(K);
            for(ll i=K;i<N;++i){
                if(found_p && found_m){
                    break;
                }
                if(!found_m && as[i]<0){
                    big_m = as[i];
                    found_m = true;
                }else if(!found_p && as[i]>=0){
                    big_p = as[i];
                    found_p = true;
                }
            }
            if(least_p<0 && found_p){
                mint ans = 1;
                rep(i, K-1){
                    ans *= abs(as[i]);
                }
                ans *= big_p;
                cout << ans <<endl;
            }else if(least_p<0 && !found_p){
                mint ans = 1;
                rep(i, K){
                    ans *= as[N-i-1];
                }
                // ans *= big_p;
                if(ans.x < 0){
                    ans += mod;
                }
                cout << ans << endl;
            }else if(found_m && found_p){
                ll p_prod = big_p * least_p;
                ll m_prod = big_m * least_m;
                // cout << "found m : " << big_m << " found p : " << big_p <<endl;
                if(p_prod > m_prod){
                    // del m pick p
                    mint ans = 1;
                    rep(i, K){
                        if(i!= least_mi){
                            ans *= abs(as[i]);
                        }
                    }
                    ans *= big_p;
                    cout << ans << endl;
                }else{
                    mint ans = 1;
                    rep(i, K){
                        if(i!= least_pi){
                            ans *= abs(as[i]);
                        }
                    }
                    ans *= abs(big_m);
                    cout << ans << endl;
                }
            }else if(found_m){
                mint ans = 1;
                rep(i, K){
                    if(i!= least_pi){
                        ans *= abs(as[i]);
                    }
                }
                ans *= abs(big_m);
                cout << ans <<endl;
            }else if(found_p){
                mint ans = 1;
                rep(i, K){
                    if(i!= least_mi){
                        ans *= abs(as[i]);
                    }
                }
                ans *= big_p;
                cout << ans <<endl;
            }
        }
    }



}

int main(){
    // cout << 10 % mod <<endl;
    // cout << -10 % mod <<endl;
    // vector<ll> t = {-1, 10, 5, -10, 100,0, -1000};
    // sort(t.begin(), t.end(), comp_abs);
    // cout << t <<endl;
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}