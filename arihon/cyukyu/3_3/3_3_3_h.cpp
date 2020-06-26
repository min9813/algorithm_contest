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

struct P{
    ll out;
    ll cap;
    ll id;

    // bool operator < (const P& p){
        // return cap < p.cap;
    // }
};


bool comp_p(const P &p1, const P &p2){
    return p1.cap > p2.cap;
}

bool comp_out(const P &p1, const P &p2){
    return p1.out < p2.out;
}



class RMQ{
    public:
        vector<P> max_list;
        ll n;
        ll length = 1;
        P fill_value;

        RMQ(ll n=1, P fill_value=P{0, 0, -1}): n(n), fill_value(fill_value) {
            length = 1;
            while (length < n){
                length *= 2;
            }
            // cout << "length;" << length <<endl;
            max_list.resize(2*length-1);
            fill(max_list.begin(), max_list.end(), fill_value);
        }

        void update(ll idx, P v){
            idx += length - 1;
            max_list[idx] = v;
            // cout << "update idx "<<idx <<" to " << v <<endl;
            while(idx > 0){
                idx = (idx - 1 )/ 2;
                max_list[idx] = max(max_list[idx*2+1], max_list[idx*2+2], comp_out);
                // cout << "update idx" << idx << "to " << x_list[idx] <<endl;
            }
        }

        P query(ll x, ll y){return query(x, y, 0, 0, length);}

        P query(ll x, ll y, ll k, ll l, ll r){
            if(y <= l || x >= r){
                // cout << "l,r,x,y,k = "<< l << "," << r << "," << x << "," << y << "," <<k <<endl;
                return fill_value;
            }

            // cout << "k = " << k << " l,r=" << l << "," <<r << " x,y=" << x << "," << y <<endl;

            if(x <= l && r <= y) return max_list[k];

            auto v_lch = query(x, y, 2*k+1, l, (l+r)/2);
            auto v_rch = query(x, y, 2*k+2, (l+r)/2, r);
            return max(v_lch, v_rch, comp_out);

        }
};

vector<P> ps;
ll N;

ll search(ll k){
    RMQ rmq(N);
    ll sum = 0;
    rep(i, k){
        auto target_p = ps[i];
        target_p.id = i;
        rmq.update(i, target_p);
        sum += target_p.out;
    }
    auto min_p = ps[k-1];
    // cout << " ### k = " << k << " ####" <<endl;
    // cout << "sum="<<sum <<" min cap=" << min_p.cap << endl;
    if(min_p.cap * k >= sum) return true;
    for(ll i=k;i<N;i++){
        auto min_p = ps[i];
        auto max_p = rmq.query(0, N);

        min_p.id = max_p.id;
        ll min_cap = min_p.cap;

        rmq.update(max_p.id, min_p);
        sum -= (max_p.out - min_p.out);
        // cout << "i=" << i << ", sum = "<< sum <<endl;
        if(min_cap * k >= sum){
            return true;
        }
    }

    return false;

}

void Main(){
    ll a, b;
    sll(N);
    ps.resize(N);
    rep(i, N){
        sll(a);
        sll(b);
        ps[i] = P{a, b, i}; 
    }
    sort(ps.begin(), ps.end(), comp_p);
    // cout << max(ps[0], ps[1], comp_out).cap << endl;
    // rep(i, N){
    //     cout << "cap=" << ps[i].cap << " out=" << ps[i].out<< endl;
    // }
    ll left = 0;
    ll right = N+1;
    while(right - left > 1){
        ll mid = (left + right) / 2;
        // printf("mid=%lld, left=%lld, right=%lld\n", mid, left, right);
        if(search(mid)){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << left <<endl;
    

}

int main(){
    Main();
}