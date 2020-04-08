#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
static const int max_num = 10000000;
static const int nmax = 200000;

int lsi(vector<int> &array){
    vector<int> L(array.size());
    int i, j, n = array.size();
    int length = 1;
    L[0] = array[0];
    for(i=1;i<n;i++){
        if(L[length-1]<array[i]){
            L[length++] = array[i];
        }else{
            *lower_bound(L.begin(), L.begin()+length, array[i]) = array[i];
        }
    }

    return length;

}


int main(){
    int n, max_w, i, j, w, v;
    scanf("%d", &n);
    vector<int> array(n+1,0);
    for(i=0;i<n;i++){
        scanf("%d", &array[i]);
    }

    int length = lsi(array);
    printf("%d\n", length);
    return 0;


}