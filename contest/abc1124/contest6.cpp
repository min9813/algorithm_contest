#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool dfs(vector<vector<int>> field, int idx, int depth, vector<int> searching);
vector<vector<int> > ans;
int mini_len;

int main(){
    int M,N, Field[N+1],i,j;
    scanf("%d %d", &N, &M);
    vector< vector<int> > DP(N);
    vector <int> answer;
    vector<int> is_ok(N+1, 0);
    string input;
    mini_len = N+1;
    cin >> input;
    is_ok[0] = 1;
    for(i=0;i<N+1;i++){
        if(input[i]=='1') continue;
        for(j=1;j<=M && (i-j)>=0;j++){
            if(is_ok[i-j]){
                DP[i-j].push_back(j);
                is_ok[i] = 1;
            }
        }
    }
    vector<int> search;
    bool flag;
    if(is_ok[N]==0) cout << -1 <<endl;
    else{
        for(i=0;i<DP[0].size();i++){
            flag = dfs(DP, DP[0][i], DP[0][i], search);
        }
        for(i=0;i<ans.size();i++){
            string msg = "";
            if(ans[i].size()==mini_len){
                for(j=0;j<mini_len;j++){
                    msg += to_string(ans[i][j]);
                }
                answer.push_back(stoi(msg));
            }
        }
    }
    sort(answer.begin(), answer.end());

    string answer_msg = to_string(answer[0]);

    for(i=0;i<answer_msg.size();i++){
        cout << answer_msg[i];
        if(i<answer_msg.size()-1) cout << " ";
    }
    cout << '\n';

    return 0;

}

bool dfs(vector<vector<int>> field, int idx, int depth, vector<int> searching){
    if(depth+1==field.size()+1 && searching.size()<mini_len){
        searching.push_back(idx);
        ans.push_back(searching);
        mini_len = min(mini_len, (int)searching.size());
        return true;
    }else if(depth+1 > field.size()+1 || searching.size()>=mini_len){
        return false;
    }
    searching.push_back(idx);

    bool flag = false;

    for(int j=0;j<field[depth].size();j++){
        vector<int> old_searching = searching;

        if(dfs(field, field[depth][j], depth+field[depth][j], searching)){
            flag = true;
        }
        vector<int> searching = old_searching;
    }

    return flag;
}