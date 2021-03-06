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


void Main(){
    ll n, a;
    v(ll) answers;
    while(cin >> n){
        if(n==0) break;
        v(ll) persons(n);
        ll sum = 0;
        rep(i, n){
            cin >> a;
            persons[i] = a * n;
            sum += a;
        }
        sort(persons.begin(), persons.end());
        ll ans = upper_bound(persons.begin(), persons.end(), sum) - persons.begin();
        answers.emplace_back(ans);
    }

    rep(i, answers.size()){
        cout << answers[i] <<endl;
    }
}

int main(){
    Main();
}