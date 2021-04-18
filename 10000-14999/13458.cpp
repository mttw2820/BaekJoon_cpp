//BaekJoon_13458
//시험 감독
/*
* 제한 시간 : 2s
* 정답 비율 : 26.274%
*/

#include <iostream>
using namespace std;

int ppl[1000005] = {0,};
void get_input(int &n, int &total, int &assist){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &ppl[i]);
    }
    scanf("%d %d", &total, &assist);
    return;
}

long long count_supervision(int n, int total, int assist){
    long long cnt = n;
    for(int i=0; i<n; i++){
        ppl[i] -= total;
        if(ppl[i] > 0) {
            cnt += ppl[i] / assist;
            if(ppl[i] % assist != 0) cnt ++;
        }
    }
    return cnt;
}
int main(){
    int n, total, assist;
    get_input(n, total, assist);

    long long count = count_supervision(n, total, assist);
    printf("%lld\n", count);

    return 0;
}