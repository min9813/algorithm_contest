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

static const ll ai = (1L<<31L) - 1L;
static const ll max_n = 310;

class RMQ{
    public:
        vector<ll> x_list;
        ll n;
        ll length = 1;

        RMQ(ll n=1): n(n){
            length = 1;
            while (length < n){
                length *= 2;
            }
            // cout << "length;" << length <<endl;
            x_list.resize(2*length-1);
            fill(x_list.begin(), x_list.end(), ai);
        }

        void update(ll idx, ll v){
            idx += length - 1;
            x_list[idx] = v;
            // cout << "update idx "<<idx <<" to " << v <<endl;
            while(idx > 0){
                idx = (idx - 1 )/ 2;
                x_list[idx] = min(x_list[idx*2+1], x_list[idx*2+2]);
                // cout << "update idx" << idx << "to " << x_list[idx] <<endl;
            }
        }

        ll query(ll x, ll y, ll k, ll l, ll r){
            if(y <= l || x >= r){
                // cout << "l,r,x,y,k = "<< l << "," << r << "," << x << "," << y << "," <<k <<endl;
                return ai;
            }

            // cout << "k = " << k << " l,r=" << l << "," <<r << " x,y=" << x << "," << y <<endl;

            if(x <= l && r <= y) return x_list[k];

            ll v_lch = query(x, y, 2*k+1, l, (l+r)/2);
            ll v_rch = query(x, y, 2*k+2, (l+r)/2, r);
            return min(v_lch, v_rch);

        }
};

void Main(){
    // cout << ai <<endl;
    ll n, q;
    sll(n);
    sll(q);
    RMQ rmq(n);

    int o;
    ll x, y;

    rep(i, q){
        sii(o);
        sll(x);
        sll(y);
        if(o){
            printf("%lld\n", rmq.query(x, y+1, 0, 0, rmq.length));
        }else{
            rmq.update(x, y);
        }
    }


}

int main(){
    Main();
}