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

static const char l = '(';
static const char r = ')';

struct trip{
    ll l; ll r; char m;
    trip(ll l, ll r, char m): l(l), r(r), m(m){}
    bool operator<(const trip& n1){
        return l < n1.l;
    }
};

void Main(){
    string S;
    vector<ll> answers;
    while(cin>>S){
        if(S=="#") break;
        map<ll, ll> counter;
        ll life = 0;
        ll add = 0;
        char mode;
        ll left, right;
        vector<trip> regions;
        char now_c;
        rep(i, S.size()){
            now_c = S[i];
            if(i == 0){
                mode = now_c;
                left = i;
                right = i + 1;
                continue;
            }
            if(now_c == mode){
                right = i + 1;
            }else{
                regions.emplace_back(left, right, mode);
                left = i;
                right = i + 1;
                mode = now_c;
            }
        }
        regions.emplace_back(left, right, now_c);
        ll start_i;
        if(regions[0].m == r){
            start_i = 1;
            ll diff = regions[0].r - regions[0].l;
            add += (diff / 2 + diff % 2);
        }else{
            start_i = 0;
        }
        ll i;
        for(i=start_i;i<regions.size()-1;i+=2){
            auto t = regions[i];
            auto nt = regions[i+1];
            ll num1 = t.r - t.l;
            ll num2 = nt.r - nt.l;
            if(num1 > num2 * 2){
                ll diff = num1 - num2 * 2;
                add += diff /2 + diff % 2;
            }else if(num2 > num1 * 2){
                ll diff = num2 - num1 * 2;
                add += diff /2 + diff % 2;
            }
        }
        if(i == regions.size()-1){
            auto t = regions[i];
            ll diff = t.r - t.l;
            add += (diff / 2 + diff % 2);
        }
        answers.emplace_back(add);
    }

    rep(i, answers.size()){
        cout << answers[i] <<endl;
    }
    

}

int main(){
    Main();
}