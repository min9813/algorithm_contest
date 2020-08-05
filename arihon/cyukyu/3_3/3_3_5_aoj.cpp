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


void Main(){
    ll N, Q, q, i ,x ,s,t;
    sll(N);
    sll(Q);
    ll sizeB = sqrt(N);
    ll numB = (N + (sizeB-1)) / sizeB;
    vector<ll> xs(N, 0);
    vector<ll> bs(numB, 0);
    rep(j, Q){
        sll(q);
        // cout << "i=" << i << ", Q=" << Q <<endl;
        if(q==0){
            sll(i);
            sll(x);
            -- i;
            // ll prev_x = xs[i];
            xs[i] += x;
            bs[i/sizeB] += x;
            // cout << "i=" << i <<endl;
            // cout << "xs=" << xs <<endl;
            // cout << "bs=" << bs <<endl;
        }else{
            sll(s);
            sll(t);
            -- s;
            ll v = 0;
            while(s<t && s % sizeB != 0){
                v += xs[s];
                ++ s;
            }

            while(s < t && t % sizeB != 0){
                t --;
                v += xs[t];
            }
            ll left_b = s / sizeB;
            ll right_b = t / sizeB;
            if(left_b != right_b){
                for(ll i=left_b;i<right_b;i++){
                    v += bs[i];
                }
            }
            cout << v <<endl;
        }
    }

}

int main(){
    Main();
}