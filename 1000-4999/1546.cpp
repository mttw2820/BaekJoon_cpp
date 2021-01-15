//BaekJoon_1546
//평균
/*
* 제한 시간 : 2s
* 정답 비율 : 48.976%
*/

#include <iostream>
using namespace std;

int main(){
    int n, score = 0, max_score = 0;
    int sum = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &score);
        max_score = max_score>score?max_score:score;
        sum += score;
    }
    
    float new_sum = (float)sum/(float)max_score*100.0;
    float new_average = new_sum/(float)n;

    printf("%f", new_average);
    return 0;
}