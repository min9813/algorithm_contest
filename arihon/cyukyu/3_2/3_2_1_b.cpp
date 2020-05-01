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
// vector<vector<vector<ll>>> dp(max_n, vector<vector<ll>>(max_n, vector<ll>(max_n*max_n, 0)));
// static const ll max_x = max_value * max_value;
vector<ll> A(max_n);
// vector<ll> cards(max_n);
// vector<ll> S(max_n);
// vector<pair<ll, ll>> times_vec(max_n);
ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, Q, a, S;
    sll(N);
    sll(Q);
    rep(i,N){
        sll(a);
        A[i] = a;
    }

    rep(i, Q){
        sll(S);
        ll now_num = 0;
        ll now_sum = 0;
        ll j = 0;
        rep(i, N){
            now_sum += A[i];
            if(now_sum>S){
                while(now_sum>S&&j<=i){
                    now_sum -= A[j];
                    j++;
                }
                now_num += (i-j+1);
            }else{
                now_num += i - j + 1;
            }
        }
        printf("%lld\n", now_num);
    }


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}