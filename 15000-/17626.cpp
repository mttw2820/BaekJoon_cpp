//BaekJoon_17626
//Four Squares
/*
* 제한 시간 : 0.5s
* 정답 비율 : 56.596%
*/

#include <iostream>
#include <vector>
#define MAX 50000
using namespace std;

void basic_square(int n, vector<int> &sq){
    for(int i=1; ; i++){
        if(i*i > n) break;
        sq[i*i] = 1;
    }
    return;
}

void make_sum(int n, vector<int> &sq){
    for(int num=2; num<=n; num++){
        if(sq[num] == 1) continue;
        for(int i=1; i<=num/2; i++){
            if(sq[num] == 0 || sq[num] > sq[i] + sq[num-i]){
                sq[num] = sq[i] + sq[num-i];
            }
        }
    }
    return;
}
int main(){
    int n;
    vector<int> sq(MAX+5, 0);
    scanf("%d", &n);
    basic_square(n, sq);
    make_sum(n, sq);
    printf("%d\n", sq[n]);
    return 0;
}