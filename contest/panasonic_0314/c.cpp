#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
// static const ll max_n = 200010;
// 9223372036854775807
static const ll max_l = 4000000000000000000;
static const ll max_o = 9223372036854775807;

int main(){
    // int u, v;
    // bool updated = false;
    ll a,b,c;
    cin >> a >>b >> c;
    ll left = 4*a * b;
    ll right = (c - (a+b));
    // ll small_right = right / 4;
    if(a+b>=c){
        printf("No\n");
    }else{
        right = right * right;
        // cout << right <<endl;
        // cout << left <<endl;
        if(left < right){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    
    return 0;

}