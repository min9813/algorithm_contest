#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 25
#define NIL -1

struct Node {int parent, left, right;};

Node T[MAX];
int D[MAX], H[MAX];

void preOrder(int u){
    if(u == NIL){
        return ;
    }
    printf(" %d", u);
    preOrder(T[u].left);
    preOrder(T[u].right);
}

void inOrder(int u){
    if(u == NIL){
        return ;
    }
    inOrder(T[u].left);
    printf(" %d", u);
    inOrder(T[u].right);
}

void postOrder(int u){
    if(u == NIL){
        return ;
    }
    postOrder(T[u].left);
    postOrder(T[u].right);
    printf(" %d", u);
}

int main(){
    int i, n, v, lc, rc, root;
    scanf("%d", &n);
    for(i=0;i<n;i++) T[i].parent = NIL;
    for(i=0;i<n;i++){
        scanf("%d %d %d", &v, &lc, &rc);
        T[v].left = lc;
        T[v].right = rc;
        if(lc!=NIL) T[lc].parent = v;
        if(rc!=NIL) T[rc].parent = v;
    }

    for(i=0;i<n;i++){
        if(T[i].parent==NIL) root = i;
    }

    printf("Preorder\n");
    preOrder(root);
    printf("\n");
    printf("Inorder\n");
    inOrder(root);
    printf("\n");
    printf("Postorder\n");
    postOrder(root);
    printf("\n");

}