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

static const ll max_n = 1510;
static const ll max_v = 1e15;
static const string TIE = "TIE";
vector<char> ns[max_n];

void Main(){
    ll n;
    char a;
    ll num_d;
    rep(i, max_n){
        cin >> n;
        vector<char> as(n);
        if(n == 0){
            num_d = i;
            break;
        }
        rep(j, n){
            cin >> a;
            as[j] = a;
        }

        ns[i] = as;
    }

    rep(i, num_d){
        auto as = ns[i];
        n = as.size();
        map<char, ll> counter;
        ll this_id = -1;
        char this_c;
        ll now_max = -1;
        char now_max_c;
        rep(j, n){
            char c = as[j];
            counter[c] ++;
            ll now_c_num = counter[c];
            if(now_max < now_c_num){
                now_max = now_c_num;
                now_max_c = c;
            }
            ll max_other_add = n - j - 1;
            ll max_other = max_other_add;
            for(auto p:counter){
                if(p.first == now_max_c) continue;
                max_other = max(p.second+max_other_add, max_other);
            }
            if (now_max > max_other){
                this_c = now_max_c;
                this_id = j+1;
                break;
            }
        }

        if(this_id == -1){
            cout << TIE <<endl;
        }else{
            cout << this_c << " " << this_id << endl;
        }
    }

}

int main(){
    Main();
}