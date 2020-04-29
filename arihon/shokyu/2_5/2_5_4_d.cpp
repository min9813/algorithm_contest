#pragma GCC optimize("O2")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define whlie while
#define retunr return
#define reutrn return
#define reutnr return
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define inf 1001001001
#define infLL (1LL << 61)
#define FOR(i, a, b) for (int(i) = (int)(a); (i) < (int)(b); (i)++) // [a,b)
#define rep(i, N) FOR((i), 0, (int)(N))                             // [0,N)
#define FORR(i, a, b) for (int(i) = (int)(b)-1; (i) >= (int)(a); (i)--)
#define repr(i, N) FORR((i), 0, (int)(N))
#define each(x, v) for (auto &x : v)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define vrep(v, it) for (auto it = v.begin(); it != v.end(); it++)
#define vrepr(v, it) for (auto it = v.rbegin(); it != v.rend(); it++)
#define ini(...)     \
    int __VA_ARGS__; \
    in(__VA_ARGS__)
#define inl(...)    \
    ll __VA_ARGS__; \
    in(__VA_ARGS__)
#define inc(...)      \
    char __VA_ARGS__; \
    in(__VA_ARGS__)
#define ins(...)        \
    string __VA_ARGS__; \
    in(__VA_ARGS__)
#define ind(...)        \
    double __VA_ARGS__; \
    in(__VA_ARGS__)
#define inpii(...)   \
    pii __VA_ARGS__; \
    in(__VA_ARGS__)

#ifdef LOCAL
#define trc(...)                       \
    do                                 \
    {                                  \
        cout << #__VA_ARGS__ << " = "; \
        dbg_out(__VA_ARGS__);          \
    } while (0)
#define stopif(val) assert(!(val))
#define trcv(v, ...)                    \
    do                                  \
    {                                   \
        cout << #v << " = ";            \
        vector_debug(v, ##__VA_ARGS__); \
        cout << endl;                   \
    } while (0)
#else
#define trc(...)
#define stopif(...)
#define trcv(...)
#endif

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vector<int>>;

struct IoSetupNya
{
    IoSetupNya()
    {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
        cerr << fixed << setprecision(15);
    }
} iosetupnya;

int gcd(int a, int b)
{
    if (a > b)
        swap(a, b);
    return a == 0 ? b : gcd(b % a, a);
}
ll gcd(ll a, ll b)
{
    if (a > b)
        swap(a, b);
    return a == 0 ? b : gcd(b % a, a);
}
ll lcm(int a, int b) { return (1LL * a / gcd(a, b)) * b; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
inline ll pow(int a, int b)
{
    ll ans = 1;
    rep(i, b) ans *= a;
    return ans;
}
inline ll pow(ll a, ll b)
{
    ll ans = 1;
    rep(i, b) ans *= a;
    return ans;
}
inline ll pow(int a, ll b)
{
    ll ans = 1;
    rep(i, b) ans *= a;
    return ans;
}
inline ll pow(ll a, int b)
{
    ll ans = 1;
    rep(i, b) ans *= a;
    return ans;
}
template <typename T, typename U>
inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template <typename T, typename U>
inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template <typename C>
inline void _cin(C &c) { cin >> c; }
template <typename T, typename U>
inline void _cin(pair<T, U> &p)
{
    cin >> p.fi;
    cin >> p.se;
}
template <typename C>
inline void _cout(const C &c) { cout << c; }
template <typename T, typename U>
inline void _cout(const pair<T, U> &p) { cout << p.fi << ' ' << p.se; }
void in() {}
template <typename T, class... U>
void in(T &t, U &... u)
{
    _cin(t);
    in(u...);
}
void out() { cout << "\n"; }
template <typename T, class... U>
void out(const T &t, U... u)
{
    _cout(t);
    if (sizeof...(u))
        cout << ' ';
    out(u...);
}
template <typename C>
inline void in(vector<C> &v, int N = -1)
{
    if (sz(v) != 0)
    {
        int M = (N == -1) ? sz(v) : N;
        rep(i, M) _cin(v[i]);
    }
    else
    {
        C c;
        rep(i, N) v.pb((_cin(c), c));
    }
}
template <typename C>
inline void in(C v[], int N) { rep(i, N) _cin(v[i]); }
template <typename C>
inline void out(const vector<C> &v, int N = -1)
{
    int M = (N == -1) ? sz(v) : N;
    rep(i, M)
    {
        cout << ((i) ? " " : "");
        _cout(v[i]);
    }
    cout << "\n";
}
template <typename C>
inline void out(C v[], int N)
{
    rep(i, N)
    {
        cout << ((i) ? " " : "");
        _cout(v[i]);
    }
    cout << "\n";
}
template <typename C>
inline void vector_debug(const vector<C> &v, int N = -1)
{
    cout << "{";
    int M = (N == -1) ? sz(v) : N;
    rep(i, M)
    {
        cout << ((i) ? ", " : "");
        _cout(v[i]);
    }
    cout << "}";
}
template <typename C>
inline void vector_debug(C v[], int N)
{
    cout << "{";
    rep(i, N)
    {
        cout << ((i) ? ", " : "");
        _cout(*(v + i));
    }
    cout << "}";
}
void dbg_out() { cout << endl; }
template <typename T, class... U>
void dbg_out(const T &t, U... u)
{
    _cout(t);
    if (sizeof...(u))
        cout << ", ";
    dbg_out(u...);
}
template <typename C, class... U>
void dbg_out(const vector<C> &v, U... u)
{
    vector_debug(v);
    if (sizeof...(u))
        cout << ", ";
    dbg_out(u...);
}
template <typename C, class... U>
void dbg_out(const vector<vector<C>> &v, U... u)
{
    cout << "{ ";
    rep(i, sz(v))
    {
        if (i)
            cout << ", ";
        vector_debug(v[i]);
    }
    cout << " }";
    if (sizeof...(u))
        cout << ", ";
    dbg_out(u...);
}
template <typename C>
inline C vmax(const vector<C> &v)
{
    C n = v[0];
    rep(i, sz(v)) amax(n, v[i]);
    return n;
}
template <typename C>
inline C vmax(C v[], int N)
{
    C n = v[0];
    rep(i, N) amax(n, v[i]);
    return n;
}
template <typename C>
inline C vmin(const vector<C> &v)
{
    C n = v[0];
    rep(i, sz(v)) amin(n, v[i]);
    return n;
}
template <typename C>
inline C vmin(C v[], int N)
{
    C n = v[0];
    rep(i, N) amin(n, v[i]);
    return n;
}
void die(string s)
{
    out(s);
    exit(0);
}
#define rand mtrand
#define randinit()          \
    random_device seed_gen; \
    mt19937_64 mtrand(seed_gen())

#define MOD 1000000007

////////////
/// main ///
////////////

template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int to) : src(-1), to(to), cost(0) {}
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    { // edge e = n; とできる(e.to = n)
        to = x;
        return *this;
    }

    // int()をオーバーロードすることで重み付きグラフと普通のグラフでライブラリを共用できる
    operator int() const { return to; } // v[e]とできる ( v[e.to]に同じ )
};

