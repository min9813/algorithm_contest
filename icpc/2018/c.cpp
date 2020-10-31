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
#define v(t) vector<t>
typedef long long ll;
typedef double lf;
typedef short int si;

static const ll max_n = 100000;


void Main(){
    ll n, a;
    v(pll) answers;
    while(cin >> n){
        if(n==0)break;
        pll ans = {n, 1};
        for(ll k=max_n;k>0;--k){
            ll res = 2 * n - k * k + k;
            if(res>0){
                if(res%k==0 && (res/k) % 2 == 0){
                    ans = {res/k/2, k};
                    break;
                }
            }
        }
        answers.push_back(ans);
    }

    rep(i, answers.size()){
        cout << answers[i].first << " " <<answers[i].second <<endl;
    }
}

int main(){
    Main();
}