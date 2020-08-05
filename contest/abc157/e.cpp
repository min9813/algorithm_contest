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
    ll N, Q, i, l, r;
    char c;
    string S;
    vector<set<ll>> cs(26);
    cin >> N;
    cin >> S;
    cin >> Q;
    rep(i, N){
        cs[S[i]-'a'].insert(i);
    }
    rep(j, Q){
        sll(i);
        if(i==1){
            sll(l);
            cin >> c;
            -- l;
            cs[S[l]-'a'].erase(l);
            cs[c-'a'].insert(l);
            S[l] = c;
        }else
        {
            sll(l);
            sll(r);
            -- l;
            ll num = 0;
            rep(k, 26){
                auto st_iter = cs[k].lower_bound(l);
                if(st_iter != cs[k].end() && *st_iter<r){
                    ++ num;
                }

                // auto end_iter = upper_bound(p.second.begin(), p.second.end(), r);

                // cout << "i=" << i << " l=" << l << " r=" << r << " end_it,st_it=" << *end_iter<<"," << *st_iter<<endl;
            }
            printf("%lld\n", num);
        }
        
    }


}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}