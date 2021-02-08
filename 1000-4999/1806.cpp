//BaekJoon_1806
//부분합
/*
* 제한 시간 : 0.5s
* 정답 비율 : 25.379%
*/

#include <iostream>
#define MAX 1000000
using namespace std;

int num[MAX+10]={0,};
void get_input(int &n, int &target){
    scanf("%d %d", &n, &target);
    for(int i=0; i<n; i++){
        scanf("%d", &num[i]);
    }
    return;
}

int min_sum(int n, int target){
    int s=0, e=0;
    int min_len = 0;
    int sum = num[0];

    while(s<=n && e<=n){
        if(sum >= target){
            if(min_len ==0 || e-s+1 < min_len) min_len = e-s+1;
            sum -= num[s++];
        }
        else if(sum < target){
            sum += num[++e];
        }   
    }

    return min_len;
}
int main(){
    int n, target;
    get_input(n, target);
    int result = min_sum(n, target);
    printf("%d\n", result);
    return 0;
}