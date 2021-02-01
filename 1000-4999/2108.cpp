//BaekJoon_2108
//통계학
/*
* 제한 시간 : 2s
* 정답 비율 : 26.661%
*/

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int num[500001]={0,};

long double arith_avg(int n){
    long double sum = 0;
    for(int i=0; i<n; i++){
        sum += (long double)num[i];
    }
    sum /= (long double) n;
    return sum;
}

int mode(int n){
    int cnt[8001] = {0,};
    for(int i=0; i<n; i++){
        cnt[num[i]+4000]++;
    }
    int mode_num = num[0], mode_cnt = cnt[num[0]+4000];
    bool flag_second = true;
    for(int i=1; i<n; i++){
        if(num[i-1] == num[i]) continue;
        if(mode_cnt < cnt[num[i]+4000]){
            mode_num = num[i];
            mode_cnt = cnt[num[i]+4000];
            flag_second = true;
        }
        else if(mode_cnt == cnt[num[i]+4000]){
            if(flag_second){
                mode_num = num[i];
                flag_second = false;
            }
        }
    }
    return mode_num;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num[i]);
    }
    sort(num, num+n);
    // 산술 평균
    cout << round(arith_avg(n)) << endl;
    // 중앙값
    cout << num[(n+1)/2-1] << endl;
    // 최빈값
    cout << mode(n) << endl;
    // 범위
    cout << num[n-1] - num[0] << endl;

    return 0;
}