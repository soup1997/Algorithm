#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char setRange(char c){
    return 'a' + ((c - 'a') % 26);
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(auto c: s){
        int cnt = 0;
        char newC = c;
        
        while(cnt != index){
            newC = setRange(newC + 1);
            
            if(skip.find(newC) == string::npos){
                cnt++;
            }
        }
        answer += newC;
    }
    return answer;
}