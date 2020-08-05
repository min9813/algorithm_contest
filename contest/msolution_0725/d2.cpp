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
    ll N;
    sll(N);
    vector<ll> as(N);
    vector<ll> i_ac(N, 0);
    vector<ll> im_ac(N, 0);
    ll prev_a = 1000;

    rep(i, N){
        sll(as[i]);
    }
    // cout << "i-1:" << im_ac <<endl;
    // cout << "i:" << i_ac <<endl;
    ll now_m = 1000;
    ll now_s = 0;
    ll prev_sell = 0;
    ll prev_buy = 0;
    string now_type = "normal";

    rep(i, N-1){
        if(i==0){
            if(as[0] < as[i+1]){
                // buy stock
                now_s = now_m / as[i];
                now_m = now_m - now_s * as[i];
                now_type = "inc";
            }else if(as[0] > as[i+1]){
                now_type = "dec";
            }
        }else{
            if(as[i+1]>as[i] && now_type == "dec"){
                // buy stock
                now_s = now_m / as[i];
                now_m = now_m - now_s * as[i];
                now_type = "inc";
            }else if(as[i+1] < as[i] && now_type == "inc"){
                now_m += now_s * as[i];
                now_s = 0;
                now_type = "dec";
            }
        }
    }

    now_m += now_s * as[N-1];

    // cout << now_s << "," <<now_m <<endl;

    // now_m += now_s * as[N-1];

    cout << now_m <<endl;

}

int main(){
    Main();
}