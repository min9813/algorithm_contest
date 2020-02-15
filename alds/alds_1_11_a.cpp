#include<iostream>
#define MAX 100
using namespace std;


int main(){
    int n,i,v,u,k,j;
    int matrix[MAX][MAX];
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrix[i][j] = 0;
        }
    }
    for(i=0;i<n;i++){
        cin >> v;
        cin >> k;
        for(j=0;j<k;j++){
            cin >> u;
            matrix[v-1][u-1] = 1;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            cout << matrix[i][j] << " ";
        }
        cout << matrix[i][j] << "\n";
    }

    return 0;


}