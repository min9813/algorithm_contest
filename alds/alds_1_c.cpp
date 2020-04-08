#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

int search_is_prime(int number){
    if(number == 2){
        return 1;
    }
    if(number<=1 || number % 2 == 0){
        return 0;
    }

    for(int i=3;i*i<=number;i+=2){
        if(number % i == 0) return 0;
    }
    // printf("number = %d\n", number);
    return 1;

}

int main(){
    int n, i, number;
    int prime_num = 0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &number);
        prime_num += search_is_prime(number);
    }

    printf("%d\n", prime_num);
    return 0;

    
}