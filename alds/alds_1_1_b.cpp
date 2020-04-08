#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    int r;
    if(a < b) swap(a, b);
    while(b > 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));

    return 0;
}