#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
// #include <prettyprint.hpp>
using namespace std;
typedef long long llong;
static const llong max_n = 100010;
static const llong max_rgb = 300010;
// static const llong mod = 1000000007;
vector<pair<llong, llong>> R;


int main(){
    // int u, v;
    llong X, Y, A, B, C, p;
    // bool updated = false;
    llong ans = 0;
    scanf("%lld %lld %lld %lld %lld", &X, &Y, &A, &B, &C);
    R.resize(A+B+C);
    for(llong i=0;i<A;i++){
        scanf("%lld", &p);
        R[i] = make_pair(-p, 0);
    }

    for(llong i=0;i<B;i++){
        scanf("%lld", &p);
        R[i+A] = make_pair(-p, 1);

    }

    for(llong i=0;i<C;i++){
        scanf("%lld", &p);
        R[i+A+B] = make_pair(-p, 2);
    }

    sort(R.begin(), R.end());
    llong num_R=0, num_G=0, num_N=0;
    llong i = 0, total_score = 0;
    bool pick_r = true, pick_g = true;
    for(i=0;i<A+B+C;i++){
        bool pick = false;
        if(R[i].second==0 && pick_r){
            // printf("pick R, R[%lld]=%lld\n", i, R[i].first);
            num_R ++;
            pick = true;
            pick_r = num_R < X;
        }else if(R[i].second==1 && pick_g){
            // printf("pick G, G[%lld]=%lld\n", i, R[i].first);
            num_G ++;
            pick = true;
            pick_g = num_G < Y;

        }else if(R[i].second==2){
            num_N ++;
            pick = true;
        }
        if(pick){
            total_score += R[i].first;
            if(num_R+num_G+num_N==X+Y){
                break;
            }
        }
    }


    printf("%lld\n", -total_score);
    // double limit = 1. / (double)(4 * M);



    return 0;

}