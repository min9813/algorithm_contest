#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define N 100000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,m;
vector<int> color;
vector<vector<int>> adj_vec;
vector<int> group_id;

int next(int u){
    int i,v;
    // printf("size = %d ", (int)adj_vec[u].size());
    for(i=0;i<(int)adj_vec[u].size();i++){
        v = adj_vec[u][i];
        // printf("next = %d, color=%d", v, color[v]);
        if(color[v]==WHITE){
            return v;
        }
    }
    return -1;
}

void dfs(){
    int v,w,i;
    int group_num = 0;
    stack<int> S;
    // printf("dfs in n=%d \n", n);
    for(i=0;i<n;i++){
        // printf("i=%d\n",i);
        if(color[i]==WHITE){
            S.push(i);
            color[i] = GRAY;
            group_id[i] = group_num;
            while (!S.empty()){
                v = S.top();

                w = next(v);
                // printf("v=%d w=%d\n",v,w);

                if(w==-1){
                    S.pop();
                    color[v] = BLACK;
                }else{
                    S.push(w);
                    color[w] = GRAY;
                    group_id[w] = group_num;
                }
            }
            group_num ++;

        }
    }

    
}

int main(){
    int i,j,u,v,q;
    vector<pair<int,int>> questions;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++){
        vector<int> tmp;
        adj_vec.push_back(tmp);
        color.push_back(WHITE);
        group_id.push_back(0);
    }
    for(i=0;i<m;i++){
        scanf("%d %d", &u,&v);
        adj_vec[u].push_back(v);
        adj_vec[v].push_back(u);
    }
    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%d %d", &u, &v);
        questions.push_back(make_pair(u,v));
    }
    dfs();
    // for(i=0;i<n;i++){
    //     printf("group_id:%d=%d\n", i,group_id[i]);
    // }
    for(i=0;i<questions.size();i++){
        u = questions[i].first;
        v = questions[i].second;
        if(group_id[u]==group_id[v]){
            printf("yes\n");
        }else{
            printf("no\n");
        }

    }


}
