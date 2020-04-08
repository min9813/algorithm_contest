#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int amount = 1000;
vector<int> coins = {500, 100, 50, 10, 5, 1};

int main(){
    int pay, ans=0;
    scanf("%d", &pay);

    amount -= pay;

    for(int i=0;i<coins.size();i++){
        int t = amount / coins[i];
        amount -= t * coins[i];
        ans += t;
    }

    printf("%d\n", ans);


}