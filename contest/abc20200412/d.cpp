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
    ll N;
    string S;
    cin >> N;
    cin >> S;
    ll ng_num_both = 0;
    ll ng_num_eq = 0;
    ll total_num = 0;
    map<ll, ll> counter;
    rep(i, N){
        for(ll j=1;j<N;++j){
            if(i+2*j>=N){
                break;
            }
            ll a = i;
            ll b = i + j;
            ll c = i + 2 * j;
            if(S[a] == S[b] || S[a] == S[c] || S[b] == S[c]){
                ng_num_both += 1;
            }
            ng_num_eq += 1;
        }
        for(ll j=i+1;j<N;++j){
            total_num += (N - j - 1);
        }
        counter[S[i]] ++;
    }

    ll ng_num_same = 0;
    for(auto p:counter){
        ll n = p.second;
        ll this_n = (n * (n-1) * (n-2)) / 6;
        this_n += (n * (n-1)) / 2 * (N-n);

        ng_num_same += this_n;
    }

    // cout << "total num=" << total_num << " ng_num_eq="<<ng_num_eq << "ng_num_same=" << ng_num_same << "ng_num_both=" << ng_num_both << endl;
    cout << total_num - (ng_num_eq + ng_num_same - ng_num_both) << endl;


}

int main(){
    Main();
}