#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    stack<int> s1;
    stack<pair<int, int> > s2; // s2 = (point_coordinate, amount)

    int sum = 0;
    char input;
    
    for(int i=0;cin >> input;i++){
        // printf("%d \n", i);
        if(input=='\\')s1.push(i);
        else if(input=='/' && s1.size()>0){
            int j = s1.top();s1.pop();
            int a = i - j;
            sum += a;
            while(!s2.empty() && s2.top().first>j){
                a += s2.top().second;s2.pop();                
            }
            s2.push(make_pair(j, a));
        }
        // printf("fin");
    }
    // printf("finish");

    vector<int> ans;
    while(!s2.empty()){ans.push_back(s2.top().second); s2.pop();}
    reverse(ans.begin(), ans.end());
    cout << sum << endl;
    cout << ans.size();
    for (int i=0; i<ans.size();i++){
        cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}