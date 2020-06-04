#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <iomanip>
#include <complex>
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<ii,ii>
typedef long long ll;
typedef double lf;

static const ll INF = 1000000000000000;



void Main(){
    ll N;
    sll(N);
    string S;
    map<pair<string, string>, ll> l_status, r_status;
    cin >> S;
    
    ll ans = 0;
    for(ll i=0;i<(1<<N);i++){
        string left_rs = "", left_bs = "";
        for(ll j=0;j<N;j++){
            if((i>>j) & 1){
                left_rs += S[j];
            }else{
                left_bs += S[j];
            }
        }

        pair<string, string> p = make_pair(left_rs, left_bs);
        l_status[p] ++;

    }

    for(ll i=0;i<(1<<N);i++){
        string rs = "", bs = "";
        for(ll j=0;j<N;j++){
            if((i>>j) & 1){
                rs = S[j+N] + rs;
            }else{
                bs = S[j+N] + bs;
            }
        }

        pair<string, string> p = make_pair(bs, rs);
        r_status[p] ++;
    }

    for(auto p:l_status){
        ans += p.second * r_status[p.first];
    }
    cout << ans << endl;

}

int main(){
    Main();

    return 0;

}