#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    vector<string> strings;
    int idx = 0;
    
    // 공백을 기준으로 나누기
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            strings.push_back(s.substr(idx, i - idx));  // Add word before space
            idx = i + 1;  // Move idx to character after space
        }
        if (i == s.length() - 1) {
            strings.push_back(s.substr(idx, i - idx + 1));  // Add last word
        }
    }
    
    // 짝수 인덱스는 대문자로, 홀수 인덱스는 소문자로 변환
    vector<string> memory;
    for (auto& word : strings) {
        string tmp = "";
        for (int j = 0; j < word.length(); j++) {  // Fix to word length
            if (j % 2 == 0) {
                tmp += toupper(word[j]);  // 짝수 인덱스는 대문자
            } else {
                tmp += tolower(word[j]);  // 홀수 인덱스는 소문자
            }
        }
        memory.push_back(tmp);
    }
    // Join the words back together with spaces
    string answer = "";
    for (int i = 0; i < memory.size(); i++) {
        answer += memory[i];
        if (i != memory.size() - 1) {
            answer += " ";  // Add space between words
        }
    }
    
    return answer;
}