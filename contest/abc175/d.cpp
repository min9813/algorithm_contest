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


void Main(){
    ll N, K, p, c;
    cin >> N >> K;
    vector<ll> ps(N, 0);
    vector<ll> cs(N, 0);
    vector<bool> searched(N, false);
    vector<vector<ll>> groups;
    rep(i, N){
        sll(p);
        -- p;
        ps[i] = p;
    }

    rep(i, N){
        sll(c);
        // -- c;
        cs[i] = c;
    }


    rep(i, N){
        if(searched[i]){
            continue;
        }
        vector<ll> group;
        searched[i] = true;
        ll next_v = ps[i];
        group.emplace_back(i);
        while(next_v != i){
            searched[next_v] = true;
            group.emplace_back(next_v);
            next_v = ps[next_v];
        }

        groups.emplace_back(group);
    }

    // vector<vector<ll>> counters(groups.size());
    // vector<ll> group_scores(groups.size());
    ll index = 0;
    ll ans = -1e15;
    for(auto group:groups){
        vector<ll> counter(group.size()*2, 0);
        ll org_index;
        rep(i, group.size()*2-1){
            org_index = group[(i+1)%group.size()];
            counter[i+1] = counter[i] + cs[org_index];
        }
        // counters[index] = counter;
        // group_scores[index] = counter[group.size()];
        ll num_circle = K / group.size();
        ll num_inc = K % group.size();
        ll first_v;
        if(counter[group.size()]>0){
            first_v = 0;
        }else{
            first_v = cs[org_index];
        }
        ll max_add_score_num_inc = first_v;
        ll max_add_score_all = first_v;
        rep(i, group.size()){
            rep(j, group.size()){
                if(j==0){
                    continue;
                }
                if(j<=num_inc){
                    max_add_score_num_inc = max(max_add_score_num_inc, counter[i+j]-counter[i]);
                }
                max_add_score_all = max(max_add_score_all, counter[i+j]-counter[i]);
            }
            // max_add_score = max(max_add_score, counter[i+num_inc]-counter[i]);
        }

        ll this_ans;
        if(counter[group.size()] < 0){
            if(K>=group.size()){
                this_ans = max_add_score_all;
            }else{
                this_ans = max_add_score_num_inc;
            }
        }else{
            // ans = max(ans, );
            this_ans = num_circle*counter[group.size()]+max_add_score_num_inc;
            this_ans = max(this_ans, (num_circle-1)*counter[group.size()]+max_add_score_all);
        }
        ans = max(ans, this_ans);
        // cout << " #####  index = " << index << "  K=" << K <<" num_c, num_i=" << num_circle << "," << num_inc << endl;
        // cout << "group:" << group << " counter:" << counter << " g_score:" << counter[group.size()] << " max add score:" << max_add_score_all << " max_add_score_num_inc:" << max_add_score_num_inc << endl;
        ++ index;
    }

    cout << ans <<endl;


}

int main(){
    Main();
}