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

template<typename T>
class RSQ{
    public:
        vector<T> uniform_op;
        vector<T> non_uniform;
        ll size = 1;
        ll fill_value = 0;

    RSQ(ll n=1, ll fill_value=0):fill_value(fill_value){
        while (size<n)
        {
            /* code */
            size *= 2;
        }
        uniform_op.resize(size*2-1);
        non_uniform.resize(size*2-1);
        fill(uniform_op.begin(), uniform_op.end(), fill_value);
        fill(non_uniform.begin(), non_uniform.end(), fill_value);
    }

    void update(ll a, ll b, ll x){
        update(a, b, x, 0, 0, size);
    }

    void update(ll a, ll b, ll x, ll k, ll l, ll r){
        // l, r = range of index k
        // a, b = range of query, x = query value
        eval(k, l, r);
        if(a<=l && r <= b){
            // l,r in query
            uniform_op[k] += x;
            eval(k, l, r);
        }else if(a < r && l <b){
            // l, r half overlap query
            // non_uniform[k] += (min(r, b) - min(l, a)) * x;
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            non_uniform[k] = non_uniform[2*k+1] + non_uniform[2*k+2];
        }
    }

    void eval(ll k, ll l, ll r){
        if(uniform_op[k] != 0 && uniform_op[k] %2==1){
            non_uniform[k] = (r - l) - non_uniform[k];
            if(r-l > 1){
                uniform_op[k*2+1] += uniform_op[k];
                uniform_op[k*2+2] += uniform_op[k];
            }
        }
        uniform_op[k] = 0;
    }

    T query(ll a, ll b){
        return query(a, b, 0, 0, size);
    }

    T query(ll a, ll b, ll k, ll l, ll r){
        eval(k, l, r);
        if(l >= b || r<= a ){
            return fill_value;
        }
        if(a<=l && r <= b){
            return non_uniform[k];
        }else{
            ll res = 0;
            res += query(a, b, k*2+1, l, (l+r)/2);
            res += query(a, b, k*2+2, (l+r)/2, r);
            return res;
        }
    }
};



void Main(){
    ll n, Q, q, l, r;
    sll(n);
    sll(Q);
    RSQ<ll> rsq(n, 0);
    rep(i, Q){
        sll(q);
        sll(l);
        sll(r);
        if(q==1){
            rsq.update(l, r, 1);
        }else{
            ll num = rsq.query(l, r);
            cout << num << endl;
        }
    }
    
    

}

int main(){
    Main();
}