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
#define v(t) vector<t>
typedef long long ll;
typedef double lf;
typedef short int si;

static const ll max_x = 45;
static const ll m_max_x = -20;

void Main(){
    ll n, r, xl, xr, h;
    v(lf) answers;
    while(cin >> r >> n){
        if(r ==0 ) break;
        if(n == 0){
            answers.emplace_back(0);
            continue;
        }
        v(ll) fhs(max_x, 0);
        // ll min_xl = -1;
        // ll max_xr = 1;
        rep(i, n){
            cin >> xl >> xr >> h;
            xl -= m_max_x;
            xr -= m_max_x;
            // min_xl = min(xl, min_xl);
            // max_xr = max(xr, max_xr);
            // ll max_h = max(h, fhs[xl+1]);
            for(ll j=xl+1;j<xr+1;++j){
                fhs[j] = max(h, fhs[j]);
            }
        }
        vector<pair<lf, lf>> points;
        v(ll) indices;

        rep(i, fhs.size()-1){
            // if(i < min_xl - 1 || i > max_xr + 1) continue;
            indices.emplace_back(i);
            lf point_x = (lf)i+1;
            lf point_y = (lf)fhs[i+1];
            points.emplace_back(point_x, point_y);
            // point_x = (lf)i + 1;
            if(fhs[i] == fhs[i+1]) continue;
            point_y = (lf)fhs[i];
            points.emplace_back(point_x, point_y);
        }
        indices.emplace_back(fhs.size()-1);

        lf sx = -m_max_x + 1;
        lf sy = - r;
        // ll num = 0;
        // cout << "ok" <<endl;
        lf delta = 0.00005;
        for(;sy<=21;sy+=delta){
            bool is_break = false;
            rep(i, points.size()){
                lf dy = sy - points[i].second;
                lf dx = sx - points[i].first;
                // cout << "sy=" << sy << " sx=" << sx << " points[" << i << "]=" << points[i] <<endl;
                lf total_d = dx * dx + dy * dy;
                if(total_d < r * r) {
                    is_break = true;
                    break;
                }
            }
            if(is_break){
                break;
            }
        }
        // cout << "ok" <<endl;
        sy -= delta;
        lf ans = sy - (-r);
        // cout << ans << " sy=" << sy << " r=" << -r <<endl;
        answers.push_back(ans);
        // cout << points << endl;

        // rep(i, fhs.size()){
        //     cout << indices[i] << "," << fhs[i] <<endl;
        // }

    }

    rep(i, answers.size()){
        cout << fixed << setprecision(10) << answers[i] <<endl;
    }
}

int main(){
    Main();
}