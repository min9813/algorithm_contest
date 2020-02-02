#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

int main(){
    int N,i,j, index;
    long K, in;
    scanf("%d %ld",&N, &K);

    vector<long> A(N);
    vector<long> S(N+1);
    map<int, int> num;

    S[0] = 0;
    for(i=0;i<N;i++){
        scanf(" %ld", &in);
        A[i] = in;
        S[i+1] = S[i] + A[i];
    }

    long long sum=0;

    // order O(NlogK), num[] の検索にlogK
    num[S[0]%K] = 1;

    for(j=1;j<N+1;j++){
        // del operation
        if(j-K>=0){
            index = (S[j-K] - (j-K)) % K;
            num[index]--;
        }
        // if(j==0){
        //     num[A[0] % K] ++;
        //     continue;
        // }
        index = (S[j]-j) % K;
        sum += num[index];
        // printf("j=%d sum:%lld", j,sum);
        num[index] ++;
    }

    printf("%lld\n", sum);
    return 0;
}