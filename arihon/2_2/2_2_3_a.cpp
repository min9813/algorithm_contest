#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

string S, T;

int main(){
    cin >> S;
    cin >> T;
    int n_s = S.size();
    int n_t = T.size();
    int t_index = n_t-1;
    int free_n = 0;
    bool is_ok = false;
    if(n_s < n_t){
        printf("UNRESTORABLE\n");
    }else{
        for(int i=n_s-1;i>=0;i--){
            int j;
            for(j=0;j<n_t;j++){
                if(S[i+j]!=T[j] && S[i+j]!='?') break;
            }

            if(j==n_t){
                for(int j=i+n_t-1;j>=i;j--){
                    S[j] = T[j-i];
                }
                is_ok = true;
                break;
            }
        }
        if(is_ok){
            for(auto &c:S){
                if(c=='?'){
                    printf("a");
                }else{
                    printf("%c", c);
                }
            }
            printf("\n");
        }else{
            printf("UNRESTORABLE\n");
        }
    }

    return 0;
}