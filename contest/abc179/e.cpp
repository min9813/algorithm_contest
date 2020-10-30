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
    ll N, X, M;
    cin >> N >> X >> M;
    set<ll> found;
    vector<ll> found_r = {X};
    found.insert(X);

    ll a = X;
    ll circle_length = 0;
    // ll sum = a;
    rep(i, M){
        a = (a * a) % M;
        if(found.find(a) != found.end()){
            circle_length = i+1;
            break;
        }
        found.insert(a);
        found_r.emplace_back(a);
        // sum += a;
    }

    // ll size_r = found_r.size();
    auto it = find(found_r.begin(), found_r.end(), a);
    ll first_l = it - found_r.begin();
    ll circle_l = found_r.size() - first_l;
    ll sum = 0;
    ll first_s = 0;
    rep(i, circle_l){
        sum += found_r[first_l+i];
    }
    rep(i, first_l){
        first_s += found_r[i];
    }
    // found_r.find()

    // cout << "found r:" << found_r << endl;
    // cout << "size_r:" << size_r << " circle_l="<<circle_length <<endl;
    // cout << "first_l:" << first_l << " circle_l=" << circle_l << endl;
    // cout << "circle sum:" << sum << " first_s:" << first_s <<endl;

    ll res = (N  - first_l)% circle_l;
    ll ans = (N - first_l) / circle_l * sum;
    if(res>0){
        rep(i, res){
            ans += found_r[i+first_l];
        }
    }

    cout << ans + first_s <<endl;

}

int main(){
    Main();
}