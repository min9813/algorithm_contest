#include <iostream>
using namespace std;

int main(){
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string input;
    string output;
    int n,i,j;

    cin >> n;
    cin >> input;


    for(i=0;i<input.size();i++){
        for(j=0;j<s.size();j++){
            if(s[j]==input[i]) break;
        }
        output.push_back(s[(j+n)%26]);
    }

    cout << output << "\n";

    return 0;
}