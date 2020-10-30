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
#include <assert.h>
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
static const int max_m = 20;
static const int max_n = 100010;
static const ll INF = 1e15;

// ll counter[max_m][max_n];
vector<vector<ll>> counter(max_m, vector<ll>(max_n, 0));
vector<ll> dp((1<<max_m), INF);
vector<ll> each_c((1<<max_m)-1, 0);

void Main(){
    ll N, M, m;
    cin >> N >> M;
    rep(i, N){
        cin >> m;
        counter[m-1][i+1] = 1;
    }

    rep(i, M){
        // 並べ替えの回数は左からぬいぐるみを条件に一致するように並べた時に、元の並び順と一致しないぬいぐるみの個数になる
        // これは、並び替えた時のぬいぐるみiの連続する部分が(l, r] の時に、
        // ぬいぐるみiがnまでに存在する数、という累積和の配列Aをとることて、A[i][r]-A[i][l]と表せる
        for(ll j=1;j<=N;j++){
            counter[i][j] = counter[i][j-1] + counter[i][j];
        }
    }

    dp[0] = 0;
    each_c[0] = 0;
    for(ll S=1;S<=(1<<M)-1;++S){
        // 上のコメントである(l, r]のlの計算にeach_cを使う
        for(ll u=0;u<M;++u){
            if((S>>u)&1){
                ll l = each_c[S-(1<<u)];
                ll r = l + counter[u][N];
                ll num_same = counter[u][r]-counter[u][l];
                ll num_this_class = counter[u][N];
                dp[S] = min(dp[S-(1<<u)]+num_this_class - num_same, dp[S]);
                each_c[S] = r;
            }
        }
    }
    cout << dp[(1<<M)-1] <<endl;

}

int main(){
    Main();
}