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

// static const ll max_n = 3000000000000000000;
vector<ll> as;
vector<ll> mas;
vector<ll> pas;
vector<ll> zero_as;
ll N, K, search_k;
ll ans_type;

bool search(ll mid){
    ll this_num = 0;
    if(ans_type == -1){
        mid = - mid;

    }
    rep(i, N){
        ll q, num;
        if(as[i] == 0){
            continue;
        }
        if(ans_type == -1){
            if(as[i]<0){
                q = mid / abs(as[i]);
                auto iter = upper_bound(pas.begin(), pas.end(), q);
                num = pas.end() - iter;
            }else{
                q = mid / as[i];
                num = mas.end() - upper_bound(mas.begin(), mas.end(), q);
            }
            // this_num += num;
        }else{
            if(as[i] < 0){
                q = mid / (-as[i]) + (mid % (-as[i])>0);
                num = lower_bound(mas.begin(), mas.end(), q) - mas.begin();
                if(q >= -as[i]){
                    -- num;
                }
            }else{
                q = mid / as[i] + (mid % as[i] > 0);
                num = lower_bound(pas.begin(), pas.end(), q) - pas.begin();
                // cout << pas << " found="<<*lower_bound(pas.begin(), pas.end(), q)<< endl;
                if(q >= as[i]){
                    -- num;
                }
            }
            // ans_type = 1
        }
        this_num += num;
        // cout << "i=" << i <<" as[i]=" << as[i] << " num=" << num<< " this_num= "<<this_num << " search k=" << search_k<< " mid="<<mid << " q="<< q <<endl;
        if(this_num > search_k){
            return false;
        }
    }

    return true;

}


void Main(){
    ll a;
    sll(N);
    sll(K);
    as.resize(N);
    rep(i, N){
        sll(a);
        as[i] = a;
        if(a<0){
            mas.emplace_back(-a);
        }else if(a>0){
            pas.emplace_back(a);
        }else{
            zero_as.emplace_back(a);
        }
    }
    ll zero_n = zero_as.size();
    ll m_n = mas.size();
    ll p_n = pas.size();
    sort(as.begin(), as.end());
    sort(mas.begin(), mas.end());
    sort(pas.begin(), pas.end());
    ll m_pn = m_n * p_n * 2;
    ll p_pn = (m_n*(m_n-1)) + (p_n*(p_n-1));
    ll zero_pn = zero_n * (N - zero_n)*2 + (zero_n * (zero_n-1));
    ll left_v, right_v;
    K *= 2;
    if(K<=m_pn){
        ans_type = -1;
        left_v = -1e18;
        right_v = 0;
        search_k = K - 2;
    }else if(K<=(m_pn+zero_pn)){
        ans_type = 0;
        cout << "0" <<endl;
        return;
    }else{
        ans_type = 1;
        left_v = 1;
        right_v = 1e18;
        search_k = K - (m_pn + zero_pn) - 2;
        // search_k *= 2;
    }
    // cout << "ans type=" << ans_type <<endl;

    // cout << left_v <<endl;
    // cout << right_v <<endl;

    while(right_v - left_v > 1){
        ll mid = (right_v + left_v )/ 2;
        bool is_ok = search(mid);
        // cout << "mid=" <<mid << " is_ok=" << is_ok <<endl;
        if(is_ok){
            left_v = mid;
        }else{
            right_v = mid;
        }
    }

    cout << left_v <<endl;

}

int main(){
    // cout << -15 % 4 <<endl; 
    // cout << 15 / (-4) <<endl; 
    // vector<ll> a = {3, 4, 6,6,7, 7, 10, 40};
    // cout << "upper_bound - a.begin() = " << upper_bound(a.begin(), a.end(), 6) - a.begin() <<endl;;
    // cout << "a.end()-upper_bound = " <<a.end()- upper_bound(a.begin(), a.end(), 6) <<endl;;
    // cout << lower_bound(a.begin(), a.end(), 6) -a.begin()<<endl;;
    Main();
}