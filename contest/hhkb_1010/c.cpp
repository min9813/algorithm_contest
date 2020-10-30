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
    cin >> N ;
    vector<ll> ps(N, 0);
    vector<ll> all_ans(N, 0);
    rep(i, N){
        cin >> ps[i];
    }

    ll ans = 0;
    set<ll> founds;
    rep(i, N){
        founds.insert(ps[i]);
        if(ps[i] != ans){
            all_ans[i] = ans;
        }else{
            while(founds.find(ans) != founds.end()){
                ++ ans;
            }
            all_ans[i] = ans;
        }

    }
    rep(i, N){
        cout << all_ans[i] <<endl;
    }
}

int main(){
    Main();
}