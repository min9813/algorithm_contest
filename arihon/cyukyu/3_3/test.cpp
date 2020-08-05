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
    

}

int main(){
    // Main();
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ll n = 26;
    map<ll, char> con;
    rep(i, n){
        con[i] = alphabets[i];
    }
    vector<vector<ll>> as = {{4, 5, 3, 9, 16, 8, 5, 18, 9, 14, 7, 9, 20, 23, 1, 19, 3, 15, 16, 12, 5, 20, 5 , 12, 25, 13, 5, 1, 14, 9, 14, 7, 12, 5, 19, 19}};
    rep(i, as.size()){
        for(auto j: as[i]){
            cout << con[(j-1-13) % alphabets.size()];
        }
        cout << endl;
    }
}