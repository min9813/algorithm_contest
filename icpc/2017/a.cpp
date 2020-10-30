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
#define vv(t) vector<vector<t>>
#define vvv(t) vector<vector<vector<t>>>
typedef long long ll;
typedef double lf;
typedef short int si;


void Main(){
    ll n, m, a;
    v(ll) answers;
    while(cin >> n >> m){
        if(n==0) break;
        v(ll) as(n);
        rep(i, n){
            cin >> a;
            as[i] = a;
        }

        ll max_v = 0;
        rep(i, n){
            if(as[i] > m) continue; 
            for(ll j=i+1;j<n;++j){
                if(as[i] + as[j] <= m){
                    max_v = max(max_v, as[i]+as[j]);
                }
            }
        }
        answers.push_back(max_v);
    }
    rep(i, answers.size()){
        if(answers[i] == 0){
            cout << "NONE" << endl;
        }else{
            cout << answers[i] <<endl;
        }
    }
}


int main(){
    Main();
}