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

static const ll K = 1<<24;
typedef long long ll;
// const int mod_ = 1000000007;
ll mod_;
// const int mod = 998244353;
struct mint {
    ll x; // typedef long long ll;
    ll mod;
    mint(ll x=0, ll mod=mod_):x((x%mod+mod)%mod), mod(mod){}
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
    ll X, P, A, B;
    sll(X);
    sll(P);
    sll(A);
    sll(B);
    mod_ = P;
    ll dist = B - A + 1;
    ll num_b = ceil(sqrt(P));
    // cout << "dist=" <<dist << " K=" << K <<endl;
    if(dist> K){
        vector<pair<mint, ll>> x_pows(num_b);
        mint base_x(X, P);
        set<ll> x_pows_set;
        mint base = base_x.inv().pow(num_b);
        rep(i, num_b){
            x_pows[i] = make_pair(base_x.pow(i), i);
            x_pows_set.insert(x_pows[i].first.x);
        }
        // cout << x_pows << endl;
        // cout << x_pows_set << endl;
        // baby step giant step
        ll found_v = 0;


        rep(i, P){
            bool is_break = false;
            mint gamma(i, P);
            ll start_it = A;
            ll end_it = B+1;
            mint left_pow_n = base.pow(A/num_b);
            // cout << "##### i=" <<i << " gamma=" << gamma << "######" <<endl;
            // cout << "left pow n = "<< left_pow_n << " start_it=" << start_it << endl;

            while(start_it<end_it && start_it % num_b != 0){
                mint this_v = gamma * left_pow_n;
                bool is_eq = x_pows[start_it%num_b].first.x == this_v.x;
                if(is_eq){
                    is_break = true;
                    found_v = i;
                    break;
                }
                ++ start_it;
            }
            if(is_break) break;

            mint right_pow_n = base.pow(B/num_b);
            // cout << "right pow n = "<< right_pow_n << " end_it=" << end_it << endl;

            while(start_it < end_it && end_it % num_b != 0){
                -- end_it;
                mint this_v = gamma * right_pow_n;
                bool is_eq = this_v.x == x_pows[end_it%num_b].first.x;
                if(is_eq){
                    is_break = true;
                    found_v = i;
                    break;
                }
            }
            if(is_break) break;
            if(start_it == end_it) continue;

            ll add_p = A / num_b;
            if(A%num_b!=0){
                left_pow_n *= base;
                add_p ++;
            }

            ll this_found = -1;
            ll this_found_j = -1;
            gamma = gamma * base.pow(add_p);
            // cout << "num_b=" << num_b << " start_it=" << start_it  << " left_pow_n=" << left_pow_n<< endl;
            // cout << "after start it =" << start_it << " gamma=" << gamma<<" addp=" << add_p <<endl;
            rep(i, num_b){
                // cout << "i=" << i <<" gamma=" << gamma <<endl;
                auto it = x_pows_set.find(gamma.x);
                if(it != x_pows_set.end()){
                    this_found = *it;
                    this_found_j = 0;
                    rep(j, num_b){
                        if(this_found == x_pows[j].first.x){
                            this_found_j = j;
                            break;
                        }
                    }
                    this_found_j += num_b * i;
                    break;
                }
                gamma = gamma * base;
                start_it += num_b;
                if(start_it == end_it) break;
            }
            if(this_found_j!=-1){
                // cout << "found v = " << i <<endl;
                found_v = i;
                break;
            }

        }
        cout << found_v <<endl;

    }else{
        // cout << "ex" <<endl;
        mint base(X, P);
        // cout << "base mod = "<< base.mod <<endl;
        base = base.pow(A);
        ll min_v = base.x;
        for(ll i=A+1;i<=B;i++){
            base = base * X;
            if(base.x < min_v){
                min_v = base.x;
            }
            // cout << base << endl;
        }
        cout << min_v <<endl;
    }

}

int main(){
    Main();
}