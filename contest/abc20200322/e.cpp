#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
// #include <prettyprint.hpp>
using namespace std;
typedef long long ll;
static const ll max_h = 12;
static const ll max_w = 1010;
static const ll max_rgb = 300010;
static const ll max_num = 1000000000000000;
// static const ll mod = 1000000007;
vector<vector<ll>> F(max_h, vector<ll>(max_w, 0));
ll ans = 0;
ll H, W, K;

void solve(ll st_w, ll ed_w, ll st_h, ll ed_h){
    ll total = 0;;
    for(ll i=st_h;i<=ed_h;i++){
        total = 0;
        for(ll j=st_w;j<=ed_w;j++){
            total = total + F[i][j];
            if(total > K){
                ans ++;
                total = total - K;
            }
        }
    }
}

ll dfs(vector<bool> bit){
    // cout << "bit = " << bit << endl;
    if((int)bit.size()==H-1){
        ll ans = 0;
        for(const bool &b:bit){
            ans += (ll)b;
        }
        vector<ll> count(H, 0);
        for(ll i=0;i<W;i++){
            vector<ll> next_count(H, 0);
            int block_idx = 0;
            bool is_ok = true;
            for(ll j=0;j<H;j++){
                // printf("i=%lld, j=%lld, next count: %lld\n", i, j, next_count[block_idx]);
                // printf("i=%lld, j=%lld, count: %lld\n", i, j, count[block_idx]);
                next_count[block_idx] += F[j][i];
                if(next_count[block_idx] + count[block_idx]>K){
                    is_ok = false;
                    break;
                }
                if(j<H-1 && bit[j]){
                    block_idx ++;
                }
            }
            if(is_ok){
                for(ll j=0;j<H;j++){
                    count[j] += next_count[j];
                };
            }else{
                // printf("too many!\n");
                // ans = 0;
                fill(count.begin(), count.end(), 0);
                is_ok = true;
                // ll total_count = 0;
                for(ll j=0;j<H;j++){
                    count[block_idx] += F[j][i];
                    if(count[block_idx]>K){
                        is_ok = false;
                        break;
                    }
                    if(bit[j]){
                        block_idx ++;
                    }
                }
                if(is_ok){
                    ans ++;
                    // count = next_count;
                }else{
                    // printf("return max num\n");
                    return max_num;
                }
            }

        }
        // printf("return answer = %lld\n", ans);
        return ans;

    }else{
        bit.push_back(0);
        ll ans = dfs(bit);
        bit.pop_back();
        bit.push_back(1);
        ans = min(ans, dfs(bit));
        return ans;
    }

    
}

int main(){
    // int u, v;
    // bool updated = false;
    // ll ans = 0;
    char s;
    scanf("%lld %lld %lld", &H, &W, &K);

    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            cin >> s;
            if(s == '0'){
                F[i][j] = 0;
            }else{
                F[i][j] = 1;
            }
        }
    }
    // for(ll i=0;i<H;i++){
    //     for(ll j=0;j<W;j++){
    //         cout << F[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    // exit(1);
    // printf("ok!");
    // vector<bool> bit_vec;

    // // solve(0, W-1, 0, H-1);
    // ll ans = dfs(bit_vec);
    ll ans = max_num;
    for(ll i=0;i<(1<<(H-1));i++){
        vector<ll> a;
        ll num = 1;
        ll this_ans = 0;
        bool add_flag = false;
        bool ok_flag = true;
        for(ll j=0;j<H-1;j++){
            if((i>>j)&1){
                a.emplace_back(num);
                this_ans ++;
                num = 0;
            }
            num ++;
        }
        a.push_back(num);
        // cout << "H block:" << a << endl;
        ll block_num = a.size();
        vector<ll> num_white_total(block_num, 0);
        vector<ll> num_white_cur(block_num, 0);
        for(ll j=0;j<W;j++){
            ll h_idx = 0;
            for(ll k=0;k<a.size();k++){
                for(ll m=0;m<a[k];m++){
                    num_white_cur[k] += F[h_idx][j];
                    h_idx ++;
                }
            }
            // cout << "h idx:"<<h_idx <<endl;

            for(ll k=0;k<block_num;k++){
                if(num_white_cur[k]+num_white_total[k]>K){
                    add_flag = true;
                    break;
                }
            }
            if(add_flag){
                // printf("add at i=%lld, j=%lld\n", i, j);
                for(auto v:num_white_cur) ok_flag &= (v <= K);
                if(!ok_flag){
                    // cout << num_white_cur << endl;
                    // printf("NG, get out !\n");
                    break;
                }else{
                    // printf("--- Now white num ! ---\n");
                    // cout << num_white_cur << endl;
                    // printf("--- prev total white num ! ---\n");
                    // cout << num_white_total << endl;
                    for(ll k=0;k<block_num;k++){
                        num_white_total[k] = num_white_cur[k];
                    }
                    // printf("--- after total white num ! ---\n");
                    // cout << num_white_total << endl;
                    this_ans ++;
                    add_flag = false;
                }
            }else{
                for(ll k=0;k<block_num;k++){
                    num_white_total[k] += num_white_cur[k];
                }
            }
            fill(num_white_cur.begin(), num_white_cur.end(), 0);
        }
        if(ok_flag){
            ans = min(ans, this_ans);
        }
        // exit(1);

    }
    printf("%lld\n", ans);
    
    // double limit = 1. / (double)(4 * M);



    return 0;

}