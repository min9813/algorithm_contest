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
    ll A,B,C;
    cin >> A >> B >> C;
    string out1 = "Yes";
    string out2 = "No";
    if(A==B && C != B){
        cout << out1 << endl;
    }else if(A==C && B != A){
        cout << out1 << endl;

    }else if(B==C && A != B){
        cout << out1 << endl;

    }else{
        cout << out2 << endl;

    }


}

int main(){
    Main();
}