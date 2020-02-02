#include <iostream>
#include <stdio.h>
#define MAX 200000
#define SENTINEL 2000000000
typedef long long llong;

int L[MAX /2 + 2], R[MAX/2 + 2]; // 番兵分の1を足す

llong merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int i=0, j=0, k;
    llong cnt = 0;

    for (i=0;i<n1;i++){
        L[i] = A[left+i];
    }
    for (i=0;i<n2;i++){
        R[i] = A[mid+i];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    i=0;

    for(k=left;k<right;k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            cnt += n1 - i;
            j++;
        }
    }

    return cnt;
}

llong mergeSort(int A[], int left, int right){
    llong v1,v2,v3;

    if(left + 1 < right){
        int mid = (left + right) / 2;
        v1 = mergeSort(A, left, mid);
        v2 = mergeSort(A, mid, right);
        v3 = merge(A, left, mid, right);
        return v1 + v2 + v3;
    }else{
        return 0;
    }
}

int main(){
    int A[MAX], n, i;
    llong cnt = 0;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }

    cnt = mergeSort(A, 0, n);

    // for(i=0; i<n;i++){
    //     if(i>0) printf(" ");
    //     printf("%d", A[i]);
    // }
    printf("%lld\n", cnt);
}