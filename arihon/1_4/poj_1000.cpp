#include <cstdio>
int a, b, c;

void solve(){
    c = a + b;
}

int main(){
    scanf("%d %d", &a, &b);
    solve();

    printf("%d \n", c);

    return 0;
}