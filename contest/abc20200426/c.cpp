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
using namespace std;
typedef long long ll;
// static const ll max_n = 200010;



int main(){
    // int u, v;
    // bool updated = false;
    set<string> items;
    ll N, A;
    string S;
    scanf("%lld", &N);
    for(ll i=0;i<N;i++){
        cin >> S;
        items.insert(S);
    }

    cout << items.size() <<endl;

    return 0;

}