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
    ll now_right_r = -1;
    ll now_left_w = -1;
    rep(i, N){
        if(S[i] == 'W' && now_left_w == -1){
            now_left_w = i;
        }
        if(S[N-i-1] == 'R' && now_right_r == -1){
            now_right_r = N - i - 1;
        }
    }

    if(now_left_w == -1 || now_right_r == -1){
        cout << 0 <<endl;
    }else{
        ll num = 0;
        while(now_left_w<now_right_r){
            S[now_left_w] = 'R';
            S[now_right_r] = 'W';
            ++ num;
            for(;now_left_w<N;now_left_w++){
                if(S[now_left_w] == 'W'){
                    break;
                }
            }
            for(; now_right_r>=0;now_right_r--){
                if(S[now_right_r] == 'R'){
                    break;
                }
            }
            // cout << num <<endl;
        }
        cout << num <<endl;
    }

}

int main(){
    Main();
}