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
#include <bit>
#include <cstdint>
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
const int mod_ = 1000000007;
// ll mod_;
// const int mod = 998244353;
struct mint {
    ll x, mod; // typedef long long ll;
    mint(ll x=0, ll mod=mod_):x((x%mod+mod)%mod), mod(mod){}
    mint operator-() const { return mint(-x, mod);}
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
        // mint t_(t, mod);
        if (!t) return mint(1, mod);
        mint a = pow(t>>1);
        // cout << "pow mode=" << a.mod <<endl;
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

ll pop_count(ll x){
    ll v = 1;
    ll ans = 0;
    while(v<=x){
        ans += ((v & x)>0);
        // cout << bitset<8>(v) <<endl;
        // cout << bitset<8>(x) <<endl;
        // cout << bitset<8>(v&x) <<endl;

        v = v << 1;
    }

    return ans;
}

void Main(){
    ll N, X;
    string Xs;
    cin >> N;
    cin >> Xs;
    ll num = 0;
    for(auto c:Xs){
        num += c == '1';
    }
    map<ll,mint> mods;
    for(ll v=num-1;v<=num+1;v++){
        if(v>0){
            mint t(0, v);
            mods[v] = t;
        }
    }
    // cout << mods <<endl;
    ll v = 0;
    rep(i, Xs.size()){
        char c = Xs[i];
        if(c == '1'){
            v += pow(2, Xs.size()-i-1);
            for(auto &p:mods){
                ll this_v = p.first;
                mint t(2, this_v);
                t = t.pow(Xs.size()-i-1);
                // cout << "i=" << i << ", t=" << t <<endl;
                p.second += t;
            }
        }
    }
    // cout << v  <<endl;
    // for(auto &p:mods){
    //     cout <<p.first << " = " << v % p.first <<endl;
    // }
    // cout << mods <<endl;
    

    rep(i, Xs.size()){
        ll this_num;
        if(Xs[i] == '0'){
            this_num = num + 1;
        }else{
            this_num = num - 1;
        }
        if(this_num==0){
            cout << 0 <<endl;
            continue;
        }
        if(this_num==1){
            cout << 1 <<endl;
            continue;
        }
        mint this_v = mods[this_num];
        // cout << "### i = " << i << "####"<<endl;
        // exit(0);
        mint change(2, this_num);
        change = change.pow(Xs.size()-i-1);
        // cout << "this_v = " << this_v<<" mod=" << this_v.mod << " power=" << Xs.size()-i-1<< "change=" << change << "," <<change * (this_num - num) <<endl;
        if(this_num - num == -1){
            this_v -= change * (num - this_num);
        }else{
            this_v += change * (this_num - num);
        }
        // cout << "Xs[i] = " <<   Xs[i] << " this_num-num=" << this_num - num <<endl;
        // cout << "this v= "<< this_v <<endl;
        ll v = this_v.x;
        if(v == 0){
            cout << 1 <<endl;
            continue;
        }
        ll ans = 1;
        while(v != 0){
            ll pc = pop_count(v);
            v = v % pc;
            ans ++;
        }
        cout << ans <<endl;

    }



}


int main(){
    // cout << pop_count(1) <<endl;
    Main();
}