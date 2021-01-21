//BaekJoon_1541
//잃어버린 괄호
/*
* 제한 시간 : 2s
* 정답 비율 : 48.192%
*/

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

void make_border(stack<long long> &calc, char* formula, int f_len){
    long long num = 0;
    long long calc_plus = 0;

    for(int i=0; i<f_len; i++){
        switch(formula[i]){
        case '+':
            calc_plus += num;
            num = 0;
            break;
        case '-':
            calc_plus += num;
            calc.push(calc_plus);
            num = 0;
            calc_plus = 0;
            break;
        default :
            num = num*10 + (formula[i]-'0');
            break;
        }
    }

    calc_plus += num;
    calc.push(calc_plus);
    return;
}

long long calc_min_result(stack<long long> &calc){
    long long result = 0;

    while(calc.size() != 1){
        result += calc.top();
        calc.pop();
    }
    result = calc.top() - result;

    return result;
}

int main(){
    char formula[55]; int f_len = 0;
    scanf("%s", formula);
    f_len = strlen(formula);

    stack<long long> calc;
    make_border(calc, formula, f_len);

    long long result = calc_min_result(calc);
    printf("%lld\n", result);

    return 0;
}