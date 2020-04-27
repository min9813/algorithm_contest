#include <iostream>
#include <stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX /2 + 2], R[MAX/2 + 2]; // 番兵分の1を足す
int cnt;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];
    int i=0, j=0, k;

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
        cnt ++;
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int A[MAX], n, i;
    cnt = 0;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n);

    for(i=0; i<n;i++){
        if(i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", cnt);
}