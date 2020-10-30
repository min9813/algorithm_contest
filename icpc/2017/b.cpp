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
#include <complex>
#include <random>
#include <bitset>
#include <list>
#include <assert.h>
#include <prettyprint.hpp>
using namespace std;
#define repi(i,n) for(int i=0;i<n;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repinvi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vvv(t) vector<vector<vector<t>>>
typedef long long ll;
typedef double lf;
typedef short int si;

static const string identical = "IDENTICAL";
static const string close = "CLOSE";
static const string different = "DIFFERENT";


inline vector<string> split(string s1, char sp){
    vector<string> splitted;
    string in = "";
    rep(i, s1.size()){
        if(s1[i]==sp){
            splitted.emplace_back(in);
            in = "";
        }else{
            in = in + s1[i];
        }
    }
    if(in.size()>0){
        splitted.emplace_back(in);
    }

    return splitted;
}



void Main(){
    string s1, s2;
    vector<string> answers;
    while(cin >> s1){
        if(s1 == ".") break;
        cin >> s2;
        auto splitted_s1 = split(s1, '\"');
        auto splitted_s2 = split(s2, '\"');
        if(splitted_s1.size() != splitted_s2.size()){
            answers.emplace_back(different);
            continue;
        }
        ll num_diff = 0;
        string ans = identical;
        // cout << splitted_s1 <<endl;
        bool is_skip = false;
        rep(i, splitted_s1.size()){
            auto content1 = splitted_s1[i];
            auto content2 = splitted_s2[i];
            if(i%2){
                if(content1.compare(content2)==0){
                    continue;
                }else{
                    if(num_diff==1){
                        ans = different;
                        num_diff ++ ;
                        is_skip = true;
                        break;
                    }else{
                        num_diff ++;
                    }
                }
            }else{
                if(content1.compare(content2) == 0){
                    continue;
                }else{
                    ans = different;
                    is_skip = true;
                    break;
                }
            }
        }
        if(num_diff == 1 && !is_skip){
            ans = close;
        }
        // cout << "num diff:" << num_diff <<endl;
        answers.emplace_back(ans);

    }

    rep(i, answers.size()){
        cout << answers[i] << endl;
    }

}

int main(){
    // string a = "2zi4pe7XqlpuR29iP2kQIbx6qv2GTF8wyp6KOjrG42lFHfC4PSSFr2um4AoCgVu9US";
    // string b = "2zi4pe7VOAft86K62ih7HBZpvfEbcI4xOXDVk3gFNCq;dal7WrGG9PzwmwI0AeRQSP";
    // cout << a.compare(b) << endl;
    Main();
}