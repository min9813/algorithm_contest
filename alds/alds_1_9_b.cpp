#include<iostream>
using namespace std;
#define MAX 500000
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

int main(){
    int i;
    cin >> H;
    for(i=1;i<=H;i++){
        cin >> A[i];
    }
    for(i = H/2;i>=1;i--){
        max_heapify_while(i);
    }

    for(i = 1;i<=H;i++){
        cout <<" "<< A[i];
    }
    cout << endl;
    return 0;
}
