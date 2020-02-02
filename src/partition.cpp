# include<stdio.h>
# define MAX 100000


int partition(int A[], int p, int r){
    int x = A[r];
    int i=p-1, j, tmp;

    for(j=0;j<r;j++){
        if(A[j]<= x){
            i ++;
            tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
        }
    }
    A[r] = A[i+1];
    A[i+1] = x;
    return i+1;
}

int main(){
    int n, A[MAX],i, idx;

    scanf("%d", &n);
    for(i=0;i<n;i++)scanf("%d", &A[i]);

    idx = partition(A, 0, n-1);

    for(i=0;i<n;i++){
        if(i == idx){
            printf("[%d]", A[i]);
        }else{
            printf("%d", A[i]);
        }

        if (i<n-1)printf(" ");
    }
    printf("\n");

    return 0;
}