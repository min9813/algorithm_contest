#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll, ll>
typedef long long ll;
typedef double lf;
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
typedef long long ll;
const int max_n = 200010;
const int mod = 1000000007;
// const int mod = 998244353;

vector<ll> as;
vector<ll> bs;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, a, b;
    sll(N);
    rep(i, N){
      sll(a);
      sll(b);
      as.emplace_back(a);
      bs.emplace_back(b);
    }

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    ll ans;
    if(N % 2){
      ll min_x = as[N / 2];
      ll max_x = bs[N / 2];
      // cout << "max x, min_x " << max_x << "," <<min_x <<endl;

      ans = max_x - min_x + 1;
    }else{
      ll min_x = as[(N-1) / 2] + as[N / 2];
      ll max_x = bs[(N-1) / 2] + bs[N / 2];
      // cout << "max x, min_x " << max_x << "," <<min_x <<endl;
      ans = max_x - min_x + 1;
    }
    

    
    cout << ans << endl;
    // M * (M-1)^(N-k-1) * nCk

}

int main(){
    Main();

    return 0;

}