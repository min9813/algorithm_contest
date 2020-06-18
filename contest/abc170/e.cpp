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
// #include <bits/stdc++.h>
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

static const ll max_n = 51;
vector<ll> as(max_n,0);

void Main(){
    map<ll, set<ll, greater<ll>>> kinders;
    ll N, Q, a, b, c, d;
    sll(N); sll(Q);
    vector<ll> rates(N, 0);
    vector<ll> belongs(N, 0);
    map<ll, map<ll, ll>> kinder_counter;
    rep(i, N){
        sll(a);
        sll(b);
        rates[i] = a;
        belongs[i] = b;
        kinders[b].insert(a);
        kinder_counter[b][a] ++;
    }
    ll max_now = 1000000000;
    map<ll, ll> max_counter;
    set<ll> kinder_max_set;
    for(auto k:kinders){
        auto itr = k.second.begin();
        max_counter[*itr] ++;
        max_now = min(max_now, *itr);
        kinder_max_set.insert(*itr);
    }

    // cout << "kinder counter " << kinder_counter <<endl;
    // cout << "max set" << kinder_max_set <<endl;
    // cout << "max counter " << max_counter <<endl;


    rep(i, Q){
        sll(c);
        sll(d);
        -- c;
        // cout << "########## i = " <<i <<"###########"<<endl;
        // cout << "kinder counter " << kinder_counter <<endl;
        // cout << "max set" << kinder_max_set <<endl;
        // cout << "max counter " << max_counter <<endl;
        ll this_rate = rates[c];
        ll each_kinder = belongs[c];
        ll from_max_before = *kinders[each_kinder].begin();
        kinder_counter[each_kinder][this_rate] --;
        if(kinder_counter[each_kinder][this_rate]==0){
            kinders[each_kinder].erase(this_rate);
        }
        if(kinders[each_kinder].size()>0){
            ll this_max = *kinders[each_kinder].begin();
            if(from_max_before != this_max){
                -- max_counter[from_max_before];
                if(max_counter[from_max_before]==0){
                    kinder_max_set.erase(from_max_before);
                }
                ++ max_counter[this_max];
                kinder_max_set.insert(this_max);
            }
        }else{
            -- max_counter[from_max_before];
            if(max_counter[from_max_before]==0){
                kinder_max_set.erase(from_max_before);
            }
        }
        
        if(kinders[d].size()>0){
            ll to_max_before = *kinders[d].begin();
            kinders[d].insert(rates[c]);
            kinder_counter[d][this_rate] ++;
            ll to_max = *kinders[d].begin();
            if(to_max_before != to_max){
                -- max_counter[to_max_before];
                if(max_counter[to_max_before]==0){
                    kinder_max_set.erase(to_max_before);
                }
                ++ max_counter[to_max];
                kinder_max_set.insert(to_max);
            }

        }else{
            kinders[d].insert(rates[c]);
            kinder_counter[d][this_rate] ++;
            ll to_max = *kinders[d].begin();
            ++ max_counter[to_max];
            kinder_max_set.insert(to_max);
        }

        belongs[c] = d;
        // cout << " --- after manip ---" <<endl;
        // cout << "kinder counter " << kinder_counter <<endl;
        // cout << "max set" << kinder_max_set <<endl;
        // cout << "max counter " << max_counter <<endl;
        
        ll now_max_min = *kinder_max_set.begin();
        printf("%lld\n", now_max_min);
    }



}

int main(){
    // Main();
    multiset<ll> st{1,2,3,3,3,4, 1};



    cout << st <<endl;
    cout << *st.begin() <<endl;
    // st.erase(3);
    // st.erase(3);
    auto itr = st.lower_bound(3);
    cout << *itr <<endl;
    auto prev_itr = itr++;
    st.erase(prev_itr, itr);
    cout << st <<endl;
    // set<ll> t = {1};
    // t.erase(1);
    // cout << *t.begin() <<endl;
}