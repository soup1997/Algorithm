#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    unordered_map<char, int> um; // 문자와 인덱스
    
    for(int i=0; i < s.length(); i++){
        auto iter = um.find(s[i]);
        if(iter == um.end()){
            um[s[i]] = i;
            answer.push_back(-1);
        }
        
        else{
            answer.push_back(i - um[s[i]]);
            um[s[i]] = i;
        }
    }
    return answer;
}