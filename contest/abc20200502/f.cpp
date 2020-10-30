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
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll, ll>
typedef long long ll;
typedef double lf;
static const ll max_n = 200010;
static const ll mod = 1000000007;
static const ll INF = 100000000000100;

ll N, M;

ll as[max_n];
vector<ll> dp(max_n, INF);
vector<ll> edges[max_n];
ll ans[max_n];

pll dfs(ll st, ll pr, ll max_l){
    ll this_v = as[st];
    auto index = lower_bound(dp.begin(), dp.end(), this_v);
    ll value = *index;
    ll dist = index - dp.begin();
    dp[dist] = this_v;
    ll this_ans = max(max_l, dist+1);
    ans[st] = this_ans;
    // cout << "st=" << st << " prev="<<pr << " dist="<< dist << " old_v=" << value << " new_v=" << this_v << endl;
    for(ll nu: edges[st]){
        if(nu == pr) continue;
        auto org_v = dfs(nu, st, this_ans);
        // cout << " nu =" << nu << " org_v=" << org_v <<endl;
        dp[org_v.second] = org_v.first;
    }

    return make_pair(value, dist);
}

void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, u, v;
    cin >> N;
    rep(i, N){
        cin >> as[i];
    }

    rep(i, N-1){
        cin >> u >> v;
        -- u;
        -- v;
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    dfs(0, 0, 0);

    rep(i, N){
        cout << ans[i] <<endl;
    }
    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    // vector<ll> test = {1, 3, 5, 10};
    // auto it = lower_bound(test.begin(), test.end(), 4);
    // cout << *it << " index=" << it-test.begin() << endl;
    Main();

    return 0;

}