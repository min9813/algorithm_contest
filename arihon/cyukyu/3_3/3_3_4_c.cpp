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
#include <prettyprint.hpp>
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
        // vector<T> non_uniform;
        ll size = 1;
        ll fill_value = 0;
        ll fill_value2 = 1e18;

    RSQ(ll n=1, ll fill_value=0, ll fill_value2=0):fill_value(fill_value), fill_value2(fill_value2){
        while (size<n)
        {
            /* code */
            size *= 2;
        }
        uniform_op.resize(size*2-1);
        // non_uniform.resize(size*2-1);
        fill(uniform_op.begin(), uniform_op.end(), fill_value);
        // fill(non_uniform.begin(), non_uniform.end(), fill_value2);
    }

    void update(ll a, ll b, ll x){
        if(a > b){
            swap(a, b);
        }
        update(a, b, x, 0, 0, size);
    }

    void update(ll a, ll b, ll x, ll k, ll l, ll r){
        // l, r = range of index k
        // a, b = range of query, x = query value
        if(a<=l && r <= b){
            // l,r in query
            uniform_op[k] += x;
            // if(non_uniform[k]==fill_value2){
            //     non_uniform[k] = 0;
            // }
            // non_uniform[k] += x;
        }else if(a < r && l <b){
            // l, r half overlap query
            // non_uniform[k] += (min(r, b) - max(l, a)) * 1;

            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);

        }
    }

    T query(ll idx){
        idx += size - 1;
        T ans = uniform_op[idx];
        while(idx > 0){
            idx = (idx-1)/2;
            ans += uniform_op[idx];
        }

        return ans;
    }

};

void Main(){
    ll N, M, a, t, b, c, d;
    sll(N);
    sll(M);
    vector<ll> mans(N+2, 0);
    vector<ll> values;
    vector<pll> queries(N);
    rep(i, N){
        sll(a);
        mans[i+1] = a;
        values.emplace_back(a);
    }
    values.emplace_back((ll)0);
    rep(i, M){
        sll(t);
        if(t==1){
            sll(b);
            queries[i] = make_pair(b, -1);
            values.emplace_back(b);
        }else{
            sll(b);
            sll(c);
            queries[i] = make_pair(b, c);
            values.emplace_back(c);
        }
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    map<ll,ll> tables;
    rep(i, values.size()){
        tables[values[i]] = i;
    }

    rep(i, N+2){
        mans[i] = tables[mans[i]];
        // printf("man %lld = %lld", i, mans[i]);
    }

    ll max_v = -1;
    // ll max_idx = -1;

    rep(i, M){
        auto query = queries[i];
        if(query.second==-1){
            query.first = tables[query.first];
            // max_v = max(query.first, max_v);
        }else{
            query.second = tables[query.second];
            // max_v = max(query.second, max_v);
            // max_idx = max(max_idx, query.first);
        }
        queries[i] = query;
    }

    // cout << values << endl;
    cout << values.size() <<endl;
    RSQ<ll> tree(values.size()+1, 0, 0);
    rep(i, N+1){
        tree.update(mans[i]+1, mans[i+1]+1, 1);
        // max_v = max(mans[i]+1, max_v);
        // max_v = max(mans[i+1]+1, max_v);
    }
    // cout << "max v:" <<max_v << " max id:" << max_idx << " size=" << mans.size()<<endl;

    rep(i, M){
        auto query = queries[i];
        if(query.second==-1){
            // query type 1
            ll ans = tree.query(query.first);
            printf("%lld\n", ans/2);
        }else{
            // query type 2

            tree.update(mans[query.first-1]+1, mans[query.first]+1, -1);
            tree.update(mans[query.first]+1, mans[query.first+1]+1, -1);
            mans[query.first] = query.second;
            tree.update(mans[query.first-1]+1, mans[query.first]+1, 1);
            tree.update(mans[query.first]+1, mans[query.first+1]+1, 1);
        }
    }


}

int main(){
    Main();

    return 0;
}