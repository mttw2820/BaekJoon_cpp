//BaekJoon_6064
//카잉 달력
/*
* 제한 시간 : 1s
* 정답 비율 : 24.048%
*/

#include <iostream>
using namespace std;

int solution(){
    int m, n, x, y;
    scanf("%d %d %d %d", &m, &n, &x, &y);
    
    int result = x;
    int pro_y = x;
    while (pro_y > n) pro_y -= n;
    int start_p = pro_y;

    while(pro_y != y){
        pro_y += m;
        result += m;
        while(pro_y > n) pro_y -= n;

        if(pro_y == start_p) return -1;
    }

    return result;
}
int main(){
    int testcase = 0;
    scanf("%d", &testcase);
    for(int i=0; i<testcase; i++){
        int result = solution();
        printf("%d\n", result);
    }
    return 0;
}