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

// static const ll ai = (1L<<31L) - 1L;
static const ll max_n = 100010;

const int mod = 1000000007;
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
//   mint operator == (const mint a) {return x == a.x;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

static const ll fill_value = 1;

template<typename T>
T gcd(T a, T b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

template<typename T>
T lcm(T a, T b){
    return a * (b / gcd(a, b));
}

template <typename T>
class RMQ{
    public:
        vector<T> x_list;
        vector<mint> y_list;
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
            fill(x_list.begin(), x_list.end(), fill_value);
            fill(y_list.begin(), y_list.end(), 0);
        }

        void update(ll idx, T vx, mint vy){
            idx += length - 1;
            x_list[idx] = vx;
            y_list[idx] = vy;
            // cout << "update idx "<<idx <<" to " << v <<endl;
            while(idx > 0){
                idx = (idx - 1 )/ 2;
                x_list[idx] = lcm(x_list[idx*2+1], x_list[idx*2+2]);
                y_list[idx] = y_list[idx*2+1] * (x_list[idx]/ x_list[idx*2+1]) + y_list[idx*2+2] * (x_list[idx] / x_list[idx*2+2]);
                // cout << "update idx" << idx << "to " << x_list[idx] <<endl;
            }
        }

        pair<T, mint> query(ll x, ll y){return query(x, y, 0, 0, length);}

        pair<T, mint> query(ll x, ll y, ll k, ll l, ll r){
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
            auto x_v = lcm(v_lch.first, v_rch.first);
            auto y_v = v_lch.second * (x_v/ v_lch.first) + v_rch.second * (x_v/ v_rch.first);
            return make_pair(x_v, y_v);
        }
};

vector<ll> weight(max_n, 0);
vector<ll> pos(max_n, 0);


void Main(){
    // cout << ai <<endl;
    ll N, Q, l, r, a;
    sll(N);
    sll(Q);
    RMQ<ll> rmq(N);
    vector<ll> p_list(N+1);
    vector<mint> sum_list(N+1);
    for(ll i=1;i<=N;i++){
        sll(a);
        p_list[i] = a;
    }

    map<ll, mint> num2sum;
    map<ll, ll> num2circle_length;
    for(ll i=1;i<=N;i++){
        if(num2sum.find(i) != num2sum.end()){
            continue;
        }
        ll st = p_list[i];
        ll circle_length = 1;
        set<ll> group;
        group.insert(st);
        group.insert(i);
        ll sum;
        if (st == i){
            sum = st;
        }else{
            sum = st + i;
        }
        while(st != i){
            st = p_list[st];
            circle_length ++;
            // cout << group << endl;
            if(st != i){
                sum += st;
                // if(group.find(st) != group.end()){
                //     printf("something wrong ! ");
                //     exit(0);
                // }
            }
            group.insert(st);
        }

        for(auto e: group){
            num2sum[e] = sum;
            num2circle_length[e] = circle_length;
            // cout << "ok, " << e << endl;
            rmq.update(e-1, circle_length, sum);
        }
    }
    // cout << num2sum << endl;
    // cout << num2circle_length << endl;
    // auto prev_v = rmq.query(0, 1);
    // sum_list[1] = num2sum[1] * prev_times;
    // vector<ll> v_list = {prev_v};
    // for(ll i=1;i<N;i++){
    //     auto v = rmq.query(0, i+1);
    //     auto now_times = v / num2circle_length[i+1];
    //     sum_list[i+1] = sum_list[i] * (v / prev_v)+ num2sum[i+1] * now_times;
    //     // prev_times = now_times;
    //     prev_v = v;
    //     v_list.emplace_back(prev_v);
    // }
    // cout << "v list:" << v_list <<endl;

    // mint ans = 0;
    // cout << sum_list << endl;
    // cout << rmq.x_list <<endl;
    // cout << rmq.y_list <<endl;
    rep(i, Q){
        sll(l); sll(r);
        auto ans = rmq.query(l-1, r);
        printf("%lld\n", ans.second.x);
    }

    // cout << ans << endl;


}

int main(){
    Main();
    
}

