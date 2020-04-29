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
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,n) for(ll i=n-1;i>=0;i--)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 100010;
static const ll mod = 2019;
static const ll max_value = 100000000000100;
// static const ll max_x = max_value * max_value;
static const double max_f = 1000000000.000;
vector<lf> weights(max_n);
vector<lf> salt(max_n);
vector<lf> sorted_array(max_n);
// vector<ll> S(max_n);
// vector<pair<ll, ll>> times_vec(max_n);
ll N, K, X;
double p, w;

bool is_ok(lf V){
    rep(i, N){
        sorted_array[i] = salt[i] - weights[i] * V;
    }

    sort(sorted_array.begin(), sorted_array.begin()+N, greater<lf>());
    lf v = 0;
    rep(i, K){
        // printf("sorted val[%lld]=%lf\n", i, sorted_array[i]);
        v += sorted_array[i];
    }
    return v>=0;
}


int main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    sll(N);
    sll(K);
    rep(i, N){
        slf(w);
        weights[i] = w;
        slf(p);
        salt[i] = p * 0.01 * w;
    }
    // rep(i,N) printf("salt[%lld] = %lf\n", i, salt[i]);

    double L = 0;
    double R = 1.1;
    rep(i,100){
        lf mid = (R+L)/2;
        // cout << "--- mid = " << mid << "----" <<endl;
        if(is_ok(mid)){
            L = mid;
        }else{
            R = mid;
        }
    }
    cout<<fixed<<setprecision(10)<<L*100<<endl;
    return 0;

}

// int main(){
//     Main();

//     return 0;

// }