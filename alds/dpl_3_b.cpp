#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;

struct Rectangle{
    int height;
    int pos;
};

int get_largest_square(vector<int> &histgram){
    stack<Rectangle> S;
    int max_v = 0, target;
    for(int i=0;i<=histgram.size();i++){
        Rectangle rect;
        rect.height = histgram[i];
        rect.pos = i;
        if(S.empty()){
            S.push(rect);
        }else if(S.top().height<rect.height){
            S.push(rect);
        }else if(S.top().height>rect.height || i==histgram.size()-1){
            target = i;
            while(!S.empty()&&S.top().height>=rect.height){
                Rectangle pre = S.top();S.pop();
                max_v = max(max_v, pre.height*(i-pre.pos));
                // printf("i=%d max_v=%d\n",i, max_v);
                target = pre.pos;
            }
            rect.pos = target;
            S.push(rect);
        }
    }
    return max_v;
}

int get_largest_square(vector<vector<int>> &array){
    int i, j, h = array.size(), w = array[0].size();
    vector<vector<int>> square_size(h, vector<int>(w+1,0));
    int max_size = 0;
    for(j=0;j<w;j++){
        if(array[0][j]){
            square_size[0][j] = 0;
        }else{
            square_size[0][j] = 1;
        }
    }
    for(i=1;i<h;i++){
        for(j=0;j<w;j++){
            if(array[i][j]){
                square_size[i][j] = 0;
            }else{
                square_size[i][j] = square_size[i-1][j] + 1;
            }
        }
    }

    for(i=0;i<h;i++){
        // printf("--- i = %d ---\n", i);
        max_size = max(max_size, get_largest_square(square_size[i]));
        // printf("max size = %d\n", max_size);
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
    printf("%d\n", length);
    return 0;


}