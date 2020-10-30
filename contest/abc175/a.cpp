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
#include <assert.h>
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
    string S;
    cin >> S;

    ll ans = 0;
    if(S[0] == 'R'){
        if(S[1] == 'R'){
            ans = 2 + (S[2] == 'R');
        }else{
            ans = 1;
        }
    }else{
        if(S[1] == 'R'){
            ans = 1 + (S[2] == 'R');
        }else{
            ans = (S[2] == 'R');
        }
    }

    cout << ans <<endl;

}

int main(){
    Main();
}