// sort用 とりあえずcostの小さいほうが左としているが適宜書き換えて使いましょう
/**
template<typename T>
bool operator <(const edge<T>& e1,const edge<T>& e2){ 
  return e1.cost < e2.cost;
}//*/
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WG = vector<Edges<T>>;
template <typename T>
using UWG = vector<vector<int>>;

// ベルマンフォード法
// 負閉路がないときは配列Aにsからの最短距離を格納してtrueを返す
// 負閉路があるときにfalseを返す 計算量 O(頂点数N * 辺の数E)
// s 始点 A メモ用ベクトル es 辺
// (Aはinfで初期化済　0<A.size()&&(点の数)<=A.size()が必要)
template <typename T, T UNIT>
bool bellman(int s, vector<T> &A, Edges<T> &es)
{
    int N = int(A.size());
    A[s] = 0;
    rep(i, N)
    {
        bool update = false;
        for (auto &e : es)
        {
            if (A[e.src] == UNIT)
                continue;
            update |= amin(A[e.to], A[e.src] + e.cost);
        }
        if (A[0] < 0)
            return false;
        if (!update)
            return true;
    }
    return false;
}

int main()
{
    auto start = clock();
    ini(N, M);
    Edges<ll> es;
    es.reserve(N * 6);
    vl memo(2 * N + 1, infLL);
    // 始点 0 e[i]...i+1 g[i]...N + i+1とする
    rep(i, N)
    {
        inl(P);
        es.eb(i + 1, 0, 0);
        es.eb(0, i + 1, P);
    }
    rep(i, N)
    {
        inl(Q);
        es.eb(0, N + i + 1, 0);
        es.eb(N + i + 1, 0, Q);
    }
    rep(k, M)
    {
        inl(X, Y, A, B);
        es.eb(X, Y + N, -A);
        es.eb(Y + N, X, B);
    }
    //each(e,es) trc(e.src,e.to,e.cost);
    trc(clock() - start);
    /* */
    bool ans = bellman<ll, infLL>(0, memo, es);
    //trc(memo);
    out(ans ? "yes" : "no");
    trc(clock() - start);
    //*/
}