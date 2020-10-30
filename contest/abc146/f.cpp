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
static const ll MAX_N = 100010;

// bool field[MAX_N];


void Main(){
    ll N, M;
    string S;
    cin >> N >> M;
    cin >> S;
    ll size = S.size();
    bool is_reach = false;
    vector<ll> path;
    for(ll i=N;i>=0;){
        ll prev_i = i;
        for(ll j=M;j>0;--j){
            if((i-j)>=0 && S[i-j] == '0'){
                i -= j;
                path.emplace_back(j);
                if(i==0){
                    is_reach = true;
                }
                break;
            }
        }
        if(prev_i == i){
            break;
        }

    }

    if(is_reach){
        for(ll i=path.size()-1;i>=0;--i){
            cout << path[i];
            if(i!=0){
                cout << " ";
            }
        }
        cout << "\n";
    }else{
        cout << "-1" <<endl;
    }
}

int main(){
    Main();
}