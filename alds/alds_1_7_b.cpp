#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 25
#define NIL -1

struct Node {int parent, left, right;};

Node T[MAX];
int D[MAX], H[MAX];

int getHeight(int u){
    int h1 = 0, h2 = 0;
    if(T[u].left != NIL){
        h1 = getHeight(T[u].left) + 1;
    }
    if(T[u].right != NIL){
        h2 = getHeight(T[u].right) + 1;
    }

    H[u] = max(h1,h2);
    return H[u];
}

void getDepth(int u, int depth){
    D[u] = depth;
    if(T[u].left!=NIL) getDepth(T[u].left, depth+1);
    if(T[u].right!=NIL) getDepth(T[u].right, depth+1);
}

void print(int node){
    int d=0;
    printf("node %d: ", node);
    printf("parent = %d, ", T[node].parent);
    if(T[node].parent == NIL){
        printf("sibling = %d, ", NIL);
    }else{
        if(T[T[node].parent].left==node){
            printf("sibling = %d, ", T[T[node].parent].right);
        }else{
            printf("sibling = %d, ", T[T[node].parent].left);
        }
    }
    if(T[node].left != NIL) d ++;
    if(T[node].right != NIL) d ++;
    printf("degree = %d, ", d);
    printf("depth = %d, ", D[node]);
    printf("height = %d, ", H[node]);

    if(T[node].parent == NIL) printf("root\n");
    else if(T[node].left == NIL & T[node].right == NIL) printf("leaf\n");
    else printf("internal node\n");
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
    getDepth(root,0);
    getHeight(root);

    for(i=0;i<n;i++){
        print(i);
    }



}