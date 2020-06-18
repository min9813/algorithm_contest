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
class BIT{
    public:
        vector<T> x_list;
        ll n;

        BIT(ll n=1, T fill_value=0): n(n){
            x_list.resize(n+1);
            fill(x_list.begin(), x_list.end(), fill_value);
        }

        void add(ll idx, T v){
            for(ll x=idx; x<= n;x += (x & -x)){
                x_list[x] += v;
            }
        }

        ll get_sum(ll idx){
            T v = 0;
            for(ll x=idx;x>0;x-=(x & -x)){
                v += x_list[x];
            }
            return v;
        }
};

void Main(){
    ll N, a;
    sll(N);
    BIT<ll> bitree(N, 0);
    ll ans;
    vector<ll> a_list(N);
    vector<ll> a_list_s(N);
    map<ll, ll> counter;
    bool is_ok = true;
    rep(i, N){
        sll(a);
        a_list[i] = a;
        a_list_s[i] = a;
        counter[a] ++;
        if(counter[a] > 1){
            is_ok = false;
        }
    }

    if(is_ok){
        sort(a_list_s.begin(), a_list_s.end());
        a_list_s.erase(unique(a_list_s.begin(), a_list_s.end()), a_list_s.end());

        ans = 0;
        rep(i, N){
            a = a_list[i];
            ll bit_index = lower_bound(a_list_s.begin(), a_list_s.end(), a) - a_list_s.begin() + 1;
            ans += (i - bitree.get_sum(bit_index)) * a;
            bitree.add(bit_index, 1);
        }

        cout << ans <<endl;
    }else{
        cout << "-1" <<endl;
    }

    
}

int main(){
    Main();
}