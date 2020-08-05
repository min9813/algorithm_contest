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
    cin >> N;
    map<ll,ll> counter;
    ll ans = 0;
    for(ll x=1;x*x<N;x++){
        for(ll y=1;y*y+x*x<N;y++){
            for(ll z=1;z*z+x*x+y*y<N;z++){
                ll v = x*x + y*y+z*z;
                v += (x*y + y*z+z*x);
                if(v<=N){
                    counter[v] ++;
                }
            }   
        }
    }
    rep(i, N){
        cout << counter[i+1] <<endl;
    }
}

int main(){
    Main();
}