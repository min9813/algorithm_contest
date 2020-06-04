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
#include <unordered_set>
// #include <prettyprint.hpp>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 100010;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;
vector<ll> height(max_n, -1);
vector<pair<ll,ll>> edge_list(max_n);

ll N, M, Q;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll h, a, b;
    sll(N);
    sll(M);
    rep(i, N){
        sll(h);
        height[i] = h;
    }

    // unordered_set<ll> high_set;
    unordered_set<ll> low_set;
    rep(i, M){
        sll(a);
        sll(b);
        a --;
        b --;
        if(height[a]>height[b]){
            // high_set.insert(a);
            low_set.insert(b);
            // if(high_set.find(b) != high_set.end()){
            //     high_set.erase(b);
            // }
        }else if(height[a]<height[b]){
            low_set.insert(a);
            // high_set.insert(b);
            // if(high_set.find(a) != high_set.end()){
                // low_set.erase(a);
            // }
        }else{
            // if(high_set.find(a)!=high_set.end()){
            //     high_set.erase(a);
            // }

            // if(high_set.find(b) != high_set.end()){
            //     high_set.erase(b);
            // }

            low_set.insert(a);
            low_set.insert(b);
        }
        // edge_list[i] = make_pair(a, b);

    }
    // cout << "low set:" << low_set << endl;

    // rep(i, N){
    //     auto edge = edge_list[i];
    // }

    printf("%lld\n", N-(ll)low_set.size());


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}