//BaekJoon_5525
//IOIOI
/*
* 제한 시간 : 1s
* 정답 비율 : 31.994%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_pattern(int &index, int len, string &str, vector<int> &pattern){
    // out of range
    if(index + 1 >= len) {
        return false;
    }

    if(str[index] == 'O' && str[index+1] == 'I') {
        pattern[index+1] = pattern[index-1] + 1;
        index++;
        return true;
    }
    else {
        index--;
        return false;
    }
}
void count_pattern(int len, string &str, vector<int> &pattern){
    bool ispattern = false;
    for(int i=0; i<len; i++){
        if(ispattern){
            ispattern = check_pattern(i, len, str, pattern);
        }
        else{
            if(str[i] == 'I')
                ispattern = true; 
        }
    }
}

void print_result(int n, vector<int> &pattern){
    int size = pattern.size();
    int count = 0;
    for(int i=0; i<size; i++){
        if(pattern[i]>=n) count++;
    }

    printf("%d\n", count);
}
int main(){
    // get input
    int n, len;
    string str;
    vector<int> pattern(1000001, 0);

    scanf("%d %d", &n, &len);
    cin >> str;

    count_pattern(len, str, pattern);
    print_result(n, pattern);

    return 0;
}