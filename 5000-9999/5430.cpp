//BaekJoon_5430
//AC
/*
* 제한 시간 : 1s
* 정답 비율 : 20.152%
*/

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

int arr[100001]={0,};
char arr_str[400010] = "";  // 숫자가 아니라 문자열 배열^^

void get_input(string &order, int &arr_size){
    cin >> order;
    scanf("%d", &arr_size);

    int index = 0;
    scanf("%s", arr_str);
    // 숫자 하나씩 strtok
    char *ptr = strtok(arr_str, "[, ");
    while(ptr != NULL){
        arr[index++] = atoi(ptr);
        ptr = strtok(NULL, "[,] ");
    }
    return;
}

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
    return;
}

void make_order(string &order, int arr_size){
    int front = 0, end = arr_size - 1;
    int isFront = -1;   // 앞 인덱스면 -1, 뒤 인덱스면 1
    int order_len = order.length();

    for(int i=0; i<order_len; i++){
        if(order[i] == 'R'){
            swap(front, end);
            isFront = -isFront;
        }
        else {
            front = front - isFront;
        }
    }
    if(isFront < 0 && front <= end+1) {
        if(front == end + 1) printf("[]\n");
        else{
            // 정방향
            printf("[");
            for(int i=front; i<end; i++){
                printf("%d,", arr[i]);
            }
            printf("%d]\n", arr[end]);
        }
    }
    else if(isFront > 0 && front >= end - 1){
        if(front == end -1) printf("[]\n");
        else{
            // 역방향
            printf("[");
            for(int i=front; i>end; i--){
                printf("%d,", arr[i]);
            }
            printf("%d]\n", arr[end]);
        }
    }
    else printf("error\n");

    return;
}

int main(){
    int testcase = 0, arr_size = 0;
    string order;

    scanf("%d", &testcase);
    for(int i=0; i<testcase; i++){
        get_input(order, arr_size);
        make_order(order, arr_size);
    }
    return 0;
}