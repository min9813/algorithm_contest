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
class LAZYSEG{
    public:
        vector<T> lazy;
        vector<T> node;
        T default_v;
        ll size=1;
    
    LAZYSEG(ll n, T default_v): default_v(default_v){
        while(size<n){
            size *= 2;
        }

        lazy.resize(2*size-1);
        node.resize(2*size-1);
        fill(lazy.begin(), lazy.end(), default_v);
        fill(node.begin(), node.end(), default_v);
    }

    void eval(ll k, ll l, ll r){
        // evaluate node k, k represents index [l, r)
        if(lazy[k]!=default_v){
            node[k] += lazy[k];
            if(r-l>1){
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = default_v;

        }

    }

    void update(ll a,ll b, ll x){
        update(a, b, x, 0, 0, size);
    }

    void update(ll a, ll b, ll x, ll k, ll l, ll r){
        // eval(k, l, r);

        if(a<= l && r <= b){
            lazy[k] += (r-l)*x;
            eval(k, l, r);
        }else if(a<r && l < b){
            eval(k, l, r);

            update(a, b, x, k*2+1, l, (l+r)/2);
            update(a, b, x, k*2+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
            // eval(k, l, r);

        }else{
            eval(k, l, r);
            
        }
    }

    T get_query(ll a, ll b){
        return get_query(a, b, 0, 0, size);
    }

    T get_query(ll a, ll b, ll k, ll l, ll r){
        if(b <= l || r<= a){
            return default_v;
        }
        eval(k, l, r);

        if(a<=l && r <= b){
            return node[k];
        }
        // kの区間[l, r)には[a,b) 外のものも含まれているので子の区間の値をそのまま使うしかできない。
        // そうすると区間内にクエリ[a, b)がピッタリおさまる 値しか伝播してこないのでセーフ
        ll l_ch = get_query(a, b, 2*k+1, l, (l+r)/2);
        ll r_ch = get_query(a, b, 2*k+2, (l+r)/2, r);
        return l_ch + r_ch;

    }
};


void Main(){
    ll n, q, a, s, t, x;
    cin >> n >> q;
    LAZYSEG<ll> lseg(n, 0);
    rep(i, q){
        sll(a);
        sll(s);
        sll(t);
        -- s;
        -- t;
        if(a==0){
            sll(x);
            lseg.update(s, t+1, x);
        }else{
            cout << lseg.get_query(s, t+1) << endl;
        }
    }

}

int main(){
    Main();
}