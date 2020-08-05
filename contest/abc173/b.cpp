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
    ll N;
    sll(N);
    string s;
    map<string, ll> as;
    rep(i, N){
        cin >> s;
        as[s] ++;
    }

    cout << "AC x " << as["AC"] <<endl;
    cout << "WA x " << as["WA"] <<endl;
    cout << "TLE x " << as["TLE"] <<endl;
    cout << "RE x " << as["RE"] <<endl;

}

int main(){
    Main();
}