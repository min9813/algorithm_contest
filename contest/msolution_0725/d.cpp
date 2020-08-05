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
        if(as[i] > prev_a){
            im_ac[i-1] = 1;
            i_ac[i] = -1;
            // buy at i-1, sell at i
        }else if(as[i] < prev_a && i!=0){
            im_ac[i-1] = -1;
            i_ac[i] = 1;
            // sell at i-1, buy at i
        }

        prev_a = as[i];

    }
    // cout << "i-1:" << im_ac <<endl;
    // cout << "i:" << i_ac <<endl;
    ll now_m = 1000;
    ll now_s = 0;
    ll prev_sell = 0;
    ll prev_buy = 0;
    bool first_buy = true;
    rep(i, N-1){
        if(i==0 || first_buy){
            if(im_ac[i]==1){
                // buy
                now_s = now_m / as[i];
                now_m = now_m - now_s * as[i];
                first_buy = false;
            }
        }else{
            if(im_ac[i]==-1){
                bool found = false;
                for(ll j=i-1;j>=prev_sell;j--){
                    if(im_ac[j] == 1){
                        found = true;
                        break;
                    }
                }
                if(found){
                    prev_sell = i;
                    // sell
                    now_m = now_m + now_s * as[i];
                    now_s = 0;
                }
            }else if(im_ac[i] == 1){
                bool found = false;
                for(ll j=i-1;j>=prev_buy;j--){
                    if(im_ac[j] == -1){
                        found = true;
                        break;
                    }
                }
                if(found){
                    // cout << "found" <<endl;
                    // buy
                    prev_buy = i;
                    ll this_add = now_m / as[i];
                    now_m = now_m - this_add * as[i];
                    now_s += this_add;
                }
            }
            
        }
    }

    // cout << now_s << "," <<now_m <<endl;

    now_m += now_s * as[N-1];

    cout << now_m <<endl;

}

int main(){
    Main();
}