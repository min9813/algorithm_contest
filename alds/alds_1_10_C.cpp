#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static const int N = 1000;

int lcs(string X, string Y){
    int m = X.size();
    int n = Y.size();
    int i,j,maxl=0;
    int dp[N+1][N+1];
    for(i=0;i<m+1;i++){
        dp[i][0] = 0;
    }
    for(j=0;j<n+1;j++){
        dp[0][j] = 0;
    }
    for(i=1;i<m+1;i++){
        for(j=1;j<n+1;j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else if(dp[i][j-1]>dp[i-1][j]){
                dp[i][j] = dp[i][j-1];
            }else{
                dp[i][j] = dp[i-1][j];
            }
            maxl = max(maxl, dp[i][j]);

        }
    }

    return maxl;
}


int main(){
    string X, Y;
    int i, q;
    cin >> q;
    for(i=0;i<q;i++){
        cin >> X >> Y;
        cout << lcs(X, Y) <<endl;
    }
    return 0;
}