#include <iostream>
#include <stdio.h>
#define MAX 100000
#define SENTINEL 2000000000


struct Card{
    char suit;
    int value;
};

struct Card L[MAX /2 + 2], R[MAX/2 + 2]; // 番兵分の1を足す


void merge(struct Card A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int i=0, j=0, k;

    for (i=0;i<n1;i++){
        L[i] = A[left+i];
    }
    for (i=0;i<n2;i++){
        R[i] = A[mid+i];
    }
    L[n1].value = SENTINEL;
    R[n2].value = SENTINEL;

    i=0;

    for(k=left;k<right;k++){
        if(L[i].value<=R[j].value){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(struct Card A[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(struct Card A[], int p, int r){
    int x = A[r].value;
    int i=p-1, j;
    struct Card tmp;

    for(j=p;j<r;j++){
        if(A[j].value<= x){
            i ++;
            tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
        }
    }
    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    return i+1;
}

void quickSort(struct Card A[], int l, int r){
    int q;
    if (l < r){
        q = partition(A, l, r);
        quickSort(A, l, q-1);
        quickSort(A, q+1, r);
    }
}

int main(){
    int n, i, value, stable=1;
    char s[10];
    struct Card A[MAX], B[MAX];

    scanf("%d", &n);
    for(i=0; i<n;i++){
        scanf("%s %d", &s[0],&value);
        A[i].value = B[i].value = value;
        A[i].suit = B[i].suit = s[0];
    } 

    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);

    for(i=0;i<n;i++){
        if(A[i].suit != B[i].suit){
            stable = 0;
            break;
        }
    }

    if (stable == 1) printf("Stable\n");
    else printf("Not stable\n");

    for(i=0; i<n;i++){
        printf("%c %d\n", B[i].suit, B[i].value);
    }

    return 0;


}