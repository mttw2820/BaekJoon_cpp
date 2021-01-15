//BaekJoon_1152
//단어의 개수
/*
* 제한 시간 : 2s
* 정답 비율 : 27.719%
*/

#include <iostream>
#include <string>
using namespace std;

int count_word(string str){
    int blank_w = 0;
    int start_point = 0, point = 0;

    while(start_point != string::npos){
        // find에 실패하면 npos 리턴
        point = str.find(' ', start_point + 1);
        start_point = point;
        // 맨 앞, 맨 끝의 공백은 무시
        if((point > 0) && (point < str.length()-1)){
            blank_w++;
        }
    }

    // 공백만 있거나 입력이 없는 경우는 공백 수와 상관없이 0
    if(str == " " || str.length() == 0) return 0;
    // 단어 수 = 공백 + 1
    return blank_w + 1;
}

int main(){
    string str;
    getline(cin, str);
    int words = count_word(str);
    printf("%d", words);
    return 0;
}