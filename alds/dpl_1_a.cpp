#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
static const int max_num = 10000;
static const int nmax = 200000;


int main(){
    int n, m, i, j, c;
    scanf("%d %d", &n, &m);
    vector<int> num_coin_table(nmax,max_num);
    vector<int> coins(m,0);
    for(i=0;i<m;i++){
        scanf("%d", &c);
        // printf("input = %d\n", c);
        coins[i] = c;
    }

    num_coin_table[0] = 0;

    for(i=0;i<n+1;i++){
        for(j=0;j<m;j++){
            num_coin_table[i+coins[j]] = min(num_coin_table[i+coins[j]], num_coin_table[i]+1);
            // printf("%d:%d\n", i+coins[j], num_coin_table[i+coins[j]]);
        }
    }

    printf("%d\n", num_coin_table[n]);
    return 0;


}