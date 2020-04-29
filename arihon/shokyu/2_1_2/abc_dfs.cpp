#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
static const int start = 0;
static const int goal = 1;
static const int road = 2;
static const int ng = 3;
static const int searched = 4;
vector<vector<int>> field;
vector<pair<int, int>> command = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int H, W;

int solve(pair<int, int> point)
{
    field[point.first][point.second] = searched;
    for(auto &cm:command){
        int next_h = point.first + cm.first;
        int next_w = point.second + cm.second;
        if(next_h<0 || next_h>=H){
            continue;
        }
        if(next_w<0 || next_h>=W){
            continue;
        }
        if(field[next_h][next_w]==road){
            pair<int, int> next_p = make_pair(next_h, next_w);
            int result = solve(next_p);
            if(result==1){
                return result;
            }else{
                continue;
            }
        }else if(field[next_h][next_w]==goal){
            return 1;
        }
    }
    return 0;
}

int main()
{
    char input;
    pair<int, int> st_p;
    scanf("%d %d", &H, &W);
    // cout << H <<" "<< W << "\n";
    field.resize(H);
    for (int i = 0; i < H; i++)
    {
        field[i].resize(W);
        for (int j = 0; j < W; j++)
        {
            cin >> input;
            if (input == 's')
            {
                field[i][j] = 0;
                st_p = make_pair(i, j);
            }
            else if (input == 'g')
            {
                field[i][j] = 1;
            }
            else if (input == '.')
            {
                field[i][j] = 2;
            }
            else if (input == '#')
            {
                field[i][j] = 3;
            }
        }
    }

    int result = solve(st_p);
    if(result==1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}