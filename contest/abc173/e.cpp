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
    vector<ll> as(N, 0);
    rep(i, N){
        sll(as[i]);
    }
    sort(as.begin(), as.end(), comp_abs);
    set<ll> select_m_ids;
    set<ll> select_p_ids;
    set<ll> select_ids;
    ll num_m = 0;
    bool has_zero = false;
    rep(i, K){
        if(as[i]<0){
            num_m ++;
            select_m_ids.insert(i);
        }else if(as[i]>0){
            select_p_ids.insert(i);
        }else{
            has_zero = true;
        }
        select_ids.insert(i);
    }
    if(has_zero){
        cout << "0" <<endl;
        return;
    }
    else if(K==N || num_m %2 == 0){
        mint ans = 1;
        // ll prev = 1;
        for(auto c:select_ids){
            // ll this_a = prev * as[c];
            // prev = as[c];
            // this_a %= mod;
            // if(this_a < 0){
            //     this_a += mod;
            // }
            // ans *= this_a;
            ans *= as[c];
            if(ans.x < 0){
                ans += mod;
            }
        }
        cout << ans <<endl;
        return ;
    }else{
        bool find_m = false;
        bool find_p = false;
        ll found_m;
        ll found_m_idx;
        ll found_p;
        ll found_p_idx;
        for(ll i=K;i<N;i++){
            if(as[i]<0 && !find_m){
                find_m = true;
                found_m = as[i];
                found_m_idx = i;
            }else if(as[i]>0 && !find_p){
                find_p = true;
                found_p = as[i];
                found_p_idx = i;
            }
            if(find_m && find_p){
                break;
            }
        }

        bool may_del_p = select_p_ids.size()>0 && find_m;
        bool may_del_m = select_m_ids.size()>0 && find_p;

        if(may_del_m && may_del_p){
            auto m_it = select_m_ids.end();
            auto p_it = select_p_ids.end();
            -- m_it;
            -- p_it;
            ll del_m_id = *m_it;
            ll del_p_id = *p_it;
            // ll diff_p = -as[del_m_id] - found_p;
            // ll diff_m = as[del_p_id] + found_m;
            ll del_m_gain = as[del_p_id] * found_p;
            ll del_p_gain = as[del_m_id] * found_m;
            if(del_p_gain>del_m_gain){
                // get m
                select_p_ids.erase(del_p_id);
                select_ids.erase(del_p_id);
                select_ids.insert(found_m_idx);
            }else{
                // get p
                select_m_ids.erase(del_m_id);
                select_ids.erase(del_m_id);
                select_ids.insert(found_p_idx);
            }
        }else if(may_del_m){
            auto m_it = select_m_ids.end();
            -- m_it;
            ll del_m_id = *m_it;
            select_m_ids.erase(del_m_id);
            select_ids.erase(del_m_id);
            select_ids.insert(found_p_idx);
        }else if(may_del_p){
            auto p_it = select_p_ids.end();
            -- p_it;
            ll del_p_id = *p_it;
            select_p_ids.erase(del_p_id);
            select_ids.erase(del_p_id);
            select_ids.insert(found_m_idx);
        }else if(!find_m && !find_p){
            cout << "0" <<endl;
            return;
        }else{
            mint ans = 1;
            for(ll k=N-1;k>=N-K; k--){
                ans *= as[k];
                if(ans.x < 0){
                    ans += mod;
                }
            }
            cout << ans <<endl;
            return;
        }
        mint ans = 1;
        // ll prev = 1;
        for(auto c:select_ids){
            // ll this_a = prev * as[c];
            // prev = as[c];
            // this_a %= mod;
            // if(this_a < 0){
            //     this_a += mod;
            // }
            ans *= abs(as[c]);
            // if(ans.x < 0){
                // ans += mod;
            // }
        }
        cout << ans <<endl;
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