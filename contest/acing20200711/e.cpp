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

struct Cow{
    ll k, l, r, mode;

    bool operator < (const Cow c) const {
        if(this->k == c.k){
            if(mode==1){
                return (this->r - this->l) < (c.r - c.l);
            }else{
                return (this->l - this->r) < (c.l - c.r);
            }
        }else{
            return this->k < c.k;
        }
    }

};

ll solve(vector<Cow> & ks, ll mode=0){
    ll ans = 0;
    if(ks.size()==0){
        return ans;
    }
    // cout << "##### start mod =" << mode << " #####" <<endl;
    sort(ks.begin(), ks.end());
    priority_queue<ll, vector<ll>, greater<ll>> PQ;
    // PQ.push(1);
    // PQ.push(10);
    // PQ.push(3);
    // cout << PQ.top()<< endl;
    // PQ.pop();
    // cout << PQ.top()<< endl;
    // exit(0);
    rep(i, ks.size()){
        // cout << "i=" << i << "ks[i].k,l,r=" << ks[i].k << "," << ks[i].l << "," << ks[i].r  << " ans=" << ans<<endl;
        auto this_c = ks[i];
        ll this_v;
        if(mode==0){
            this_v = this_c.l - this_c.r;
        }else{
            this_v = this_c.r - this_c.l;
        }
        if(this_c.k <= 0){
            continue;
        }
        if(PQ.size()<this_c.k){
            PQ.push(this_v);
            ans += this_v;
        }else{
            if(PQ.top()<this_v){
                ans -= PQ.top();
                PQ.pop();
                ans += this_v;
                PQ.push(this_v);
            }
        }
        // cout << "this ans = " << ans << " this_v=" << this_v <<endl;
    }

    return ans;

}


void Main(){
    ll T, N, K, L, R;
    sll(T);
    rep(i, T){
        sll(N);
        vector<Cow> ls;
        vector<Cow> rs;
        ll ans = 0;
        rep(i, N){
            cin >> K >> L >> R;
            if(L>=R){
                ls.emplace_back(Cow{K,L,R,0});
            }else{
                rs.emplace_back(Cow{N-K,L,R,1});
            }
            ans += min(L, R);
        }
        // cout << "base ans=" << ans <<endl;
        ans += solve(ls, 0);
        // cout << "base2 ans=" << ans <<endl;

        ans += solve(rs, 1);
        cout << ans <<endl;

        
    }

}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}