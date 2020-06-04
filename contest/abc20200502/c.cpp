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
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 51;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;

vector<vector<ll>>dp(max_n, vector<ll>(max_n, 0));
vector<ll> a(max_n);
vector<ll> b(max_n);
vector<ll> c(max_n);
vector<ll> d(max_n);
ll N, M, Q;

ll dfs(ll v, vector<ll> &array){
    ll score = 0;
    if(array.size()==N){
        rep(i, Q){
            if(array[b[i]] - array[a[i]] == c[i]){
                score += d[i];
            }
        }
    }else{
        for(ll i=v;i<=M;i++){
            array.push_back(i);
            score = max(score, dfs(i, array));
            array.pop_back();
        }
    }
    return score;
}


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll x;
    sll(N);
    sll(M);
    sll(Q);
    rep(i, Q){
        sll(x);
        x --;
        a[i] = x;
        sll(x);
        x --;
        b[i] = x;
        sll(x);
        c[i] = x;
        sll(x);
        d[i] = x;
    }


    vector<ll> s;
    ll ans = dfs(1, s);

    printf("%lld\n", ans);


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}