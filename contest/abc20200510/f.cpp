#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;++i)
#define repi(i,n) for(ll i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define slf(n) scanf("%lf", &n);
typedef long long ll;
typedef double lf;
static const ll max_n = 100010;
static const ll mod = 1000000007;
static const ll max_value = 100000000000100;
// vector<string> Qs(max_n);
ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N;
    string s;
    // string question;
    sll(N);
    // map<ll, pair<ll,ll>> counter;
    // set<pair<ll,ll>> counter;
    // vector<string> string_list(N);
    ll only_left_c = 0;
    ll only_right_c = 0;
    ll middle_c = 0;
    ll diff_count = 0;
    rep(i,N){
        cin >> s;
        stack<char> S;
        S.push('*');
        for(char c:s){
            if(c==')' && S.top()=='('){
                S.pop();
            }else{
                S.push(c);
            }
        }
        string modyfied = "";
        ll left_c = 0;
        ll right_c = 0;
        while(S.top()!='*'){
            modyfied = S.top() + modyfied;
            if(S.top() == ')'){
                right_c ++;
            }else{
                left_c ++;
            }
            S.pop();
        }
        only_right_c += (ll)(left_c==0 && right_c>0);
        only_left_c += (ll)(left_c>0 && right_c==0);
        middle_c += (ll) (left_c>0 && right_c>0);
        // counter.insert(make_pair(right_c-left_c, left_c));
        diff_count += (right_c - left_c);
        // string_list[i] = modyfied;
    }
    if(diff_count==0){
        if(middle_c==0){
            printf("Yes\n");
        }else{
            if(only_right_c>0 && only_left_c > 0){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }else{
        printf("No\n");
    }


    // cin >> s;



    

    // printf("%lld\n", );


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}