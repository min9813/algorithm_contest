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
    string S;
    cin >> S;
    ll N = S.size();
    ll next_up = 0;
    ll num = 0;
    bool no_zero = false;
    vector<ll> nums(N+1);
    vector<ll> pay(N+1);
    vector<ll> res(N+1);
    for(ll i=N-1;i>=0;--i){
        ll this_d = S[i] - '0';
        no_zero = no_zero || (this_d != 0);
        if(this_d+next_up >= 6){
            pay[N-i-1] = 0;
            res[N-i-1] = 10 - (this_d + next_up);
            ll this_add = next_up == 1;
            num += (10 - this_d - this_add);
            nums[N-1-i] = (10 - this_d - this_add);
            next_up = 1;
        }else{
            if(this_d + next_up == 5 && i!= 0 && (S[i-1]-'0')>=5){
                pay[N-i-1] = 0;
                res[N-i-1] = 10 - (this_d + next_up);
                ll this_add = next_up == 1;
                num += (10 - this_d - this_add);
                nums[N-1-i] = (10 - this_d - this_add);
                next_up = 1;
            }else{
                pay[N-i-1] = this_d + next_up;
                res[N-i-1] = 0;
                num += this_d + next_up;
                nums[N-1-i] = this_d + next_up;
                next_up = 0;
            }
        }
    }
    num += next_up;
    nums[N] = next_up;
    pay[N] = next_up;
    res[N] = 0;
    // cout << " pay " <<endl;
    // rep(i, N+1){
    //     cout << pay[N-i];
    // }
    // cout << endl;
    // cout << " res " <<endl;

    // rep(i, N+1){
    //     cout << res[N-i];
    // }
    // cout << endl;

    // rep(i, N+1){
    //     cout << nums[N-i];
    // }
    // cout << endl;
    cout << num <<endl;

}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}