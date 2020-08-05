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
    string s;
    map<string, ll> counter;
    map<ll, set<string>> inv_counter;
    // set<ll, vector<ll>, greater<ll>> nums; 
    sll(N);

    rep(i, N){
        cin >> s;
        counter[s]++;
    }

    ll max_num = -1;
    for(auto &p:counter){
        max_num = max(max_num, p.second);
        inv_counter[p.second].insert(p.first);
    }

    for(auto &ss: inv_counter[max_num]){
        cout << ss <<endl;
    }
    
}

int main(){
    Main();
}