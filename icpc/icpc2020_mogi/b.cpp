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

static const ll max_n = 110;

vector<vector<ll>> field(max_n, vector<ll>(max_n, 0));

void Main(){
    ll W, H, N, D, B;
    vector<ll> answers;
    while(cin >> W >> H >> N >> D >> B){
        if(W==0){
            break;
        }
        fill(field.begin(), field.end(), vector<ll>(max_n, 0));
        vector<ll> xs(N, 0);
        vector<ll> ys(N, 0);
        vector<bool> used(N, false);
        ll x, y;
        rep(i, N){
            cin >> x >> y;
            xs[i] = x;
            ys[i] = y;
        }
        ll tx = xs[B-1];
        ll ty = ys[B-1];
        used[B-1] = true;
        queue<pll> Q;
        Q.push({tx, ty});
        while(!Q.empty()){
            pll tp = Q.front(); Q.pop();
            ll tx = tp.first;
            ll ty = tp.second;
            rep(i, N){
                if(used[i]) continue;
                if((abs(xs[i]-tx)<=D && (ys[i] == ty)) || ((abs(ys[i] - ty) <= D) && (xs[i] == tx))){
                    Q.push({xs[i], ys[i]});
                    used[i] = true;
                }
            }
        }
        ll ans = 0;
        rep(i, N){
            ans += (ll)used[i];
        }
        answers.emplace_back(ans);

    }

    rep(i, answers.size()){
        cout << answers[i] <<endl;
    }

}

int main(){
    Main();
}