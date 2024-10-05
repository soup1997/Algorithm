#include <string>
#include <vector>


using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(char c: s){
        if (c == ' '){
            answer += ' ';
        }
        
        else{
            char newC;
            if(c >= 'a' && c <= 'z'){ // 소문자인 경우
                newC = ((c - 'a' + n) % 26) + 'a';
            }
            
            else{ // 대문자인 경우
                newC = ((c - 'A' +  n) % 26) + 'A';
            }
            answer += newC;
        }
    }
    return answer;
}