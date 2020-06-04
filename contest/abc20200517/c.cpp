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
#include <unordered_set>
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
const double PI=3.14159265358979323846;
static const ll max_n = 100010;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;
// vector<ll> height(max_n, -1);
// vector<pair<ll,ll>> edge_list(max_n);

ll N, M, Q;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    lf A, B, H, M;
    slf(A);
    slf(B);
    slf(H);
    slf(M);

    lf diff_rad = 2 * PI * (H / 12. + M / (12. * 60.) - M / 60.);
    // lf diff_rad = diff / 180. * PI;
    // cout << "diff " << diff << endl;
    // cout << "radian " << diff_rad <<endl;
    lf ans = sqrt(A*A + (B*B - 2*A*B*cos(diff_rad)));

    cout << setprecision(20) << ans <<endl;

}

int main(){
    Main();

    return 0;

}