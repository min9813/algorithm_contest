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


template<typename T>
class SBIT{
    public:
    // sum(i, j) = bit1[i] * i + bit0[i]
        vector<T> bit0;
        vector<T> bit1;
        ll size;
        T fill_value;

    SBIT(ll n=1, T fill_value=0): fill_value(fill_value){
        size = n+1;

        bit0.resize(size);
        bit1.resize(size);
        fill(bit0.begin(), bit0.end(), fill_value);
        fill(bit1.begin(), bit1.end(), fill_value);
    }

    T sum_range(ll l, ll r){
        ll sum_r = sum_0(r-1) + sum_1(r-1) * (r-1);
        ll sum_l = sum_0(l-1) + sum_1(l-1) * (l-1);
        return sum_r - sum_l;
    }

    T sum_0(ll idx){
        T s = 0;
        while(idx > 0){
            s += bit0[idx];
            idx -= (idx & -idx);
        }
        return s;
    }

    T sum_1(ll idx){
        T s = 0;
        while(idx > 0){
            s += bit1[idx];
            idx -= (idx & -idx);
        }
        return s;
    }

    void add_range(ll a, ll b, T x){
        // printf("add1\n");
        add_0(a, -(a-1)*x);
        // printf("add2\n");
        add_1(a, x);
        // printf("add3\n");
        add_0(b-1, x*(b-1));
        // printf("add4\n");
        add_1(b-1, -x);
        // printf("add end\n");
    }

    void add_0(ll idx, T x){
        while(idx<=size){
            bit0[idx] += x;
            idx += (idx & - idx);
        }
    }

    void add_1(ll idx, T x){
        while(idx <= size){
            bit1[idx] += x;
            idx += (idx & - idx);
        }
    }

};

void Main(){
    ll n, q, m, s, t, x;
    cin >> n >> q;
    SBIT<ll> sbit(n, 0);
    rep(i, q){
        sll(m);
        if(m==0){
            sll(s);
            sll(t);
            sll(x);
            sbit.add_range(s, t+1, x);
        }else{
            sll(s);
            sll(t);
            ll ans = sbit.sum_range(s, t+1);
            printf("%lld\n", ans);
        }
    }

}

int main(){
    Main();
}