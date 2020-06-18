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
            fill(x_list.begin(), x_list.end(), 1);
            fill(y_list.begin(), y_list.end(), 0);
        }

        void update(ll idx, T vx, T vy){
            idx += length - 1;
            x_list[idx] = vx;
            y_list[idx] = vy;
            // cout << "update idx "<<idx <<" to " << v <<endl;
            while(idx > 0){
                idx = (idx - 1 )/ 2;
                // a_r(a_l * x + b_l) + b_r
                // a_p = a_r * a_l, b_p = a_r * b_l + b_r
                x_list[idx] = x_list[2*idx+1] * x_list[2*idx+2];
                y_list[idx] = y_list[2*idx+1] * x_list[2*idx+2] + y_list[2*idx+2];
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
                return make_pair(1, 0);
            }

            // cout << "k = " << k << " l,r=" << l << "," <<r << " x,y=" << x << "," << y <<endl;

            // x ~ l, l ~ r, r ~ y , this return l ~ r
            // other range x ~ l and r ~ y will returned by other recursive path.
            if(x <= l && r <= y) return make_pair(x_list[k], y_list[k]);

            // this is the case l ~ x ~ r || l ~ y ~ r;
            // so we have to narrow the range to l ~ x ~ l+r //2  and (l+r) // 2 ~ x ~ r
            auto v_lch = query(x, y, 2*k+1, l, (l+r)/2);
            auto v_rch = query(x, y, 2*k+2, (l+r)/2, r);
            auto x_v = v_lch.first * v_rch.first;
            auto y_v = v_lch.second * v_rch.first + v_rch.second;

            return make_pair(x_v, y_v);
        }
};


void Main(){
    // cout << ai <<endl;
    ll N, M, p;
    double a, b;
    sll(N);
    sll(M);
    RMQ<double> rmq(M);

    ll max_v = 1;
    ll min_v = 1;
    vector<double> max_list(M+1, max_v);
    vector<double> min_list(M+1, min_v);
    vector<double> a_list(M);
    vector<double> b_list(M);
    vector<ll> p_list(M);
    vector<ll> p_list_to_sort(M);
    rep(i, M){
        sll(p);
        slf(a);
        slf(b);
        -- p;
        p_list[i] = p;
        a_list[i] = a;
        b_list[i] = b;
        p_list_to_sort[i] = p;
    }
    map<ll,ll> num2sorted_index;
    sort(p_list_to_sort.begin(), p_list_to_sort.end());
    p_list_to_sort.erase(unique(p_list_to_sort.begin(), p_list_to_sort.end()), p_list_to_sort.end());
    // for(auto p:p_list_to_sort){
    //     if(num2sorted_index.find(p) == num2sorted_index.end()){
    //         num2sorted_index[p] = (ll)num2sorted_index.size();

    //     }
    // }

    // cout << "num2sorted index:" << num2sorted_index <<endl;
    // cout << "p list:" << p_list <<endl;
    rep(i, M){
        a = a_list[i];
        b = b_list[i];
        // auto rmq_index = num2sorted_index[p_list[i]];
        auto rmq_index = lower_bound(p_list_to_sort.begin(), p_list_to_sort.end(), p_list[i]) - p_list_to_sort.begin();
        rmq.update(rmq_index, a, b);
        auto this_value = rmq.query(0, M);
        max_list[i+1] = max(max_list[i], this_value.first+this_value.second);
        min_list[i+1] = min(min_list[i], this_value.first+this_value.second);

    }

    // cout << rmq.x_list <<endl;
    // cout << rmq.y_list <<endl;

    std::cout.precision(20);
    std::cout.setf( std::ios::fixed, std:: ios::floatfield ); 
    cout << min_list[M] << endl;
    cout << max_list[M] << endl;

}

int main(){
    Main();
    
}

