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

vector<vector<ll>> field(3, vector<ll>(3, 0));
vector<ll> coord1 = {0, 4, 8};
vector<ll> coord2 = {2, 4, 6};
void Main(){
    string S, T;
    cin >> S;
    cin >> T;
    ll N = S.size();
    ll ans = 0;
    rep(i, N){
        ans += (ll)(S[i] != T[i]);
    }

    cout << ans <<endl;

}

int main(){
    Main();
}