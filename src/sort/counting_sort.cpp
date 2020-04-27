#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 2000001
#define MAX_VAL 10001

void print_array(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void countingSort(int A[], int B[], int n){
    int C[MAX_VAL];
    int i;
    for(i=0;i<MAX_VAL;i++){
        C[i] = 0;
    }

    for(i=0;i<n;i++){
        C[A[i]] ++;
    }


    for(i=1;i<MAX_VAL;i++){
        C[i] = C[i] + C[i-1];
    }

    for(i=n;i>=0;i--){
        B[C[A[i]]] = A[i];
        C[A[i]] --;
    }
}

int main(){
    int A[MAX_LEN], B[MAX_LEN];
    int n,i;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }

    countingSort(A, B, n);

    for(i=1;i<=n;i++){
        if(i>1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}