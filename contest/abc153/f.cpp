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




void Main(){
    ll N, D, A, x, h;
    cin >> N >> D >> A;
    vector<ll> xs(N);
    map<ll,ll> xhs;
    ll max_x = x;
    rep(i, N){
        sll(x);
        sll(h);
        xs[i] = x;
        xhs[x] = h;
        max_x = max(x, max_x);
    }

    vector<ll> cs;
    rep(i, N){
        x = xs[i];
        cs.emplace_back(x);
        if(x==max_x){
            continue;
        }
        cs.emplace_back(x+2*D+1);
    }
    sort(cs.begin(), cs.end());
    cs.erase(unique(cs.begin(), cs.end()), cs.end());

    map<ll,ll> a2c;
    rep(i, cs.size()){
        x = cs[i];
        a2c[x] = i;
    }
    // cout << cs <<endl;
    // cout << a2c << endl;

    ll prev_x = -1;
    ll next_x = -1;
    ll now_num = 0, st_c, ed_c, now_dm,left_h, this_n;
    ll ans = 0;
    vector<ll> imos(cs.size(), 0);
    rep(i, cs.size()){
        x = cs[i];
        // cout << "i=" <<i << ", cs[i]=" << x  << " imos[i] = " << imos[i];
        if(xhs.find(x)==xhs.end()){
            // cout << " only end, now_num=" << now_num <<endl;
            now_num += imos[i];
            continue;
        }
        now_num += imos[i];
        // cout << " now num=" << now_num <<endl;
        h = xhs[x];
        now_dm = now_num * A;
        left_h = h - now_dm;
        if(left_h <= 0){
            // cout << "h=" << left_h << " < 0, continue" <<endl;
            continue;
        }
        this_n = (left_h-1) / A + 1;
        imos[i] += this_n;
        ans += this_n;
        now_num += this_n;
        if(x == max_x){
            break;
        }
        ed_c = a2c[x+2*D+1];
        imos[ed_c] -= this_n;
        
    }
    cout << ans <<endl;
}

int main(){
    Main();
}