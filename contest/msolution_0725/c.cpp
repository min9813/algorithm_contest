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
ll max_n = 1000000000000000;

void Main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> as(N);
    ll s = 1, prev_s = 1;

    rep(i, N){
        sll(as[i]);
        // s *= as[i];
        if(i>=K){
            // if(s%as[i-K] != 0)exit(0);
            if(as[i]>as[i-K]){
                cout << "Yes" <<endl;
            }else{
                cout << "No" <<endl;

            }
        }
        // prev_s = s;
    }
}

int main(){
    Main();
}