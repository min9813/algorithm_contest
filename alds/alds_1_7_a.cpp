#include <iostream>
using namespace std;
# define MAX 100000
# define NIL -1
struct Node {int p,l,r;};

int D[MAX], n;
Node T [MAX];

void rec(int node, int depth){
    D[node] = depth;
    if(T[node].r != NIL){
        rec(T[node].r, depth);
    }
    if(T[node].l != NIL){
        rec(T[node].l, depth+1);
    }
}

void print(int node){
    int i;
    cout << "node "<<node <<": parent = " << T[node].p <<", depth = " << D[node] << ", ";
    if(T[node].p == NIL) cout << "root";
    else if(T[node].l == NIL) cout << "leaf";
    else cout << "internal node";
    cout << ", [";
    i = T[node].l;
    if(i!=NIL){
        cout << i ;
        i = T[i].r;
    }
    while(i != NIL){
        cout << ", ";
        cout << i ;
        i = T[i].r;
    }
    cout << "]" << endl;


}

int main(){
    int n,l,v,d,c,g,i,j,k,r;
    cin >> n;
    for(i=0;i<n;i++)T[i].p = NIL, T[i].l = NIL, T[i].r=NIL;


    for(i=0;i<n;i++){
        cin >> v >> d;
        for(j=0;j<d;j++){
            cin >> c;
            if(j==0){
                T[v].l = c; 
            }else{
                T[g].r = c;
            }
            g = c;
            T[g].p = v;
        }
    }

    for(i=0;i<n;i++){
        if(T[i].p==NIL) r = i;
    }


    rec(r,0);

    for(i=0;i<n;i++){
        print(i);
    }
    return 0;
}
