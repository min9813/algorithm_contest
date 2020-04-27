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
using namespace std;
typedef long long ll;
static const ll max_n = 200010;

string alphabet = "abcdefghijklmnop";
map<char, ll> alphabet_idx;
ll N, X, Y;

int main(){
    // int u, v;
    // bool updated = alse;
    scanf("%lld", &N);
    for(auto s:alphabet){
        alphabet_idx[s] = alphabet_idx.size();
    }

    queue<string> Q;
    Q.push("a");
    // set<string> S;
    while(!Q.empty()){
        string top = Q.front(); Q.pop();
        ll size = top.size();
        ll max_size = 0;
        for(auto s:top){
            max_size = max(max_size, alphabet_idx[s]);
        }
        if(size==N){
            printf("%s\n", top.c_str());
            continue;
        }

        for(ll i=0;i<=max_size+1;i++){
            string new_top = top + alphabet[i]; 
            if(new_top.size()==N){
                printf("%s\n", new_top.c_str());
            }else{
                Q.push(new_top);
            }
        }

    }
    // if(N==1){
        // S.insert("a");
    // }

    // for(auto s:S){
    //     printf("%s\n", s.c_str());
    //     // printf("%c", s);
    //     // cout << s <<"\n";
    // }
    return 0;


}