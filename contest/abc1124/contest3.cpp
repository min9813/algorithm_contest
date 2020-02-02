#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long llong;

int main(){
    llong A,B,X, left_money, tmp_left_money, need_money, max_digits, minimum;
    int i, digits, j;
    scanf("%lld %lld %lld", &A,&B,&X);

    for(i=0;i<10;i++){
        left_money = X - B*(i+1);
        need_money = pow(10, i) * A;

        if(left_money>need_money){
            if(i==9) max_digits = pow(10,9);
            else continue;
        }else if(left_money==need_money){
            max_digits = pow(10,i);
            break;
        }else{
            if(i==0){
                max_digits = 0;
                break;
            }else{
                left_money = X - B * i;
                minimum = 0;
                for(j=0;j<i;j++){
                    minimum += 9 * pow(10, j);
                }
                max_digits = min(minimum, left_money / A);
                break;
                // for(j=i-1;j>=0;j--){
                    // max_digits += left_money ;
                // }

            }
        }
    }

    printf("%lld\n", max_digits);

    return 0;

}