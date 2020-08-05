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
    rep(i, 3){
        rep(j, 3){
            sll(field[i][j]);
        }
    }
    ll N, b;
    cin >> N;
    set<ll> ps;
    rep(i, N){
        sll(b);
        rep(i, 3){
            rep(j, 3){
                if(field[i][j] == b){
                    ps.insert(i*3+j);
                    break;
                }
            }
        }
    }

    bool is_ok = false;
    bool naname1_ok = true;
    bool naname2_ok = true;
    rep(i, 3){
        bool this_ok = true;
        bool tate_ok = true;
        rep(j, 3){
            this_ok = this_ok && ps.find(i*3+j) != ps.end();
            tate_ok = tate_ok && ps.find(j*3+i) != ps.end();
        }
        is_ok = is_ok || this_ok;
        is_ok = is_ok || tate_ok;
        naname1_ok = naname1_ok && ps.find(coord1[i]) != ps.end();
        naname2_ok = naname2_ok && ps.find(coord2[i]) != ps.end();
    }
    if(is_ok || naname1_ok || naname2_ok){
        cout << "Yes" <<endl;
    }else{
        cout << "No" <<endl;
    }
    

}

int main(){
    Main();
}