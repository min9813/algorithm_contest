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


void Main(){
    string S, in_s;
    string left_s="", right_s="";
    cin >> S;
    ll Q, t, f;
    sll(Q);
    bool is_reverse = false;
    bool now_order = false;
    rep(i, Q){
        sll(t);
        if(t == 1){
            is_reverse = !is_reverse;
        }else{
            sll(f);
            cin >> in_s;
            now_order = is_reverse;
            if(is_reverse){
                if(f==1){
                    right_s = right_s + in_s;
                }else{
                    left_s = in_s + left_s;
                }
                // right_s[::-1] + S[::-1] + left_s[::-1]
            }else{
                if(f==1){
                    left_s = in_s + left_s;
                }else{
                    right_s = right_s + in_s;
                }
                // left_s + S + right_s;
            }
        }
        // cout << " is reverse:" <<is_reverse << endl;;
    }

    // cout << "left s:" << left_s << " right s " << right_s <<endl;
    string concat="";
    if(now_order){
        // concat = right_s;
        for(ll i=right_s.size()-1;i>=0;i--){
            concat += right_s[i];
        }
        for(ll i=S.size()-1;i>=0;i--){
            concat += S[i];
        }
        for(ll i=left_s.size()-1;i>=0;i--){
            concat += left_s[i];
        }
    }else{
        concat = left_s + S + right_s;
    }

    string ans = "";
    if(is_reverse!=now_order){
        for(ll i=concat.size()-1;i>=0;i--){
            ans += concat[i];
        }
        cout << ans <<endl;
    }else{
        ans = concat;
        cout << ans <<endl;
    }
    


}

int main(){
    Main();
}