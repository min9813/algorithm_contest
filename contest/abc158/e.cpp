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


void Main(){
    ll P, N;
    string S;
    sll(N);
    sll(P);
    cin >> S;

    ll ans = 0;

    if(P==2 || P==5){
        for(ll i=N-1;i>=0;i--){
            ll digit = S[i] - '0';
            if(digit % P == 0){
                ans += i+1;
            }
        }
    }else{
        vector<ll> res(P,0);

        ll tmp_res = 0;
        res[0] = 1;
        ll base10_res = 1;
        for(ll i=N-1;i>=0;i--){
            tmp_res = (tmp_res + base10_res * (S[i]-'0')) % P;
            base10_res = (10 * base10_res) % P;
            ++res[tmp_res];
            // cout << "base10 res, i=" << i << " = " << base10_res <<" tmp res=" << tmp_res <<endl;
        }

        rep(i, P){
            ans += res[i] * (res[i]-1)/ 2;
        }

        // cout << "res:" << res <<endl;


    }
    cout << ans <<endl;


}

int main(){
    Main();
}