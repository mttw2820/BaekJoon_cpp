//BaekJoon_3052
//나머지
/*
* 제한 시간 : 1s
* 정답 비율 : 61.033%
*/

#include <iostream>
#include <bitset>
using namespace std;

int main(){
    bitset<45> leftover;
    leftover.reset();
    
    int num;
    for(int i=0; i<10; i++){
        scanf("%d", &num);
        leftover[num%42] = 1;
    }

    cout << leftover.count() << endl;
    return 0;
}