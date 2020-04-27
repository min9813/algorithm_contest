#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

bool is_prime(ll N){
    ll i=2;
    while(i*i<N){
        if(N % i == 0){
            return false;
        }else{
            i ++;
        }
    }
    if(N % i == 0){
        return false;
    }
    return true;
}

template<typename T>
vector<T> divisor(T N){
    vector<T> divisors_list;
    T i = 1;
    for(i = 1;i*i<N;i++){
        if(N % i == 0){
            divisors_list.emplace_back(i);
            divisors_list.emplace_back(N / i);
        }
    }

    if(N % i == 0){
        divisors_list.emplace_back(i);
    }

    return divisors_list;

}

template<typename T>
map<T, T> prime_factor(T N){
    map<T, T> res;
    ll i = 2;
    for(i=2;i*i<=N;i++){
        while(N%i==0){
            ++res[i];
            N /= i;
        }
    }
    if(N!=1){
        res[N] = 1;
    }
    return res;
}


int main(){
    ll N, a, b, c, gcd_num;
    scanf("%lld", &N);
    if(is_prime(N)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}