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

ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};

void Main(){
    ll H, W;
    cin >> H >> W;
    string S[H];
    rep(i, H){
        cin >> S[i];
    }
    // vector<vector<ll>> f(H, vector<ll>(W, 0));

    ll ans = 0;
    rep(i, H){
        rep(j, W){

            rep(k, 4){
                // cout << "i,j:" << i  << "," << j;
                ll ni = i + dx[k];
                ll nj = j + dy[k];
                if(ni < 0 || nj < 0 || ni >= H || nj >= W){
                    continue;
                }
                // cout << " ni,nj:" << ni  << "," << nj <<endl;
                if(S[i][j] == '.' && S[ni][nj] == '.'){
                    ans += 1;
                }
            }
        }
    }

    cout << ans / 2  << endl;

}

int main(){
    Main();
}