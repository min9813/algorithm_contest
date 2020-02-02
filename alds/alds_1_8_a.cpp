#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

Node * find(Node *u, int k){
    while(u != NIL && k != u->key){
        if(k < u->key) u = u->left;
        else u = u->right;
    }

    return u;
}

Node * treeMinimum(Node *x){
    while (x->left != NIL) x = x->left;
    return x;
}

Node * treeSuccessor(Node *x){
    if(x->right != NIL) return treeMinimum(x->right);
    Node *y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

void treeDelete(Node *z){
    // case1, 2, 3を一般化すると、yを削除してzのキーをyのキーにして、xをyのparentの子にする、と言う形になる。
    Node *y; // delete node
    Node *x; // child of y;

    if (z->left == NIL || z->right == NIL){
        y = z;
    }else y = treeSuccessor(z);

    if(y -> left != NIL){
        x = y->left;
    }else{
        x = y->right;
    }

    if(x != NIL){
        x -> parent = y -> parent;
    }

    if(y->parent == NIL){
        root = x;
    }else {
        if(y == y->parent->left){
            y->parent->left = x;
        }else{
            y->parent->right = x;
        }
    }

    if(y != z){
        z->key = y->key;
    }

    free(y);
}

void insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z -> key = k;
    z -> left = NIL;
    z -> right = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else if(z->key > x->key){
            x = x->right;
        }
    }

    z -> parent = y;
    // 木が空だったとき
    if(y == NIL){
        root = z;
    }else{
        if(z -> key > y->key){
            y -> right = z;
        }else{
            y -> left = z;
        }
    }
}

void inorder(Node *u){
    if(u == NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u){
    if(u == NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(){
    int n, i, x;
    string order;
    scanf("%d", &n);

    for (i=0;i<n;i++){
        cin >> order;
        if(order == "insert"){
            scanf(" %d", &x);
            insert(x);
        }else if(order == "print"){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }else if(order == "find"){
            scanf(" %d", &x);
            Node *t = find(root, x);
            if(t != NIL){
                printf("yes\n");
            }else printf ("no\n");
        }else if(order == "delete"){
            scanf("%d", &x);
            treeDelete(find(root, x));
        }
    }

    return 0;
}
