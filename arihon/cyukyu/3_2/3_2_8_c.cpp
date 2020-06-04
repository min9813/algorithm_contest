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

static const ll INF = 1 << 24;
static const ll max_n = 310;
vector<pll> shuffle_list;





ll N, M, P, Q, R;




void Main(){
    // sll(W);
    // sll(H);
    sll(N);
    sll(M);
    sll(P);
    sll(Q);
    sll(R);
    ll x, y;
    rep(i, M){
        sll(x);
        sll(y);

        shuffle_list.emplace_back(x, y);
    }

    // vector<vector<pll>> chunks = {{{1, shuffle_list[0].first}}, {{shuffle_list[0].first+1, shuffle_list[0].second}}, {{shuffle_list[0].second+1, N}}};
    vector<pll> now_chunks = {{1, N}};

    for(ll i=0;i<M;i++){
        vector<vector<pll>> chunks;
        auto shuffle_idx = shuffle_list[i];
        ll pivot = shuffle_idx.first;
        // ll chunk_idx = 0;
        bool is_second = false;
        bool is_last = false;

        vector<pll> small_chunks;
        ll prev = now_chunks[0].first;
        bool is_next_chunk = false;

        ll second_index = 0; // 今注目している新しいchunkのsecondが全体の何番目なのか
        ll first_index = 0;// 今注目している新しいchunkのfirstが全体の何番目なのか
        ll chunk_idx = 0;
        // cout << "shuffle idx:"  << shuffle_idx <<endl;
        for(chunk_idx=0; chunk_idx < now_chunks.size(); chunk_idx++){
            auto now_chunk = now_chunks[chunk_idx];
            first_index = second_index + 1;
            second_index += now_chunk.second - now_chunk.first + 1;
            prev = now_chunk.first;
            // cout << " --- chunk idx = " <<chunk_idx << "--- chunk:"<<now_chunk <<endl;
            // cout << "first index:" << first_index << " second index:" << second_index <<endl;

            // xについての判定
            if(shuffle_idx.first >= second_index){
                small_chunks.emplace_back(now_chunk);
                if(shuffle_idx.first == second_index){
                    chunks.emplace_back(small_chunks);
                    small_chunks.clear();
                }

                continue;
            }else if(first_index <= shuffle_idx.first && second_index >= shuffle_idx.first){
                // このchunkがPを含む時
                // printf("contain first index\n");
                ll input_st = now_chunk.first;
                ll input_end = now_chunk.first + (shuffle_idx.first - first_index);
                small_chunks.emplace_back(input_st, input_end);
                // first_index = shuffle_idx.first+1;
                chunks.emplace_back(small_chunks);
                small_chunks.clear();
                prev = input_end + 1;
            }

            // cout << "ok" <<endl;

            // yについての判定
            if(second_index <= shuffle_idx.second){
                ll input_st = prev;
                ll input_end = now_chunk.second;
                small_chunks.emplace_back(input_st, input_end);
                if(shuffle_idx.second == second_index){
                    chunks.emplace_back(small_chunks);
                    small_chunks.clear();
                }
                continue;
            }else if(first_index <= shuffle_idx.second){
                // yがchunkの間

                ll input_st = prev;
                ll input_end = now_chunk.first + (shuffle_idx.second - first_index);
                // printf("contain second index, input st=%lld, input ed=%lld\n", input_st, input_end);

                small_chunks.emplace_back(input_st, input_end);
                chunks.emplace_back(small_chunks);
                small_chunks.clear();

                prev = input_end + 1;
            }

            // 3番目の山についての判定
            // cout << "ok this for " <<endl;
            small_chunks.emplace_back(prev, now_chunk.second);
            // cout << "small chunks" << small_chunks <<endl;

        }
        chunks.emplace_back(small_chunks);
        small_chunks.clear();
        now_chunks.clear();
        auto temp = chunks[0];
        chunks[0] = chunks[2];
        chunks[2] = temp;

        // cout << "########## shuffle idx = " << i << endl;
        for(auto chunk:chunks){
            for(auto p:chunk){
                // cout << "new chunk:" << p << endl;
                now_chunks.emplace_back(p);
            }
        }
    }

    // for(auto chunk:now_chunks){
    //     cout << chunk << endl;
    // }
    // exit(0);

    ll index = 0;
    ll prev_index = 0;
    ll ans = 0;
    for(auto chunk:now_chunks){
        // cout << "shuffled chunk:" << chunk;
        prev_index = index+1;
        index += chunk.second - chunk.first + 1;
        // cout << " prev index:" << prev_index << " index:" << index << " ans=" << ans <<endl;
        if(prev_index <= P && index >= P){
            // P がchunkの間
            if(Q > index){
                // Pがchunkの間でQがchunkの外
                ll start = chunk.first + (P - prev_index);
                ll end = chunk.second;
                if(start <= R){
                    ans += min(R, end) - start + 1;
                }
            }else{
                // P,Qが同じchunk
                ll start = chunk.first + (P - prev_index);
                ll end = chunk.first + Q - prev_index;
                if(start <= R){
                    ans += min(R, end) - start + 1;
                }
            }
        }else if(prev_index <= Q && index >= Q){
            // Q がchunkの中でPはずっと前
            ll start = chunk.first;
            ll end = chunk.first + Q - prev_index;
            // cout << " only Q in chunk, Q,R=" << Q <<", " << R << " prev index=" << prev_index << " chunk= "<<chunk << "start, end=" <<start << "," <<end<< endl;
            if(start <= R){
                    ans += min(R, end) - start + 1;
            }
        }else if(P <= prev_index && index <= Q){
            // P, Qにchunk全体が挟まれている
            ll start = chunk.first;
            ll end = chunk.second;
            if(start <= R){
                // cout << " in (P Q), R=" <<R <<" chunk start, end=" << chunk  <<endl;
                ans += min(R, end) - start + 1;
            }
        }
    }
    


    cout << ans <<endl;

    
}

int main(){
    Main();

    return 0;

}