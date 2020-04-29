#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> requests;

bool cmp_terminate(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

int main(){
    scanf("%d %d", &N, &M);
    requests.resize(M);
    int a, b;

    for(int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        requests[i] = make_pair(a, b);
    }

    sort(requests.begin(), requests.end(), cmp_terminate);

    int now_idx = requests[0].second;
    int ans = 1;
    for(auto &req:requests){
        // printf("now idx = %d, req st=%d, req ed = %d\n", now_idx, req.first, req.second);
        if(now_idx > req.first){
            continue;
        }else{
            ans += 1;
            now_idx = req.second;
        }

    }

    printf("%d\n", ans);

}