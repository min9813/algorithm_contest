#include<stdio.h>
#include<cmath>
#define MAX_LEN 200000

int main(){
    int n, i, d;
    long long c;
    long long sum = 0, digit_num=0;

    int check = scanf("%d", &n);

    for(i=0;i<n;i++){
        int check = scanf("%d %lld", &d,&c);
        sum += d * c;
        digit_num += c;
    }

    long long reduction_num = (sum-1) / 9;
    printf("%lld\n", digit_num - 1 + reduction_num);
    return 0;
}