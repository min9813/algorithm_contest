#include<vector>
#include<cstdio>
using namespace std;
static const int length = 8;
static const int NOT_FREE = 1;
static const int FREE = 0;

vector<vector<int>> field(length, vector<int>(length, FREE));
vector<int> row(length, FREE), col(length, FREE), dpos(2*length-1, FREE), dneg(2*length-1, FREE);
int n;

void print_board();

void set_array(int n_row, int n_col, int set_value){
    row[n_row] = set_value;
    col[n_col] = set_value;
    dpos[n_col+n_row] = set_value;
    dneg[n_row+length - 1 - n_col] = set_value;
    field[n_row][n_col] = set_value;
}

bool is_all_free(int n_row, int n_col){
    return col[n_col]==FREE && dpos[n_col+n_row]==FREE && dneg[n_row+length - 1 - n_col]==FREE;
}

bool back_track(int n_row){
    // printf("---- n_row = %d ---\n", n_row);
    // print_board();
    if(n_row == length){
        print_board();
        return true;
    }else if(row[n_row]==NOT_FREE){
        back_track(n_row+1);
    }else{
        for(int i=0;i<length;i++){
            if(is_all_free(n_row, i)){
                set_array(n_row, i, NOT_FREE);
                bool is_ok = back_track(n_row+1);
                if(is_ok){
                    return is_ok;
                }else{
                    set_array(n_row, i, FREE);
                }
                
            }
        }
    }

    return false;
}

void print_board(){
    int i, j;
    for(i=0;i<length;i++){
        for(j=0;j<length;j++){
            if(field[i][j]){
                printf("Q");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
}



int main(){
    int x, y;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &x, &y);
        field[x][y] = NOT_FREE;
        row[x] = NOT_FREE;
        col[y] = NOT_FREE;
        dpos[x+y] = NOT_FREE;
        dneg[x+length-1-y] = NOT_FREE;
    }
    back_track(0);
    
}