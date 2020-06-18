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
// typedef long long ll;
using Int = long long;
typedef double lf;
typedef short int si;

struct SegTree {
    int N;
    vector<Int> A;
    SegTree(int n) {
        N = 1;
        while (N < n) N *= 2;
        A.resize(2 * N);
    }
    void add(int i, Int x) {
        i += N;
        while (i > 0) {
            A[i] += x;
            i >>= 1;
        }
    }
    Int get(int i) {
        return A[i + N];
    }
    Int sum(int L, int R) {
        L += N, R += N;
        Int ans = 0;
        while (L < R) {
            if (L & 1) ans += A[L++];
            if (R & 1) ans += A[--R];
            L >>= 1, R >>= 1;
        }
        return ans;
    }
    int lower_bound(int L, Int x) { // find first sum [L .. pos) >= x
        Int acc = 0;
        auto rec = [&](auto&& rec, int node, int l, int r) {
            if (r <= L) {
                return -1;
            }
            if (l + 1 == r) {
                acc += A[node];
                return acc >= x ? node - N : -1;
            }
            if (L <= l && acc + A[node] < x) {
                acc += A[node];
                return -1;
            }
            int m = (l + r) >> 1, res;
            res = rec(rec, 2*node+0, l, m);
            if (res != -1) return res;
            res = rec(rec, 2*node+1, m, r);
            if (res != -1) return res;
            return -1;
        };
        return rec(rec, 1, 0, N);
    }
};
int main() {
    int N, M, H; cin >> N >> M >> H;
    SegTree st(N + M);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        st.add(cnt++, a);
    }
    for (int i = 0; i < M; i++) {
        string op; Int arg; cin >> op >> arg;
        if (op == "add") {
            st.add(cnt++, arg);
        } else {
            int a = st.lower_bound(0, arg - H + 1);
            int b = st.lower_bound(0, arg + H);
            if (a == -1) {
                cout << "miss\n";
            } else if ((b == -1 && st.sum(0, a + 1) == st.sum(0, N + M)) || a == b) {
                cout << "go\n";
                st.add(a, (-1) * st.get(a));
            } else {
                cout << "stop\n";
            }
        }
    }
    return 0;
}