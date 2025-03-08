#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int calculate(string s) {
    int res = 0;
    stack<int> nums;
    stack<char> ops;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == ' ') continue;
        if(c == '+' || c == '-' || c == '(')
            ops.push(c);
        else if(c == ')'){
            
        }
    }
    
    return res;
}

int main(){

    return 0;
}