#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int H, W, K ,  AnsField[300][300], num=0;
char Field[300][300];

void solve(int col_start, int col_end){
    // solve col
    vector<int> row_cake;
    int i,j,k, v1, v2;
    for(i=col_start;i<=col_end;i++){
        for(j=0;j<W;j++){
            if(Field[i][j]=='#') row_cake.push_back(j);
        }
    }
    sort(row_cake.begin(), row_cake.end());
    for(i=0;i<row_cake.size();i++){
        v1 = 0; v2 = row_cake[i];
        if(i>0) {
            v1 = row_cake[i-1]+1;
        }
        if(i==row_cake.size()-1 && row_cake[i-1] != W-1){
            v2 = W-1;
        }
        num ++;
        for(j=col_start;j<=col_end;j++){
            for(k=v1;k<=v2;k++){
                AnsField[j][k] = num;
            }
        }
    }

}

// void print_vec(vector<int> vec){
//     for(int i=0;i<vec.size();i++){
//         printf("%d ", vec[i]);
//     }
//     printf("\n");
// }

int main(){
    int i,j, v1, v2;
    vector<int> vec;
    string s;
    int check = scanf("%d %d %d", &H, &W, &K);
    // char s[W];
    // printf("%d %d %d", H,W,K);
    vector<int> cnt(H, 0);

    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            // cin >> Field[i][j];
            scanf(" %c", &Field[i][j]);
            // cin >> s;
            // cout << s << "\n";
            if (Field[i][j] == '#')  cnt[i]++;
        }
    }

    for(i=0;i<H;i++){
        if(cnt[i]>0)vec.push_back(i);
    }


    for(i=0;i<vec.size();i++){
        v1 = 0, v2 = vec[i];
        if(i>0) v1 = vec[i-1]+1;
        if(i==vec.size()-1 && vec[vec.size()-1] != H-1){
            v2 = H-1;
        }


        solve(v1, v2);
    }
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            if(j==0) printf("%d", AnsField[i][0]);
            else printf(" %d", AnsField[i][j]);
            if(j==W-1) printf("\n");
        }
    }

    return 0;

}