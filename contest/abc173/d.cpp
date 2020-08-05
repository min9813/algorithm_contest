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
    sll(N);
    vector<ll> as(N,0);
    priority_queue<pll, vector<pll>> pq;
    rep(i, N){
        sll(as[i]);
        pq.push(make_pair(as[i], 2));
    }

    auto top = pq.top();pq.pop();
    // cout << top.first <<endl;
    top.second = 1;
    pq.push(top);
    ll ans = 0;
    rep(i, N-1){
        auto top = pq.top();pq.pop();
        -- top.second;
        ans += top.first;
        if(top.second>0){
            pq.push(top);
        }
    }

    cout << ans <<endl;


}

int main(){
    Main();
}