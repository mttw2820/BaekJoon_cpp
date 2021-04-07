//BaekJoon_15829
//Hashing
/*
* 제한 시간 : 1s
* 정답 비율 : 34.039%
*/

#include <iostream>
#define P_NUM 31
#define MOD 1234567891
using namespace std;

void get_input(int &L, char apc[]){
    scanf("%d", &L);
    scanf("%s", apc);
    return;
}

void make_hash_number(int L, char apc[55]){
    char stand = 'a';
    long long a = 0;
    long long power = 1;
    long long hash_number = 0;

    for(int i=0; i<L; i++){
        a = apc[i] - stand + 1;
        a = a * power % MOD;
        hash_number = (hash_number + a) % MOD;
        power = power * P_NUM % MOD;
    }

    printf("%lld\n", hash_number);
    return;
}

int main(){
    char apc[55];
    int L;

    get_input(L, apc);
    make_hash_number(L, apc);

    return 0;
}