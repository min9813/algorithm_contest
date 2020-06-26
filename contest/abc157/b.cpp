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

vector<vector<ll>> field(3, vector<ll>(3, 0));
vector<ll> coord1 = {0, 4, 8};
vector<ll> coord2 = {2, 4, 6};
void Main(){
    ll a;
    rep(i, 3){
        rep(j, 3){
            sll(a);
            field[i][j] = a;
        }
    }
    ll N;
    sll(N);
    set<ll> numbers;
    rep(i, N){
        sll(a);
        numbers.insert(a);
    }
    bool is_ok = false;
    rep(i, 3){
        bool ris_ok = true;
        bool cis_ok = true;
        rep(j, 3){
            ris_ok = ris_ok && (numbers.find(field[i][j]) != numbers.end());
            cis_ok = cis_ok && (numbers.find(field[j][i]) != numbers.end());
        }
        is_ok = is_ok || ris_ok;
        is_ok = is_ok || cis_ok;
    }

    bool e_is_ok = true;
    for(auto c:coord1){
        e_is_ok = e_is_ok && (numbers.find(field[c/3][c%3]) != numbers.end());
    }

    bool f_is_ok = true;
    for(auto c:coord2){
        f_is_ok = f_is_ok && (numbers.find(field[c/3][c%3]) != numbers.end());
    }

    is_ok = is_ok || (e_is_ok) || (f_is_ok);
    if(is_ok){
        cout << "Yes" <<endl;
    }else{
        cout << "No" <<endl;
    }


}

int main(){
    Main();
}