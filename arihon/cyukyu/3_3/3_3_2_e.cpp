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


template <typename T>
class RMQ{
    public:
        vector<T> x_list;
        vector<T> y_list;
        ll n;
        ll length = 1;

        RMQ(ll n=1): n(n){
            length = 1;
            while (length < n){
                length *= 2;
            }
            // cout << "length;" << length <<endl;
            x_list.resize(2*length-1);
            y_list.resize(2*length-1);
            fill(x_list.begin(), x_list.end(), 0);
            fill(y_list.begin(), y_list.end(), 0);
        }

        void update(ll idx, T vx){
            idx += length - 1;
            x_list[idx] = vx;
            // y_list[idx] = vy;
            // cout << "update idx "<<idx <<" to " << v <<endl;
            while(idx > 0){
                idx = (idx - 1 )/ 2;
                // a_r(a_l * x + b_l) + b_r
                // a_p = a_r * a_l, b_p = a_r * b_l + b_r
                x_list[idx] = x_list[2*idx+1] + x_list[2*idx+2];
                y_list[idx] = max(x_list[2*idx+2]+y_list[2*idx+1], y_list[2*idx+2]);
                // cout << "update idx" << idx << "to " << x_list[idx] <<endl;
            }
        }

        pair<T, T> query(ll x, ll y){return query(x, y, 0, 0, length);}

        pair<T, T> query(ll x, ll y, ll k, ll l, ll r){
            // query range -> (x, y)
            // range represented by k's index -> (l, r)

            // other range, x < y < l < r || l < r < x < y
            if(y <= l || x >= r){
                // cout << "l,r,x,y,k = "<< l << "," << r << "," << x << "," << y << "," <<k <<endl;
                return make_pair(0, 0);
            }

            // cout << "k = " << k << " search node l,r=" << l << "," <<r << " query x,y=" << x << "," << y <<endl;

            // x ~ l, l ~ r, r ~ y , this return l ~ r
            // other range x ~ l and r ~ y will returned by other recursive path.
            if(x <= l && r <= y) return make_pair(x_list[k], y_list[k]);

            // this is the case l ~ x ~ r || l ~ y ~ r;
            // so we have to narrow the range to l ~ x ~ l+r //2  and (l+r) // 2 ~ x ~ r
            auto v_lch = query(x, y, 2*k+1, l, (l+r)/2);
            auto v_rch = query(x, y, 2*k+2, (l+r)/2, r);
            auto x_v = v_lch.first + v_rch.first;
            auto y_v = max(v_rch.first+v_lch.second, v_rch.second);


            return make_pair(x_v, y_v);
        }
};


void Main(){
    // cout << ai <<endl;
    ll Q, K, q, d, a;
    sll(Q);
    sll(K);
    vector<ll> d_list(Q+1, 0);
    vector<ll> q_list(Q);
    vector<ll> a_list(Q, -1);
    vector<ll> d_list_sort(Q+1, 0);
    rep(i, Q){
        sll(q);
        q_list[i] = q;
        sll(d);
        if(q==1){
            sll(a);
            a_list[i] = a;
        }
        d_list[i+1] = d;
        d_list_sort[i+1] = d;
    }


    sort(d_list_sort.begin(), d_list_sort.end());
    d_list_sort.erase(unique(d_list_sort.begin(), d_list_sort.end()), d_list_sort.end());
    RMQ<ll> rmq((ll)d_list_sort.size());

    // cout << "compressed:" << d_list_sort <<endl;
    vector<ll> each_day_req(d_list_sort.size(), 0);
    rep(i, Q){
        d = d_list[i+1];
        ll rmq_index = lower_bound(d_list_sort.begin(), d_list_sort.end(), d) - d_list_sort.begin();
        ll day_diff = d_list_sort[rmq_index] - d_list_sort[rmq_index-1];
        ll x_value = K * day_diff;
        rmq.update(rmq_index, x_value);
    }
    // cout << "rmq x_list=" <<rmq.x_list <<endl;
    // cout << "rmq y_list=" <<rmq.y_list <<endl;
    rep(i, Q){
        d = d_list[i+1];
        ll rmq_index = lower_bound(d_list_sort.begin(), d_list_sort.end(), d) - d_list_sort.begin();
        // cout << "d=" <<d <<" rmq index=" <<rmq_index;
        if(q_list[i] == 1){
            ll day_diff = d_list_sort[rmq_index] - d_list_sort[rmq_index-1];
            each_day_req[rmq_index] += a_list[i];
            ll x_value = K * day_diff - each_day_req[rmq_index];

            // cout << " day diff=" <<day_diff << " x_value " << x_value << " a_list[" << i << "]=" <<a_list[i] <<endl;

            rmq.update(rmq_index, x_value);
            // cout << "rmq x_list=" <<rmq.x_list <<endl;
            // cout << "rmq y_list=" <<rmq.y_list <<endl;
        }else{
            auto ans = rmq.query(0, rmq_index+1);
            ll ans_v = max(ans.second, ans.first);
            // cout << "ans " <<ans <<endl;
            cout << K*d - ans_v <<endl;
        }

    }

    

}

int main(){
    Main();
    
}

