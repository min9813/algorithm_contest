#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 2000000
#define INFTY (1<<30)
int H, A[MAX+1];

int parent(int i){
    return i / 2;
}

int left(int i){
    return 2 * i;
}

int right(int i){
    return 2 * i + 1;
}

void max_heapify(int i){
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;
    if(l <= H && A[l]>A[i]) largest = l;
    else largest = i;
    if(r <= H && A[r]>A[largest]) largest = r;

    if(largest != i){
        swap(A[i], A[largest]);
        max_heapify(largest);
    }
}

void max_heapify_while(int i){
    int l,r,largest=-1;
    bool is_loop = true;
    while(is_loop){
        l = 2 * i;
        r = 2 * i + 1;
        if(l <= H && A[l]>A[i]) largest = l;
        else largest = i;
        if(r <= H && A[r]>A[largest]) largest = r;
        is_loop = largest != i;
        if(is_loop){
            swap(A[i], A[largest]);
            i = largest;
        }
    }
}

void heap_increase_key(int i, int key){
    int parent_idx;
    if(key < A[i]){
        return;
    }
    A[i] = key;
    parent_idx = i / 2;
    while(i>1 && A[parent_idx]<A[i]){
        swap(A[parent_idx], A[i]);
        i = parent_idx;
        parent_idx = i/2;
    }
}

void insert(int key){
    H++;
    A[H] = -INFTY;
    heap_increase_key(H, key);
}

int extract_max(){
    int maxv;
    if(H < 1){
        return -INFTY;
    }
    maxv = A[1];
    A[1] = A[H--];
    max_heapify_while(1);
    return maxv;
}

int main(){
    int key;
    char com[10];
    while(1){
        scanf("%s", com);
        if(com[0]=='e' && com[1]=='n'){
            break;
        }
        if(com[0]=='i'){
            scanf("%d", &key);
            insert(key);
        }else{
            printf("%d\n", extract_max());
        }

    }
    return 0;
}
