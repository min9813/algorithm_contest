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
    ll N;
    string S;
    sll(N);
    cin >> S;
    ll ans = 0;
    ll now_right_r = N - 1;
    ll now_left_w = 0;
    for(;now_left_w<N;++now_left_w){
        if(S[now_left_w]!='W'){
            continue;
        }
        while(S[now_right_r]!='R' && now_right_r>now_left_w){
            -- now_right_r;
        }
        if(now_right_r<=now_left_w){
            break;
        }
        S[now_right_r] = 'W';
        S[now_left_w] = 'R';
        // cout << "add, now_left_w"
        ++ ans;
    }

    cout << ans <<endl;
}

int main(){
    Main();
}