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

static const int max_l = 300010;

// bool compare_this(pll &p1, pll &p2){
//     // p1 = (w, index) or (h, index)
    
// }



void Main(){
    map<ll,ll> row, col;
    ll H, W, M, h, w;
    cin >> H >> W >> M;
    // vector<pll> hvs(M);
    // vector<pll> wvs(M);
    // set<pll, vector<pll>, greater<pll>()> hvs;
    // set<pll, vector<pll>, greater<pll>()> wvs;
    set<pll> pairs;
    // ll hs[M], ws[M];
    ll max_hv = 0;
    ll max_wv = 0;
    rep(i, M){
        cin >> h >> w;
        ++ row[h];
        ++ col[w];
        max_hv = max(max_hv, row[h]);
        max_wv = max(max_wv, col[w]);
        // hs[i] = h;
        // ws[i] = w;
        pairs.insert(make_pair(h, w));
    }

    vector<ll> h_max_s;
    vector<ll> w_max_s;
    for(auto r:row){
        if(r.second==max_hv){
            h_max_s.emplace_back(r.first);
        }
    }

    for(auto c:col){
        if(c.second == max_wv){
            w_max_s.emplace_back(c.first);
        }
    }

    ll ans = max_hv + max_wv - 1;

    for(auto h:h_max_s){
        for(auto w:w_max_s){
            if(pairs.find(make_pair(h, w)) == pairs.end()){
                ans ++;
                cout << ans << endl;
                return;
            }
        }
    }

    cout << ans << endl;
    return ;


    // cout << ans <<endl;




}

int main(){
    Main();
}