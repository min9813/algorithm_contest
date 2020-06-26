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

ll lpower(ll b, ll p){
    if(b  < 2){
        return b;
    }

    if(p == 0){
        return 1;
    }

    if(p == 1){
        return b;
    }

    ll x = lpower(b, p/2);
    x *= x;
    if(p % 2){
        x *= b;
    }

    return x;
}

inline ll rsum(ll r, ll n){
    return r * (lpower(r, n) - 1) / (r - 1);
}

string alphabet = "abcdefghijklmnopqrstuvwxyz";


void Main(){
    ll N;
    cin >> N;

    ll length, left;
    rep(i, 12){
        ll r_sum = rsum(26, i);
        if(r_sum >= N){
            length = i;
            left = N - rsum(26, i-1);
            break;
        }
    }

    // cout << "length=" <<length <<endl;

    vector<ll> diff;
    for(ll j=length-1;j>=0;j--){
        ll base = lpower(26, j);
        if(base < left){
            ll num = (left-1) / base;
            left = left - base * num;
            diff.emplace_back(num);
        }else{
            ll num = 0;
            diff.emplace_back(num);
        }
    }

    string ans = "";
    for(ll i=diff.size()-1;i>=0;i--){
        ans = alphabet[diff[i]] + ans;
    }

    // cout << diff <<endl;

    
    cout << ans <<endl;


}

int main(){
    Main();
}