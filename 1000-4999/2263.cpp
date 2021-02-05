//BaekJoon_2263
//트리의 순회
/*
* 제한 시간 : 5s
* 정답 비율 : 37.130%
*/

#include <iostream>
using namespace std;

int inorder[100010];
int postorder[100010];

void get_input(int &n){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &inorder[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &postorder[i]);
    }
}

void pre_order(int in_s, int in_e, int post_s, int post_e){
    // post order 맨 끝 노드가 루트 노드
    int root = postorder[post_e];
    printf("%d ", root);

    // 종료 조건
    if(in_s == in_e) return;

    for(int i=in_s; i<=in_e; i++){
        if(root == inorder[i]){
            if(i!=in_s) pre_order(in_s, i-1, post_s, post_s + i - in_s - 1);
            if(i!=in_e) pre_order(i + 1, in_e, post_s + i - in_s, post_e - 1);
            break;
        }
    }
    return;
}

int main(){
    int n;
    get_input(n);
    pre_order(0, n-1, 0, n-1);

    return 0;
}