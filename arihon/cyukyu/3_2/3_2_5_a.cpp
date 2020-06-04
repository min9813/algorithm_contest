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
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;

static const ll max_n = 100010;
vector<ll> ants(max_n);
vector<ll> after(max_n);
vector<ll> ans(max_n);
vector<ll> directions(max_n);
// static const ll max_col = 10000;
ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, L, T, x, w;
    sll(N);
    sll(L);
    sll(T);

    ll id = -1;

    rep(i, N){
        sll(x);
        sll(w);
        ants[i] = x;
        directions[i] = w;
        if(w==1){
            id = i;
        }
    }

    if(id==-1){
        rep(i,N){
            cout << ((ants[i] - T) % L + L) % L << endl;
        }
    }else{
        ll st_a = ants[id];
        ll target_coord = (st_a + T) % L;
        ll num = id;
        rep(i, N){
            if(directions[i]==1){
                after[i] = (ants[i] + T) % L;
            }else{
                after[i] = ((ants[i] - T) % L + L) % L;
                ll dist = (st_a - ants[i] + L) % L;
                num += (T * 2 + dist)/ L;
                num %= N;
            }
        }

        sort(after.begin(), after.begin()+N);
        ll id_dist = upper_bound(after.begin(), after.begin()+N, target_coord) - after.begin() -1;
        // printf("id=%lld, dist:%lld\n", id, id_dist);
        for(ll i=id_dist;i<id_dist+N;i++, num++){
            num %= N;
            ans[num] = after[i%N];
        }

        rep(i,N){
            printf("%lld\n", ans[i]);
        }
    }




}

int main(){
    Main();

    return 0;

}