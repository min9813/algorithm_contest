#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int N;
char F[100], Ans[198];

char question(int index){
    string s = "?";
    for (int i=index;i<index+N;i++){
        s += " ";
        s += to_string(i);
    }
    cout << s << "\n" << flush;
    cin >> s;
    fflush(stdout);
    return s[0];
}

void print_vec(vector<int> vec){
    for(int i=0;i<vec.size();i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int BinarySearch(int start, int end){
    int left = start;
    int right = end;
    int middle;
    bool is_middle_next_right = false;
    char ans;
    while (left + 1< right){
        middle = (left + right) / 2;
        ans = question(middle+1);
        F[middle] = ans;
        is_middle_next_right = F[right] == ans;
        // printf("%lld %lld %lld\n", middle, left, right);
        if (is_middle_next_right){
            // printf("yes");
            right = middle;
        }else{
            // printf("no");
            left = middle;
        }
    }
    return left;
}

char question(string s){
    cout << s << "\n" << flush;
    cin >> s;
    return s[0];
}


int main(){
    char ans;
    int diff_index, i, j;
    string question_msg;
    int check = scanf("%d", &N);
    vector<int> T1,T2,T3;
    F[0] = question(1);
    if(F[0]=='R'){
        F[N] = 'B';
    }else{
        F[N] = 'R';
    }

    diff_index = BinarySearch(0,N);
    // printf("diff index: %d, C=%c", diff_index, F[diff_index]);
    for(i=0;i<2*N;i++){
        if(i<diff_index){
            T2.push_back(i+1);
        }else if(diff_index+N<i){
            T3.push_back(i+1);
        }else if(diff_index<i && i<diff_index+N){
            T1.push_back(i+1);
        }
    }
    // printf("\n");
    // cout << "print T3" << endl << flush;

    // print_vec(T3);
    // cout << "print T2" << endl << flush;
    // print_vec(T2);
    // cout << "print T1" << endl << flush;
    // print_vec(T1);


    for(i=0;i<2*N;i++){
        if(i==diff_index){
            Ans[i] = F[i];
            if(F[i] == 'R'){
                Ans[i+N] = 'B';
            }else{
                Ans[i+N] = 'R';
            }
        }else if(diff_index<i && i < diff_index+N){
            question_msg = "?";
            for(j=0;j<T2.size();j++){
                question_msg += " ";
                question_msg += to_string(T2[j]);
            }
            question_msg += " ";
            question_msg += to_string(i+1);
            for(j=0;j<T3.size();j++){
                question_msg += " ";
                question_msg += to_string(T3[j]);
            }
            Ans[i] = question(question_msg);
        }else if(i<diff_index || diff_index+N<i){
            question_msg = "?";
            for(j=0;j<T1.size();j++){
                question_msg += " ";
                question_msg += to_string(T1[j]);
            }
            string insert_msg = " " + to_string(i+1);
            if(i<T1[0]){
                question_msg.insert(1, insert_msg);
            }else{
                question_msg.append(insert_msg);
            }
            Ans[i] = question(question_msg);
        }else{
            continue;
        }
    }

    printf("! ");
    for(i=0;i<2*N;i++){
        printf("%c", Ans[i]);
    }
    printf("\n");

    return 0;
}