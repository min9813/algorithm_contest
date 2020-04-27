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

ll N, X, Y;

void dfs(string s, char mx){
    if(s.size()==N){
        printf("%s\n", s.c_str());
    }else{
        for(char c = 'a';c <= mx;c++){
            dfs(s+c, ((c==mx)?(char)(mx+1) : mx));
        }
    }
}

int main(){
    // int u, v;
    // bool updated = alse;
    scanf("%lld", &N);

    dfs("", 'a');
    return 0;
}