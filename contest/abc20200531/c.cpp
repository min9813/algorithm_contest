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
#include <cmath>
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
    ll A;
    string B;
    sll(A);
    cin >> B;

    ll b1 = B[2] - '0';
    ll b2 = B[3] - '0';


    ll deciaml_b = b1 * 10 + b2;
    // cout << deciaml_b <<endl;
    ll int_b = B[0] - '0';
    // // ll int_b = B;
    // // deciaml_b = deciaml_b % 100;
    // // cout << "B = " << B << ", "<< B / 1<< ", decimal b " << deciaml_b <<endl;
    // // cout << "A * decimal b = " << A * deciaml_b <<endl; 
    ll ans = A * int_b + (A * deciaml_b) / 100;
    // ll ans = floor(A * B);

    cout <<  ans <<endl;

}

int main(){
    Main();

    return 0;
}