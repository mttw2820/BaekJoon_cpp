//BaekJoon_2407
//조합
/*
* 제한 시간 : 2s
* 정답 비율 : 34.485%
*/

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

string comb[105][55];
bool check[105][55] = {false,};

// s1이 더 긴 string이 되도록 swap
void swap_str(string &s1, string &s2){
    int s1_len = s1.length();
    int s2_len = s2.length();
    if(s1_len >= s2_len) return;

    string temp = s1;
    s1 = s2;
    s2 = temp;
    return;
}

// 두 string의 정수 덧셈 연산
string str_plus(string s1, string s2){
    string new_s = "";
    swap_str(s1, s2);
    int s1_len = s1.length();
    int s2_len = s2.length();

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int num1, num2, sum, upnum = 0;
    for(int i=0; i<s1_len; i++){
        num1 = s1[i] - '0';
        if(i < s2_len) num2 = s2[i] - '0';
        else num2 = 0;
        sum = num1+num2+upnum;
        if(sum>=10){
            upnum = 1;
            sum -= 10;
        } else upnum = 0;
        new_s += (sum + '0');
    }
    if(upnum == 1) new_s += '1';

    reverse(new_s.begin(), new_s.end());
    return new_s;
}

string make_comb(int n, int m){
    // nCm = nC(m-n)
    if(m*2 > n) m = n-m;

    // nC0 = 1, nC1 = n
    if(m==0){ 
        comb[n][m] = "1";
        check[n][m] = true;
    }
    else if(m==1) {
        comb[n][m] = to_string(n);
        check[n][m] = true;
    }

    // 이미 구한 값이면 comb 값
    if(check[n][m]) {
        return comb[n][m];
    }
    else{
        // 없는 값은 재귀함수로
        string first_comb = make_comb(n-1, m-1);
        string second_comb = make_comb(n-1, m);
        comb[n][m] = str_plus(first_comb, second_comb);
        check[n][m] = true;
        return comb[n][m];
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    string result = make_comb(n, m);
    cout << result.c_str() << endl;
    return 0;
}