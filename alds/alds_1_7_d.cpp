#include <stdio.h>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100

int n, position;
vector<int> answer, preorder, inorder;

void reconstruction(int l,int r){
    if(l>=r) return;
    int root = preorder[position++];
    int m = distance(inorder.begin(), find(inorder.begin(), inorder.end(), root));
    reconstruction(l,m);
    reconstruction(m+1, r);
    answer.push_back(root);
}

int main(){
    int i, v;
    position = 0;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &v);
        preorder.push_back(v);
    }
    for(i=0;i<n;i++){
        scanf("%d", &v);
        inorder.push_back(v);
    }

    reconstruction(0,n);

    for(i=0;i<answer.size();i++){
        printf("%d", answer[i]);
        if(i<answer.size()-1){
            printf(" ");
        }
    }
    printf("\n");

}