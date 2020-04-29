#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
const int max_length = 10;
string input_s;
vector<int> input_i;
int size_n;
unsigned long long sum;

void solve(vector<int> &sign){
    unsigned long long tmp_sum = 0;
    unsigned long long tmptmp = 0;
    // printf("vec size=%d, total_size=%d\n", (int)sign.size(), size_n);
    if(sign.size()==size_n-1){
        tmptmp = input_i[0];
        for(int i=0;i<size_n-1;i++){
            // printf("i=%d sign=%d ", i, sign[i]);
            if(sign[i]){
                sum += tmptmp;
                // printf("tmp = %lld ", tmptmp);
                tmptmp = input_i[i+1];
                // if(i == size_n-1){
                //     sum += input_i[size_n-1];
                // }
            }else{
                tmptmp = tmptmp * 10 + input_i[i+1];
            }
        }
        sum += tmptmp;
        // printf("sum=%lld", sum);
        // printf("\n");
    }else{
        sign.push_back(1);
        solve(sign);
        sign.erase(sign.end()-1);

        sign.push_back(0);
        solve(sign);
        sign.erase(sign.end()-1);

        // printf("mid vec size=%d, total_size=%d\n", (int)sign.size(), size_n);

        // printf("after vec size=%d, total_size=%d\n", (int)sign.size(), size_n);

    }
    
}

int main(){
    cin >> input_s;
    size_n = (int)input_s.size();
    input_i.resize(size_n);
    for(int i=0;i<size_n;i++){
        input_i[i] = (int)(input_s[i]) - '0';
    }
    vector<int> sign;

    solve(sign);
    printf("%lld\n", sum);
    return 0;
}