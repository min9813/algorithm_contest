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

// static const ll ai = (1L<<31L) - 1L;
static const ll ai = 0;
static const ll max_n = 100010;

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
                x_list[idx] = max(x_list[idx*2+1], x_list[idx*2+2]);
                // cout << "update idx" << idx << "to " << x_list[idx] <<endl;
            }
        }

        ll query(ll x, ll y){return query(x, y, 0, 0, length);}

        ll query(ll x, ll y, ll k, ll l, ll r){
            if(y <= l || x >= r){
                // cout << "l,r,x,y,k = "<< l << "," << r << "," << x << "," << y << "," <<k <<endl;
                return ai;
            }

            // cout << "k = " << k << " l,r=" << l << "," <<r << " x,y=" << x << "," << y <<endl;

            if(x <= l && r <= y) return x_list[k];

            ll v_lch = query(x, y, 2*k+1, l, (l+r)/2);
            ll v_rch = query(x, y, 2*k+2, (l+r)/2, r);
            return max(v_lch, v_rch);

        }
};

vector<ll> weight(max_n, 0);
vector<ll> pos(max_n, 0);


void Main(){
    // cout << ai <<endl;
    ll n, w, p;
    sll(n);
    RMQ rmq(n);


    ll sum = 0;
    rep(i, n){
        sll(w);
        weight[i] = w;
        sum += w * 2;
    }

    rep(i, n){
        sll(p);
        -- p;
        pos[i] = p;
    }

    ll ans = 0;
    rep(i, n){
        rmq.update(pos[i], rmq.query(0, pos[i])+weight[pos[i]]*2);
        ans = max(ans, rmq.query(pos[i], pos[i]+1));
        // printf("i=%lld, ans = %lld, org=%lld, w=%lld\n", i, ans, pos[i], weight[pos[i]]);
    }

    cout << sum - ans << endl;


}

int main(){
    Main();
}