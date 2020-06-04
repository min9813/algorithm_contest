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
#include <prettyprint.hpp>
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

static const ll INF = 1 << 24;
static const ll max_n = 310;

ll N, M, P, Q, R;


void Main(){
    // sll(W);
    uint seed = 1234;
    vector<ll> sample = {1,2,3,4,5,6};
    // shuffle(sample.begin(), sample.end(), default_random_engine(seed));

    while(next_permutation(sample.begin(), sample.end())){
        cout << sample <<endl;
    }

    
}

int main(){
    Main();

    return 0;

}