#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
int N;
long long temp, number_1, number_2, number_p;
vector<long long> numbers;


int main(){
    scanf("%d", &N);
    numbers.resize(N);
    for(int i=0;i<N;i++){
        scanf(" %lld", &temp);
        // printf("input = %d\n", temp);
        numbers[i] = temp;
    }
    // printf("ok\n");
    sort(numbers.begin(), numbers.end());

    long long score = 0;
    for(int i=N-1;i>=1;i--){
        // printf("i=%d, numbers size=%d\n", i, (int)numbers.size());
        number_1 = numbers[i];
        number_2 = numbers[i-1];
        number_p = number_1 + number_2;
        score += (number_p); 
        numbers.erase(numbers.begin()+i);
        numbers.erase(numbers.begin()+i-1);
        auto position = lower_bound(numbers.begin(), numbers.end(), number_p);
        numbers.insert(position, number_p);
    }

    score += numbers[0];

    printf("%lld\n", score);

    return 0;

}