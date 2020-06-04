#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
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
vector<string> Qs(max_n);
ll N, M;


void Main(){
    // bool is_ok = true;
    // printf("------------- V=%lld---------\n", V);
    ll N, A, B, C;
    string question;
    sll(N);
    sll(A);
    sll(B);
    sll(C);

    map<char, ll> state;
    state['A'] = A;
    state['B'] = B;
    state['C'] = C;
    
    rep(i, N){
        cin >> question;
        Qs[i] = question;
    }

    if((A+B+C)==0){
        printf("No\n");
    }else if(state[Qs[0][0]]==0 && state[Qs[0][1]]==0){
        printf("No\n");
    }else if((A+B+C)==1){
        string answer = "";
        bool is_ok = true;
        rep(i, N){
            string q = Qs[i];
            char alpha;
            if(state[q[0]]>state[q[1]]){
                alpha = q[1];
                state[q[0]] --;
                state[q[1]] ++;
            }else if(state[q[1]]==0 && state[q[0]]==0){
                is_ok = false;
                break;
            }else if(state[q[0]]==1 && state[q[1]] == 1 && i<N-1){
                string next_q = Qs[i+1];
                // cout << "next q:"<<next_q <<endl; 
                if(next_q[0]==q[0] || next_q[1]==q[0]){
                    alpha = q[0];
                    state[q[0]] ++;
                    state[q[1]] --;
                }else{
                    alpha = q[1];
                    state[q[0]] --;
                    state[q[1]] ++;
                }
            }else{
                alpha = q[0];
                state[q[0]] ++;
                state[q[1]] --;

            }
            answer += alpha;
        }
        if(is_ok){
            printf("Yes\n");
            for(char &c:answer){
                printf("%c\n", c);
            }
        }else{
            printf("No\n");
        }
    }else{
        printf("Yes\n");
        rep(i, N){
            string q = Qs[i];
            char alpha;
            if(state[q[0]]>state[q[1]]){
                alpha = q[1];
                state[q[0]] --;
                state[q[1]] ++;
            
            }else if(state[q[0]]==1 && state[q[1]] == 1 && i<N-1){
                string next_q = Qs[i+1];
                // cout << "next q:" <<next_q <<endl;
                if(next_q[0]==q[0] || next_q[1]==q[0]){
                    alpha = q[0];
                    state[q[0]] ++;
                    state[q[1]] --;
                }else{
                    alpha = q[1];
                    state[q[0]] --;
                    state[q[1]] ++;
                }

            }else{
                alpha = q[0];
                state[q[0]] ++;
                state[q[1]] --;
            }
            printf("%c\n", alpha);
        }
    }

    

    // printf("%lld\n", );


    // cout<<fixed<<setprecision(10)<<num<<endl;
    // cout << num << endl;

}

int main(){
    Main();

    return 0;

}