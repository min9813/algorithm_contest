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

typedef long long ll;
const int mod = 1000000007;
// const int mod = 998244353;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

struct QS{
    ll lb,l, r, i;

    bool operator < (const QS& q){
        if(q.lb == lb){
            if(q.r == r){
                return i < q.i;
            }else{
                return r < q.r;
            }
        }
        return lb < q.lb;
    }

};

bool qs_sort(QS &q1, QS &q2){
    return q1 < q2;
}

template<typename T>
map<T, T> prime_factor(T N){
    map<T, T> res;
    ll i = 2;
    for(i=2;i*i<=N;i++){
        while(N%i==0){
            ++res[i];
            N /= i;
        }
    }
    if(N!=1){
        res[N] = 1;
    }
    return res;
}

void Main(){
    ll N, Q, x, l, r;
    cin >> N >> Q;
    vector<ll> xs(N);
    vector<QS> qs(Q);
    ll B = sqrt(N);
    ll numB = (N+(B-1)) / B;
    vector<vector<map<ll, ll>>> divisors(numB);
    vector<map<ll,ll>> backet(numB);
    vector<ll> q_ans(Q);
    rep(i, N){
        cin >> x;
        divisors[i/B].emplace_back(prime_factor(x));
        xs[i] = x;
    }
    // cout << "ok" <<endl;

    map<ll,ll> cum_b;
    rep(i, N){
        ll b_idx = i/B;
        ll idx_in_b = i % B;
        for(auto p:divisors[b_idx][idx_in_b]){
            cum_b[p.first] += p.second;
        }
        if(idx_in_b == B-1){
            backet[b_idx] = cum_b;
            cum_b.clear();
        }
    }

    // rep(i, numB){
    //     cout << "b=" << i << "," <<divisors[i] <<endl;
    //     cout << "total b=" << i << "," <<backet[i] <<endl;
    // }
    // exit(0);


    // cout << "ok2" <<endl;

    rep(i, Q){
        sll(l);
        sll(r);
        qs[i] = QS{(l-1)/B, l-1, r, i};
    }
    sort(qs.begin(), qs.end(), qs_sort);
    // cout << "ok3" <<endl;s

    rep(i, Q){
        auto tq = qs[i];
        // cout << "i=" << i << " l,r,i=" << tq.l <<"," << tq.r << "," << tq.i<< endl;
        ll left_idx = tq.l;
        ll right_idx = tq.r;

        ll this_b = left_idx / B;

        // cout << "this end b=" << this_end_b << " B=" << B << ", r_idx=" << right_idx <<endl;

        map<ll,ll> prev_m;
        while(left_idx % B != 0 && left_idx < right_idx){
            ll b_idx = left_idx % B;
            // cout << "this backet=" << this_b << " divisors size=" << divisors.size() <<endl;
            auto this_m = divisors[this_b][b_idx];
            for(auto p:this_m){
                prev_m[p.first] += p.second;
            }
            left_idx ++;
        }
        // cout << "ok4" <<endl;

        while(right_idx % B != 0 && right_idx > left_idx){
            right_idx --;
            ll this_end_b = right_idx / B;
            // cout << "this end backet=" << this_end_b << " divisors size=" << divisors.size() <<endl;
            ll b_idx = right_idx % B;
            auto this_m = divisors[this_end_b][b_idx];
            for(auto p:this_m){
                prev_m[p.first] += p.second;
            }
        }
        // cout << "ok5" <<endl;

        this_b = left_idx / B;
        ll this_end_b = right_idx / B;

        if(left_idx != right_idx){
            // different backet
            for(ll b_idx=this_b;b_idx<this_end_b;b_idx++){
                auto this_m = backet[b_idx];
                for(auto p:this_m){
                    prev_m[p.first] += p.second;
                }
            }
        }
        mint this_ans(1);
        for(auto p:prev_m){
            this_ans *= (p.second + 1);
        }
        // cout << "prev m :" << prev_m << " this ans=" << this_ans <<endl;

        q_ans[tq.i] = this_ans.x;
    }

    for(auto q:q_ans){
        cout << q <<endl;
    }

}

int main(){
    // vector<QS> qs = {QS{3, 5, 0}, QS{3, 4, 0}, QS{1, 4, 0}, QS{1, 3, 5}, QS{1, 3, 3}};

    // sort(qs.begin(), qs.end(), qs_sort);
    // for(auto q:qs){
    //     cout << q.l << "," << q.r << "," << q.i <<endl;
    // }
    // QS q{1,2,0}, q2{2,3,0};
    // cout << q.l << "," << q.r << "," << q.i <<endl;
    // cout << (q < q2) <<endl;
    Main();
}