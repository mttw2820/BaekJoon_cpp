//BaekJoon_2439
//별 찍기 - 2
/*
* 제한 시간 : 1s
* 정답 비율 : 57.948%
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=0; j< n-i; j++){
            printf(" ");
        }
        for(int j=0; j<i;j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}