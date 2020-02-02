#include <map>
#include <iostream>
using namespace std;

int main(){
    map<int, int> m;
    m[0] += 1;
    cout << m[0] << endl;
}