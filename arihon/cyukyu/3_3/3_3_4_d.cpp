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
        if(a<=l && r <= b){
            // l,r in query
            uniform_op[k] += x;
        }else if(a < r && l <b){
            // l, r half overlap query
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);

            non_uniform[k] = max(non_uniform[2*k+1]+uniform_op[2*k+1], non_uniform[2*k+2]+uniform_op[2*k+2]);
        }
    }

    T query(ll a, ll b){
        return query(a, b, 0, 0, size);
    }

    T query(ll a, ll b, ll k, ll l, ll r){
        if(l >= b || r<= a ){
            return fill_value;
        }
        if(a<=l && r <= b){
            return uniform_op[k] + non_uniform[k];
        }else{

            ll left_min = query(a, b, 2*k+1, l, (l+r)/2);
            ll right_min = query(a, b, 2*k+2, (l+r)/2, r);
            ll res = max(left_min, right_min) + uniform_op[k];
            return res;
        }
    }
};


static const ll max_n = 100010;
RSQ<ll> rsq(max_n, 0);


void Main(){
    ll N, s, t;
    sll(N);
    vector<pll> ranges(N);
    
    rep(i, N){
        sll(s);
        sll(t);
        // ++ t;
        ranges[i] = make_pair(s, t);
        rsq.update(s, t, 1);
    }

    ll ans = 1e18;
    rep(i, N){
        auto each_r = ranges[i];
        rsq.update(each_r.first, each_r.second, -1);
        ll this_query = rsq.query(0, max_n);
        // cout << "delete i="<<i << " ans=" << this_query <<endl;
        ans = min(ans, this_query);
        rsq.update(each_r.first, each_r.second, 1);

    }

    cout << ans <<endl;

}

int main(){
    Main();
}