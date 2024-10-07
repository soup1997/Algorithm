#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    string answer = "", tmp = "";
    vector<string> num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for(int i = 0; i < s.length(); i++) {
        if('0' <= s[i] && s[i] <= '9') answer += s[i];
        else tmp += s[i];
        
        if(find(num.begin(), num.end(), tmp) != num.end()) {
            answer += to_string(find(num.begin(), num.end(), tmp) - num.begin());
            tmp = ""; // tmp를 다시 빈문자열로 바꿈
        }
    }
    return stoi(answer);
}