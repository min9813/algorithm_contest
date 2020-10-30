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

ll ai = 1e15;

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
            x_list[idx] = min(v, x_list[idx]);
            // cout << "update idx "<<idx <<" to " << v <<endl;
            while(idx > 0){
                idx = (idx - 1 )/ 2;
                x_list[idx] = min(x_list[idx*2+1], x_list[idx*2+2]);
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
            return min(v_lch, v_rch);

        }
};






void Main(){
    ll N, Q, t, x;
    cin >> N >> Q;
    RMQ rmq_col_v(N), rmq_row_v(N);
    rmq_col_v.update(N-1, N-1);
    rmq_row_v.update(N-1, N-1);
    // rmq_c.update()
    ll del = 0;
    // ll most_u = N-1;
    // ll most_l = N-1;
    rep(i, Q){
        cin >> t >> x;
        -- x;

        if(t==1){
            // (1, x);
            ll most_u = rmq_col_v.query(x, N);
            // printf("col x=%lld, v=%lld\n", x, most_u);
            // cout << "most u=" << most_u << endl;
            del += most_u - 1;
            rmq_row_v.update(most_u, x);
            // most_l = min(most_l, x-1);
            // cout << "update row " << most_u << " to" << x-1;
        }else{
            ll most_u = rmq_row_v.query(x, N);
            // printf("col x=%lld, v=%lld\n", x, most_u);
            // cout << "most u=" << most_u << endl;
            del += most_u - 1;
            rmq_col_v.update(most_u, x);
            // most_u = min(most_u, x-1);
            // cout << "update col " << most_l << " to" << x-1;
        }
    }

    cout << (N-2) * (N-2) - del << endl;
}

int main(){
    Main();
}