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
    ll A, B;
    string S, T, u;
    cin >> S >> T;
    cin >> A >> B;
    cin >> u;

    bool is_s_ = true;
    bool is_t_ = true;
    rep(i, 10){
        if(i>=u.size()){
            if(u.size() == T.size()){
                is_s_ = false;
            }else{
                is_t_ = false;
            }
        }
        if(i>=T.size()){ is_t_ = false;break;}
        if(u[i] != T[i]) {is_t_ = false; break;}
        if(i>=S.size()){ is_s_ = false; break;}
        if(u[i] != S[i]) {is_s_ = false; break;}
    }

    if(is_s_){
        cout << A - 1 <<" " << B << endl;
    }else{
        cout << A <<" " << B -1<< endl;

    }

}

int main(){
    Main();
}