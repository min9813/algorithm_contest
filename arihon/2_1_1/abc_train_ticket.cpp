#include <iostream>
#include <vector>
#include <string>
using namespace std;
static const int size_n = 4;
string input_s;
vector<int> input_i(size_n);
vector<int> operator_list = {0, 1};

int main(){
    cin >> input_s;
    input_i.resize(size_n);
    for(int i=0;i<size_n;i++){
        input_i[i] = (int)(input_s[i]) - '0';
    }
    int score1, score2, score3;
    vector<string> ops = {"+", "-"};
    vector<int> op_idx;
    for(auto &i1: operator_list){
        if(i1==0){
            score1 = input_i[0] + input_i[1];
        }else{
            score1 = input_i[0] - input_i[1];
        }
        for(auto &i2:operator_list){
            if(i2==0){
                score2 = score1 + input_i[2];
            }else{
                score2 = score1 - input_i[2];
            }
            for(auto &i3:operator_list){
                if(i3==0){
                    score3 = score2 + input_i[3];
                }else{
                    score3 = score2 - input_i[3];
                }
                if(score3==7){
                    op_idx = {i1, i2, i3};
                    break;
                }
            }
        }
    }
    string ans = "";
    for(int i=0;i<size_n-1;i++){
        ans += input_s[i] + ops[op_idx[i]];
    }
    ans += input_s[size_n-1];
    ans += "=7";
    cout << ans <<endl;

    return 0;
}