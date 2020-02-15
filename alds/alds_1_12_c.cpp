#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 10000
#define INFTY 1<<21
#define WHITE 0
#define GLAY 1
#define BLACK 2
using namespace std;

int n, d[MAX];
vector<pair<int,int>> adj[MAX];

void dijkstra(){
    int i,u, c, c_next, minv, v;
    int color[MAX];
    pair<int, int> u_d, d_u;
    priority_queue<pair<int, int>> PQ;
    u = 0;
    for(i=0;i<n;i++){
        color[i] = WHITE;
        d[i] = INFTY;
    }

    // for(i=0;i<adj[u].size();i++){
    //     color[i] = WHITE;
    //     u_d = adj[u][i];
    //     d[u_d.first] = u_d.second;
    // }

    d[0] = 0;
    PQ.push(make_pair(0, 0));

    while(!PQ.empty()){
        d_u = PQ.top(); PQ.pop();
        u = d_u.second;
        c = d_u.first * (-1);

        if(d[u] < c) continue;
        color[u] = BLACK;

        for(i=0;i<adj[u].size();i++){
            v = adj[u][i].first;
            c_next = adj[u][i].second;

            if(color[v]!=BLACK && d[v]>c_next + c){
                d[v] = c_next + c;
                color[v] = GLAY;
                PQ.push(make_pair(d[v]*(-1), v));
            }
        }
    }

}


int main(){
    int i, j, e,k,u,v,c;
    cin >> n;

    for(i=0;i<n;i++){
        cin >> u >> k;
        for(j=0;j<k;j++){
            cin >> v >> c;
            adj[u].push_back(make_pair(v, c));
        }
    }
    dijkstra();

    for(i=0;i<n;i++){
        cout << i << " " <<d[i] <<"\n";
    }


    return 0;
}