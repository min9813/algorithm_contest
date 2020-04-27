#include <iostream>
using namespace std;
#define MAX_NUM 100000
#define MAX_WEIGHT 10000

int calc_weight_num(int A[], int p, int n, int k){
    long long sum_num = 0;
    int i=0, now_weight = 0, track_now_num=0;

    while(i<n && track_now_num<k){
        // printf("now weight : %d p=%d i=%d t_num=%d\n", now_weight,p,i, track_now_num);
        now_weight += A[i];
        if (now_weight < p){
            sum_num ++;
            i++;
        }else{
            track_now_num ++;
            if(now_weight == p){
                sum_num++;
                i++;
            }
            while(A[i]>p){
                i++;
            }
            now_weight = 0;
        }
    }
    return sum_num == n;
}



int BinarySearch(int A[], int n, int max_p, int k){
    long long left = 0;
    long long right = max_p;
    long long middle;
    bool is_ok = false;
    while (left + 1< right){
        middle = (left + right) / 2;
        // printf("%lld %lld %lld\n", middle, left, right);
        is_ok = calc_weight_num(A, middle,n,k);
        if (is_ok){
            // printf("yes");
            right = middle;
        }else{
            // printf("no");
            left = middle;
        }
    }
    return right;
}

int main(){
    int n,k,w,max_p=0;
    int T[MAX_NUM];
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> w;
        max_p += w;
        T[i] = w;
    } 
    long long ans = BinarySearch(T, n, max_p, k);
    cout << ans << endl;
    return 0;
}