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


string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lower = "abcdefghijklmnopqrstuvwxyz";

void Main(){
    // string S;
    char s;
    cin >> s;
    bool is_u = false;
    for(auto c:upper){
        if(c == s){
            is_u = true;
        }
    }
    if(is_u){
        cout << "A" <<endl;
    }else{
        cout << "a" <<endl;

    }



}

int main(){
    // Main();
    cout << (int)'A'<<" " << (int)'a' <<endl;
    cout << tolower('A') <<endl;
}