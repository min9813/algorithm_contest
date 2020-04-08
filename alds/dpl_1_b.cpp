#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
static const int max_num = 10000000;
static const int nmax = 200000;


int main(){
    int n, max_w, i, j, w, v;
    scanf("%d %d", &n, &max_w);
    vector<vector<int>> num_weight_table(n+1, vector<int>(nmax,0));
    vector<pair<int, int>> burdens(n+1,make_pair(0,0));
    for(i=0;i<n;i++){
        scanf("%d %d", &v, &w);
        // printf("input = %d\n", c);
        burdens[i+1] = make_pair(v, w);
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=max_w;j++){
            num_weight_table[i][j] = num_weight_table[i-1][j];
            if(burdens[i].second > j) continue;
            if(burdens[i].first + num_weight_table[i-1][j-burdens[i].second]>num_weight_table[i-1][j]){
                num_weight_table[i][j] = burdens[i].first + num_weight_table[i-1][j-burdens[i].second];
            }
            // printf("i=%d, weight=%d, burden_w=%d, burden_v=%d, max_v=%d\n", i,j,burdens[i].second,burdens[i].first, num_weight_table[i][j]);
        }
    }

    printf("%d\n", num_weight_table[n][max_w]);
    return 0;


}