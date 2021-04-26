//BaekJoon_14888
//연산자 끼워넣기
/*
* 제한 시간 : 2s
* 정답 비율 : 49.594%
*/

#include <iostream>
#define MAX 100000000;
#define MIN -100000000;
using namespace std;

int number[15] = {0,};

struct result{
    int max_result;
    int min_result;
    result(int ma, int mi): max_result(ma), min_result(mi){}
};

void get_input(int &n, int (&op_limit)[5]){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &number[i]);
    }
    for(int i=0; i<4; i++){
        scanf("%d", &op_limit[i]);
    }
    return;
}

result dfs_calc(int n, int now, int prev_result, int op_limit[]){
    if(now == n-1){   // end condition
        return result(prev_result, prev_result);
    }

    int min_r = MAX;
    int max_r = MIN;
    result temp(0, 0);
    
    int next_result = 0;
    for(int i=0; i<4; i++){
        if(op_limit[i] == 0) continue;
        op_limit[i] --;

        // calculate next result
        if(i == 0){         // plus
            next_result = prev_result + number[now+1];
        }
        else if(i == 1) {   // minus
            next_result = prev_result - number[now+1];
        }
        else if(i == 2) {   // multiply
            next_result = prev_result * number[now+1];
        }
        else {              // division
            if(prev_result < 0) next_result = -((-prev_result)/number[now+1]);
            else next_result = prev_result / number[now+1];
        }

        temp = dfs_calc(n, now + 1, next_result, op_limit);
        op_limit[i] ++;

        // check min, max result;
        if(temp.min_result < min_r) min_r = temp.min_result;
        if(temp.max_result > max_r) max_r = temp.max_result;
    }
    return result(max_r, min_r);
}
int main(){
    int n;
    int op_limit[5] = {0,};
    get_input(n, op_limit);
    result total = dfs_calc(n, 0, number[0], op_limit);
    printf("%d\n%d\n", total.max_result, total.min_result);
    return 0;
}