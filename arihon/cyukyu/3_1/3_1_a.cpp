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
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,n) for(ll i=n-1;i>=0;i--)
#define sll(n) scanf("%lld", &n);
typedef long long ll;
static const ll max_n = 100010;
static const ll mod = 2019;
vector<ll> A(max_n);
vector<ll> B(max_n);
vector<ll> C(max_n);

vector<ll> B_num(max_n);
vector<ll> B_cum_num(max_n);

ll N, K;


int main(){
    // int u, v;
    // bool updated = alse;
    ll N, a, b, c;
    scanf("%lld", &N);
    rep(i,N){
        sll(a);
        A[i] = a;
    }
    rep(i,N){

        sll(b);
        B[i] = b;
    }
    rep(i,N){
        sll(c);
        C[i] = c;
    }

    sort(A.begin(), A.begin()+N);
    sort(B.begin(), B.begin()+N);
    sort(C.begin(), C.begin()+N);

    // cout << *(C.begin() + N-1) << " =?" << C[N-1] <<endl;
    // printf("B[N-1]=%lld\n", B[N-1]);
    B_num[N-1] = distance(lower_bound(C.begin(), C.begin()+N, B[N-1]+1), C.begin()+N);
    B_cum_num[N-1] = B_num[N-1];
    // printf("B_cumnum[%lld]=%lld, B_num[N-1]=%lld\n", N-1, B_cum_num[N-1], B_num[N-1]);
    repi(i,N-1){
        // cout <<"distance "<<i<<"="<< distance(C.begin(), lower_bound(C.begin(), C.begin()+N, B[i]+1)) << endl;
        ll num = distance(lower_bound(C.begin(), C.begin()+N, B[i]+1), C.begin()+N);
        // printf("i=%lld, num = %lld\n", i, num);
        B_num[i] = num;
        B_cum_num[i] = num + B_cum_num[i+1];
        // printf("B_cumnum[%lld]=%lld\n", i, B_cum_num[i]);
    }

    ll ans = 0;
    rep(i, N){
        ll idx = distance(B.begin(), lower_bound(B.begin(), B.begin()+N, A[i]+1));
        ans += B_cum_num[idx];
    }

    printf("%lld\n", ans);

    return 0;

}