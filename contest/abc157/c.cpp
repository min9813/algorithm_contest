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
    ll N, M, s, c;
    sll(N);
    sll(M);
    vector<ll> digits(N,-1);
    bool ng = false;
    rep(i, M){
        sll(s);
        sll(c);
        if(digits[N-s] != -1 && digits[N-s] != c){
            ng = true;
        }
        digits[N-s] = c;
    }
    ng = ng || (digits[N-1] == 0 && N>1);
    if(ng){
        cout << "-1" <<endl;
        return ;
    }
    if(N==1 && (digits[N-1] == 0 || digits[N-1] == -1)){
        cout << "0" <<endl;
        return;
    }
    ll ans;
    bool found = false;
    for(ll d=pow(10, N-1);d<pow(10, N); d++){
        // cout << "d = "<<d<<endl;
        bool is_ok = true;
        rep(i, N){
            ll base = pow(10, i);
            ll digit = (d % (base*10)) / base;
            if(digit == digits[i] || digits[i] == -1){
                is_ok = is_ok && true;
            }else{
                is_ok = is_ok && false;
            }
        }
        if(is_ok){
            ans = d;
            found = true;
            break;
        }
    }
    if(found){
        cout << ans <<endl;
    }else{
        cout << "-1" <<endl;
    }

}

int main(){
    Main();
}