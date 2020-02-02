#include<iostream>
using namespace std;

static const int N = 100;
int M[N][N], P[N+1];


int main(){
    string X, Y;
    int i,j,k,l,n;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> P[i] >> P[i+1];
        // cout <<"i="<<i<<" "<< P[i] << " " <<P[i+1]<<endl;
        M[i][i] = 0;
    }

    for(j=1;j<n;j++){
        for(i=0;i<n-j;i++){
            k = i + j;
            M[i][k] = (1<<21);
            for(l=i;l<k;l++){
                M[i][k] = min(M[i][k], M[i][l]+M[l+1][k]+P[i]*P[l+1]*P[k+1]);
            }
        }
    }
    cout << M[0][n-1] <<endl;
    return 0;
}