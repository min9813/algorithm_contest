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

template<typename T>
class BIT{
    public:
        vector<T> x_list;
        ll n;
        ll min_value;

        BIT(ll n=1, T fill_value=0): n(n), min_value(fill_value){
            x_list.resize(n+1);
            fill(x_list.begin(), x_list.end(), fill_value);
        }

        void add(ll idx, T v){
            // cout << "idx="<<idx<<endl;
            for(ll x=idx; x<= n;x += (x & -x)){
                x_list[x] += v;
            }
        }

        ll get_sum(ll idx){
            T v = 0;
            // 最下位の1ビットを足す。
            for(ll x=idx;x>0;x-=(x & -x)){
                v += x_list[x];
            }
            return v;
        }

        T lower_bound(T w){
            if(w<=min_value){
                return min_value;
            }
            T k = 1;
            T x = 0;
            while(k*2<=n){
                k *= 2;
            }
            for(;k>0;k/=2){
                // cout << "k="<<k << ", x="<<x <<" w="<<w <<endl;
                if(x+k<=n && x_list[x+k]<w){
                    w -= x_list[x+k];
                    x += k;
                }
            }
            // cout << "w="<<w<<endl;
            // cout << "k="<<k << ", x="<<x <<" w="<<w <<endl;

            if(w>0 && x+1>=n){
                // w = bottom of hammer
                // meaning missing;
                return -1;
            }
            return x + 1;

        }
};


void Main(){
    ll N, M, H, a;
    sll(N);
    sll(M);
    sll(H);
    vector<ll> as(N+M, 0);

    ll num = 0;
    // cout << "ok"<
    BIT<ll> bitree(N+M, 0);
    rep(i, N){
        sll(a);
        as[num++] = a;
        bitree.add(num, a);
    }

    // cout << "bitree:" << bitree.x_list<<endl;

    string S;
    rep(i, M){
        cin >> S;
        sll(a);
        // cout << "op="<<S << " , a="<<a <<endl;
        if(S[0]=='a'){
            as[num++] = a;
            bitree.add(num, a);
        }else{
            ll a_idx = bitree.lower_bound(a-H+1);
            ll b_idx = bitree.lower_bound(a+H);
            if(a_idx == -1){
                printf("miss\n");
            }else if((b_idx == -1 && bitree.get_sum(a_idx+1)==bitree.get_sum(bitree.n))||(a_idx==b_idx)){
                printf("go\n");
                bitree.add(a_idx, -as[a_idx-1]);
            }else{
                printf("stop\n");
            }
        }
    }

}

int main(){
    Main();

    return 0;
}