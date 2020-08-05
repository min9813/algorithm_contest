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
// #include <prettyprint.hpp>a
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
    ll N, M, s, t;
    cin >> N >> M;
    if(N>1 && M == 0){
        string ans = "1";
        rep(i, N-1){
            ans += '0';
        }
        cout << ans <<endl;
    }else if(N==1 && M == 0){
        cout << "0" <<endl;
    }else{
        map<ll,ll> q;
        vector<char> ans(N, '0');
        ans[0] = '1';
        bool is_ok = true;
        rep(i, M){
            cin >> s >> t;
            if(q.find(s) != q.end() && q[s] != t){
                is_ok = false;
            }
            q[s] = t;
        }
        if(is_ok){
            string a = "";
            for(auto p:q){
                ans[p.first-1] = '0' + p.second;
            }
            for(auto s:ans){
                a += s;
            }
            if(a[0] == '0' && N > 1){
                cout << "-1" <<endl;
            }else{
                cout << a <<endl;
            }
        }else{
            cout << "-1" <<endl;
        }
    }
}

int main(){
    Main();
}