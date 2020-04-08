#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

int N, w, min_ok_w, min_ok_idx, num=1, pile_top, j;
vector<int> piles;

int main(){
    scanf("%d", &N);
    scanf("%d", &w);
    piles.push_back(w);

    for(int i=0;i<N-1;i++){
        scanf("%d", &w);
        min_ok_w = 200000;
        min_ok_idx = -1;
        for(j=0;j<piles.size();j++){
            pile_top = piles[j];
            if(pile_top>=w){
                if(pile_top < min_ok_w){
                    min_ok_w = pile_top;
                    min_ok_idx = j;
                }
            }
        }
        if(min_ok_idx==-1){
            piles.push_back(w);
        }else{
            piles[min_ok_idx] = w;
        }
        // printf("w=%d, top=%d\n", w, piles.top());
        
    }

    printf("%d\n", (int)piles.size());
    return 0;

}