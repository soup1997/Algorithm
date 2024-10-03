#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{   
    if(s[0] == ')') return false; // 바로 리턴
    
    bool answer = true;
    stack<char> check;
    
    for(char c: s){
        if(c == '('){
            check.push(c);
        }
        
        else{
            if(!check.empty() && c == ')' && check.top() == '('){
                check.pop();
            }
        }
        
    }
    
    if(check.empty()){
        return true;
    } else{
        return false;
    }
}