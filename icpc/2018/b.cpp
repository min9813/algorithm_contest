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
#define repi(i, n) for (int i = 0; i < n; ++i)
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define repinvi(i, n) for (int i = n - 1; i >= 0; --i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll, ll>
#define pii pair<int, int>
#define psi pair<si, si>
#define v(t) vector<t>
typedef long long ll;
typedef double lf;
typedef short int si;

void Main()
{
    ll n, m, t, p, x, y;
    v(ll) answers;
    while (cin >> n >> m >> t >> p)
    {
        if (n == 0)
            break;
        v(ll) folds(t);
        v(ll) coords(t);
        // v(ll) ps(p);

        rep(i, t)
        {
            cin >> folds[i] >> coords[i];
        }
        // v(ll) yoko(n+1, 1);
        // v(ll) tate(m+1, 1);
        v(v(ll)) fs(n + 1, v(ll)(m + 1, 1));
        ll yoko_o = 0;
        ll tate_o = 0;
        rep(i, t)
        {
            // v(ll) now_yoko(n+1, 0);
            // v(ll) now_tate(m+1, 0);
            v(v(ll)) now_f(n + 1, v(ll)(m + 1, 0));
            ll f = folds[i];
            ll c = coords[i];
            // ll now_w = n - yoko_o;
            // ll now_h = m - tate_o;
            if (f == 1)
            {
                rep(wi, n)
                {
                    rep(hi, m)
                    {
                        if (c-wi-1 >= 0)
                        {
                            now_f[wi][hi] += fs[c-wi-1][hi];
                        }
                        if (wi + c < n)
                        {
                            now_f[wi][hi] += fs[wi + c][hi];
                        }
                    }
                }
            }
            else
            {
                rep(wi, n)
                {
                    rep(hi, m)
                    {
                        if (c-hi-1 >= 0)
                        {
                            now_f[wi][hi] += fs[wi][c-hi-1];
                        }
                        if (hi + c < m)
                        {
                            now_f[wi][hi] += fs[wi][hi + c];
                        }
                    }
                }
            }
            // cout << "i == " << i << endl;
            // rep(j, n){
            //     cout << now_f[j] <<endl;
            // }
            // cout << " prev field " << endl;
            // rep(j, n){
            //     cout << fs[j] <<endl;
            // }
            fs = now_f;

        }

        ll ans = 0;
        rep(i, p)
        {
            cin >> x >> y;
            // ans += fs[x][y];
            answers.emplace_back(fs[x][y]);

        }
    }

    rep(i, answers.size())
    {
        cout << answers[i] << endl;
    }
}

int main()
{
    Main();
}