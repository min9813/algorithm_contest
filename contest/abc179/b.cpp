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
    ll N, d1, d2;
    cin >> N;
    ll num_suc = 0;
    bool is_ok = false;
    rep(i, N){
        cin >> d1 >> d2;
        if(d1 == d2){
            ++num_suc;
            if(num_suc>=3){
                is_ok = true;
            }
        }else{
            num_suc = 0;
        }
    }

    if(is_ok){
        cout << "Yes" <<endl;
    }else{
        cout << "No" <<endl;
    }

}

int main(){
    Main();
}