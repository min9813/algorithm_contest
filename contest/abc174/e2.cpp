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

static const double max_l = 1e15;
ll N, K;
vector<double> as;

bool is_ok(double mid){
    ll num_cut = 0;
    rep(i, N){
        // if(as[i]<mid){
        //     return false;
        // }
        num_cut += ceil(as[i] / mid) - 1;
        if(num_cut > K){
            return false;
        }
    }

    return true;
}

void Main(){
    cin >> N >> K;
    as.resize(N);
    double right = 0;
    rep(i, N){
        cin >> as[i];
        right = max(as[i], right);
    }

    double left = 0;
    rep(i, 200){
        double mid = (left + right) * 0.5;
        bool ok = is_ok(mid);
        // cout << "l:"<<left << " r:"<<right << " mid:"<<mid << " ok:"<<ok <<endl;
        if(ok){
            right = mid;
        }else{
            left = mid;
        }
    }

    ll ans = ceil(right);
    cout << ans <<endl;

}

int main(){
    Main();
}