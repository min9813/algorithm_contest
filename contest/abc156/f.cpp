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
    ll k, q, n, x, m;
    cin >> k >> q;
    vector<ll> org(k, 0);
    vector<ll> org_cum(k, 0);
    vector<ll> mods(k, 0);
    vector<ll> mod_sum(k+1, 0);
    vector<ll> zero_num(k+1, 0);
    rep(i, k){
        sll(org[i]);
    }
    // org_cum[0] = org[0];

    // rep(i, k-1){
    //     org_cum[i+1] = org_cum[i] + org[i+1];
    // }
    // cout << org_cum << endl;

    rep(i, q){
        cin >> n >> x >> m;
        // mod_cum[0] = x % m;
        ll one_num = 0;
        ll res = (n-2) % k;
        ll times = (n-2) / k;
        ll res_num = 0;
        // ll mod_sum = 0;
        rep(i, k){
            mods[i] = org[i] % m;
            zero_num[i+1] = (mods[i]== 0) + zero_num[i];
            mod_sum[i+1] = mods[i] + mod_sum[i];
        }
        // calc add num
        ll add_num = times * mod_sum[k] + mod_sum[res+1] + x;

        // cout << mod_sum << endl;
        ll small_num = add_num / m - x / m;
        ll equal_num = times * zero_num[k] + zero_num[res+1];

        // cout << "times=" << times << " add_num=" << add_num << " zeronum=" << zero_num << " res=" << res << endl;

        cout << n-1 - (small_num + equal_num) <<endl;

    }

}

int main(){
    Main();
    // string S = "ksdfjl";
    // char v = S[3];
    // S[3] = 'a';
    // cout << S <<endl;
}