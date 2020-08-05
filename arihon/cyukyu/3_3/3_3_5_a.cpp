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
static const ll max_n = 200010;

template <typename T>
class bucket{
    public:
        vector<set<T>> x_list;
        ll size;
        ll num_b;
        ll each_size;

    bucket(ll size, T default_v=0):size(size){
        num_b = ceil(sqrt(size));
        each_size = (size+(num_b-1)) / num_b;
        x_list.resize(num_b);
    }

    void update(T x){
        ll this_b = x / each_size;
        x_list[this_b].insert(x);
    }

    T query(T x){
        ll this_n = 0;
        ll prev_n = 0;
        rep(i, num_b){
            this_n += x_list[i].size();
            if(this_n>x){
                ll temp_i = 0;
                for(auto p:x_list[i]){
                    ++temp_i;
                    if(temp_i + prev_n == x){
                        x_list[i].erase(p);
                        return p;
                    }
                }
            }else if(this_n==x){
                auto it = x_list[i].end();
                -- it;
                ll get_p = *it;
                x_list[i].erase(get_p);
                return get_p;
            }
            prev_n = this_n;
        }
        auto it = x_list[num_b-1].end();
        -- it;
        ll get_p = *it;
        x_list[num_b-1].erase(get_p);
        return get_p;
    };



};

void Main(){
    // construct backet
    ll Q, t, x;
    sll(Q);
    bucket<ll> bb(max_n);
    // cout << bb.num_b << endl;
    // cout << bb.each_size << endl;
    // cout << bb.size << endl;
    // exit(1);
    rep(i, Q){
        sll(t);
        sll(x);
        if(t==1){
            // cout << "update ! "<<endl;

            bb.update(x);
            // cout << bb.x_list << endl;

        }else{
            // cout << "query ! "<<endl;
            cout << bb.query(x) <<endl;
            // cout << bb.x_list << endl;

        }

    }

}

int main(){
    Main();
}