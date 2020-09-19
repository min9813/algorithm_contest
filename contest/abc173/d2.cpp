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
    vector<ll> as(N);
    rep(i, N){
        cin >> as[i];
    }

    sort(as.begin(), as.end(), greater<ll>());

    ll ans = 0;
    ll i = 0;
    ll res = N - 1;
    while(i<N){
        if(i==0){
            ans += as[i];
            -- res;
            ++ i;
        }else if(res==1){
            ans += as[i];
            break;
        }else{
            ans += as[i] * 2;
            res -= 2;
            i += 1;
        }
        if(res==0){
            break;
        }

    }

    cout << ans << endl;

}

int main(){
    Main();
}