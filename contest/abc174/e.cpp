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

static const ll max_v = 1e15;
vector<ll> as;
ll K, N;

bool is_ok(ll value){
    ll cut_n = 0;
    rep(i, N){
        cut_n += (as[i] - 1)/ value;
        if(cut_n > K){
            return false;
        }
    }

    return true;
}


void Main(){
    cin >> N >> K;
    as.resize(N);
    rep(i, N){
        sll(as[i]);
    }

    ll left_v = 0;
    ll right_v = 1e9;
    while(right_v - left_v>1){
        ll mid = (right_v + left_v) / 2;
        // cout << "mid=" << mid <<endl;
        bool ok = is_ok(mid);
        if(ok){
            right_v = mid;
        }else{
            left_v = mid;
        }
    }

    cout << right_v <<endl;
}

int main(){
    Main();
}