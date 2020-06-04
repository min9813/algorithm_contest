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
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 130;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;

ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, K, a;
    sll(N);
    sll(K);
    map<ll, ll> status;

    rep(i, N){
        sll(a);
        -- a;
        status[i] = a;
    }

    // for(auto key:status){
        // cout << key.first << ";" << key.second <<endl;
    // }

    ll st = 0;
    vector<ll> junkan(1, st);
    map<ll, ll> searched;
    searched[st] = 0;
    ll next = status[st];
    while(searched.find(next) == searched.end()){
        junkan.emplace_back(next);
        searched[next] = junkan.size() -1;
        next = status[next];
    }

    ll till_junkan_st = searched[next];
    // cout << "till junkan st:" <<till_junkan_st <<endl;
    // cout << "junkan size:" << junkan.size() << endl;
    if(K <= till_junkan_st){
        cout << junkan[K] + 1 << endl;;
    }else{
        ll j_step = K - till_junkan_st;
        ll index = (j_step % (junkan.size()-till_junkan_st));
        cout << junkan[till_junkan_st+index] + 1 << endl;
    }

    // cout << junkan<<endl;

    // ll index = (K % junkan.size());
    // printf("%lld\n", junkan[index]+1);
    

    // printf("%lld\n", ans);


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}