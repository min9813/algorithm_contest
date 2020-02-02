#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_LEN 200000
using namespace std;
typedef long long llong;

int BinarySearch(llong A[], int n, int max_p, llong k){
    long long left = 0;
    long long right = max_p;
    long long middle;
    bool is_ok = false;
    while (left + 1< right){
        middle = (left + right) / 2;
        // printf("%lld %lld %lld\n", middle, left, right);
        is_ok = k < A[middle];
        if (is_ok){
            // printf("yes");
            right = middle;
        }else{
            // printf("no");
            left = middle;
        }
    }
    return left; // leftはk以下の値が降納されている最大のindexを指す
}

int main(){
    int n,i, index, check;
    llong half, money=0, tmp_money=0;

    check = scanf("%d", &n);

    llong A[n], B[n];

    for(i=0;i<n;i++){
        check = scanf("%lld", &A[i]);
        if(i>0){
            B[i] = A[i] + B[i-1];
        }else{
            B[i] = A[i];
        }
    }

    if(B[n-1] % 2 == 1){
        B[n-1] += 1;
        money += 1;
        half = B[n-1]/2;
        index = BinarySearch(B, n, n, half);

        money += 2*min((half-B[index]), B[index+1]-half);
        B[n-1] -= 2;
        tmp_money = 1;
        half --;
        index = BinarySearch(B, n, n, half);
        tmp_money += 2*min(half-B[index], B[index+1]-half);
        money = min(tmp_money, money);
    }else{
        half = B[n-1]/2;
        index = BinarySearch(B, n, n, half);
        money += 2*min(half-B[index], B[index+1]-half);
    }

    printf("%lld\n", money);
    return 0;

}