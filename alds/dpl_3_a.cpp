#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int get_largest_square(vector<vector<int>> &array){
    int i, j, h = array.size(), w = array[0].size();
    vector<vector<int>> square_size(h+1, vector<int>(w+1,0));
    int max_size = 0;
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            if(array[i-1][j-1]==0){
                square_size[i][j] = 1+min(min(square_size[i-1][j], square_size[i-1][j-1]),square_size[i][j-1]);
                max_size = max(max_size, square_size[i][j]);
            }
        }
    }

    return max_size;

}


int main(){
    int h, w, i, j;
    scanf("%d %d", &h, &w);
    vector<vector<int>> array(h,vector<int>(w));
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf("%d", &array[i][j]);
        }
    }

    int length = get_largest_square(array);
    printf("%d\n", length*length);
    return 0;


}