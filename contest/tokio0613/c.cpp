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

void Main(){
    ll K, N, a;
    cin >> N >> K;
    vector<ll> as(N,0);
    vector<ll> add_n(N+1,0);

    rep(i, N){
        sll(a);
        as[i] = a;
    }


    rep(i, K){
        fill(add_n.begin(), add_n.end(), 0);
        rep(j, N){
            ll range = as[j];
            ll left = max(j-as[j], (ll)0);
            ll right = min(j+as[j]+1, N);
            ++add_n[left];
            --add_n[right];
        }
        bool is_all_max = true;
        rep(j, N){
            add_n[j+1] += add_n[j];
            as[j] = add_n[j];
            is_all_max = is_all_max && add_n[j] == N;
        }
        // cout << "num = " << i << " is allm ax:" << is_all_max <<endl;
        if(is_all_max){
            break;
        }
    }

    printf("%lld", add_n[0]);
    rep(i, N-1){
        printf(" %lld", add_n[i+1]);
    }
    printf("\n");

}

int main(){
    Main();
}