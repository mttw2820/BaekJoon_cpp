#include <string>
#include <vector>
#include <map>
#include <stack>
#include <math.h>
using namespace std;

void next_exp(map<char, int> &exp){
    int temp = 0;
    if(exp['+'] > exp['-']) {
        temp = exp['*'];
        if(temp == 0){
            exp['*'] = exp['-'];
            exp['-'] = temp;
        }
        else {
            exp['*'] = exp['+'];
            exp['+'] = temp;
        }
    }
    temp = exp['+'];
    exp['+'] = exp['-'];
    exp['-'] = temp;
    return;
}

void init(vector<map<char, int>> & exps, string &expression, vector<int> &numbers, vector<char> &express){
    // initialize exps
    map<char, int> exp;
    exp['*'] = 0;
    exp['+'] = 1;
    exp['-'] = 2;
    exps.push_back(exp);
    
    for(int i=0; i<5; i++){
        next_exp(exp);
        exps.push_back(exp);
    }
    
    // initialize expression
    int len = expression.length();
    int num = 0;
    for(int i=0; i<len; i++){
        if(expression[i] == '*' || expression[i] == '-' || expression[i] == '+'){
            express.push_back(expression[i]);
            numbers.push_back(num);
            num = 0;
        }
        else{
            num = num * 10 + expression[i]-'0';
        }
    }
    numbers.push_back(num);
    
    return;
}

long long calc(map<char, int> exp, vector<int> numbers, vector<char> express){
    stack<long long> num;
    stack<char> ex;
    
    num.push(numbers[0]);
    int size_exp = express.size();
    for(int i=0; i<size_exp; i++){
        while(!ex.empty() && exp[ex.top()] <= exp[express[i]]){
            long long b = num.top();  num.pop();
            long long a = num.top();  num.pop();
            char e = ex.top();  ex.pop();
            if(e == '*') num.push(a*b);
            else if(e == '+') num.push(a+b);
            else num.push(a-b);
        }
        ex.push(express[i]);
        num.push(numbers[i+1]);
    }
    
    while(!ex.empty()){
        long long b = num.top();  num.pop();
        long long a = num.top();  num.pop();
        char e = ex.top();  ex.pop();
        if(e == '*') num.push(a*b);
        else if(e == '+') num.push(a+b);
        else num.push(a-b);
    }
    
    return abs(num.top());
}
long long solution(string expression) {
    long long answer = 0;
    vector<map<char, int>> exps;
    vector<int> numbers;
    vector<char> express;
    init(exps, expression, numbers, express);
    
    for(int i=0; i<6; i++){
        int result = calc(exps[i], numbers, express);
        if(result > answer) answer = result;
    }
    
    return answer;
}

int main(){
    int ans = solution("100-200*300-500+20");
    printf("%d\n", ans);
    return 0;
}