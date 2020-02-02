#include <stdio.h>
#include <algorithm>
using namespace std;
static const int MAX = 1000;
static const int MAX_W = 10000;
int B[MAX], i, T[MAX_W+1];
bool V[MAX];
int small = MAX_W;

int solve(int A[], int n){
    int cur, loop_min, loop_sum, loop_num, v, ann=0;
    for(i=0;i<n;i++){
        B[i] = A[i];
        V[i] = false;
    }

    sort(B, B+n);

    for(i=0;i<n;i++){
        T[B[i]] = i;
    }

    for(i=0;i<n;i++){
        if(V[i]) continue;
        cur = i;
        loop_min = MAX_W;
        loop_sum = 0;
        loop_num = 0;
        while(1){
            V[cur] = true;
            loop_num ++;
            v = A[cur];
            loop_min = min(loop_min, v);
            loop_sum += v;
            cur = T[v];
            if(V[cur]) break;
        }
        ann += min(loop_sum + (loop_num - 2) * loop_min, loop_sum + (loop_num+1)*small + loop_min);
    }

    return ann;

}

int main(){
    int n, weights[MAX], ans;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &weights[i]);
        small = min(small, weights[i]);
    }

    ans = solve(weights, n);
    printf("%d\n", ans);

}