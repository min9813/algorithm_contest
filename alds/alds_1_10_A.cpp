#include<iostream>
using namespace std;

int n, dp[50];

void make_fib(){
    int i;
    dp[0] = 1;
    dp[1] = 1;
    for(i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
}

int main(){
    cin >> n;
    make_fib();
    cout << dp[n] << endl;
}