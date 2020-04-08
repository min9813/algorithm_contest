#include<cstdio>
typedef unsigned long long ullong;
ullong power(ullong x, ullong n, ullong M){
    ullong res = 1;
    if(n > 0){
        res = power(x, n/2, M);
        if(n % 2 == 0){
            res = (res * res) % M;
        }else{
            res = (((res * res) % M) * x) % M;
        }
    }
    return res;
}



int main(){
    ullong m, n;
    scanf("%lld %lld", &m, &n);
    printf("%lld\n", power(m, n, 1000000007));
    return 0;
}