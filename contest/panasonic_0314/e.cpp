#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(i=0;i<(ll)n;i++)
typedef long long ll;
static const ll max_length = 50000;
static const ll M = 2000;
vector<bool> ab(max_length*2, true);
vector<bool> ac(max_length*2, true);
vector<bool> bc(max_length*2, true);

bool match(char a, char b){
    bool ok = false;
    ok = (a=='?') || (b == '?') || (a == b);
    return ok;
}


int main(){
    // int u, v;
    // bool updated = false;
    // ll ans = 0;
    string a, b, c;
    cin >> a >>b >> c;

    ll i, j;
    rep(i, a.size()) rep(j,b.size()) if(!match(a[i], b[j])) ab[i-j+max_length] = false;
    rep(i, a.size()) rep(j,c.size()) if(!match(a[i], c[j])) ac[i-j+max_length] = false;
    rep(i, b.size()) rep(j,c.size()) if(!match(b[i], c[j])) bc[i-j+max_length] = false;
    
    ll ans = M * 10;
    for(i=-M*2;i<=M*2;i++){
        for(j=-M*2;j<=M*2;j++){
            // bの先頭に対するcの先頭でokな位置がbc[a+max_length]のaが記録しているもの。
            // ab[i], ac[j]okていうのはaの先頭に対してbの先頭はi個前はok, cの先頭はj個前はok,という意味。
            // だからab[i], ac[j]の時のbの先頭に対するcの先頭の相対位置はj - iになる。
            if(ab[i+max_length] && ac[j+max_length] && bc[j-i+max_length]){
                ll L = min((ll)0, min(i, j));
                ll R = max((ll)a.size(), max(i+(ll)b.size(), j+(ll)c.size()));
                
                ans = min(ans, R - L);
            }
        }
    }
    printf("%lld\n", ans);
    
    // double limit = 1. / (double)(4 * M);



    return 0;

}