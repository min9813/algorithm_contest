#include <stdio.h>

int LinearSearch(int A[], int n, int key){
    int i = 0;
    A[n] = key;
    while (A[i] != key){
        i ++;
    }
    return i != n;
}

int BinarySearch(int A[], int n, int key){
    int left = 0;
    int right = n;
    int middle;
    while (left < right){
        middle = (left + right) / 2;
        if (A[middle]>key){
            right = middle;
        }else if(A[middle]<key){
            left = middle+1;
        }else{
            return 1;
        }
    }
    return 0;
}

int main(){
    int array[1000000];
    int i,n,q,key,sum=0;
    scanf("%d", &n);
    for (i=0;i<n;i++){
        scanf("%d", &array[i]);
    }

    scanf("%d", &q);
    for(i=0; i<q;i++){
        scanf("%d", &key);
        if(BinarySearch(array, n, key))sum++;
    }
    printf("%d\n", sum);
    return 0;

}