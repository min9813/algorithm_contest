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

vector<pair<lf, ll>> grad_x;
vector<pair<lf, ll>> grad_y;
vector<lf> bc_list;
vector<lf> ac_list;
vector<lf> y_coords;
vector<lf> y_coords_s;

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
    string S;
    cin >> S;
    ll N = S.size();
    map<char, ll> counter;
    map<char, ll> online_counter;
    rep(i, N){
        ++ counter[S[i]];
    }
    ll odd_num = 0;
    char odd_c = '0';
    for(auto &pair: counter){
        if(pair.second % 2){
            odd_c = pair.first;
            odd_num += 1;
        }

    }
    if(odd_num>1){
        cout << "-1" <<endl;
        return;
    }
    string left_s = "";
    string right_s = "";
    vector<ll> xis(N);
    vector<ll> right_s_list(N/2);
    map<char, ll> right_s_counter;
    map<pair<char, ll>, ll>right_s_index;
    // cout << "online counting "<<endl;
    rep(i, N){
        char ts = S[i];
        ++online_counter[ts];
        // cout << "i="<<i << " online counter=" << online_counter <<endl;
        if(N%2==1 && online_counter[ts] == counter[ts]/2+1 && odd_c == ts){
            xis[N/2] = i;
            online_counter[ts];
            continue;
        }
        if(online_counter[ts]>counter[ts]/2){
            ll xis_index = N / 2 + N % 2 + right_s.size();
            // cout << xis_index <<endl;
            xis[xis_index] = i;
            ll num_right_ts = right_s_counter[ts];
            right_s_index[make_pair(ts, num_right_ts)] = right_s.size();
            ++ right_s_counter[ts];
            right_s += ts;
        }else{
            ll xis_index = left_s.size();
            xis[xis_index] = i;
            left_s += ts;
        }
    }

    // cout << "finish ! "<<endl;

    BIT<ll> bit(N, 0);
    ll num_stox=0;
    // cout << "bit couting ! "<<endl;
    // cout << xis <<endl;
    rep(i, N){
        num_stox += i - bit.get_sum(xis[i]+1);
        bit.add(xis[i]+1, 1);
    }
    // cout << "finish"<<endl;
    // cout << "left s = " << left_s << "  middle = " << odd_c  << "  right s = " << right_s << endl;
    // cout << " S to X num = "<<num_stox <<endl;
    // cout << " right s index:" << right_s_index <<endl;
    // cout << " right s counter:" << right_s_counter << endl;

    map<char, ll> left_s_inv_counter;
    for(ll i=left_s.size()-1;i>=0;i--){
        char c = left_s[i];
        left_s_inv_counter[c];
        ll right_s_num = left_s_inv_counter[c];
        // cout << "i=" << i <<" c=" << c << " right_s_num=" << right_s_num <<endl;
        right_s_list[right_s_index[make_pair(c, right_s_num)]] = left_s.size()-1-i;
        ++left_s_inv_counter[c];
    }

    // cout << "right s list" << right_s_list <<endl;
    BIT<ll> bit2(N/2, 0);
    ll num_xtot = 0;
    rep(i, N/2){
        num_xtot += (i - bit2.get_sum(right_s_list[i]+1));
        bit2.add(right_s_list[i]+1, 1);
    }

    // cout << "num xtot :" << num_xtot <<endl;
    cout << num_xtot + num_stox <<endl;
    // rep(i, N/2){

    // }
    

    

    
}

int main(){
    Main();
}