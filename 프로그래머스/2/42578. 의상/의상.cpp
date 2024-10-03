#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int num = 0, ans = 1; // 총 가짓 수, 정답
    unordered_map<string, vector<string>> um;
    
    for (const auto &c: clothes){ // &는 reference(참조자, 복사가 이루어지지 않음)
        string clothing_item = c[0];
        string clothing_type = c[1];     
        um[clothing_type].push_back(clothing_item);
        num++;
    }
    
    int answer = 1;
    for (const auto& value : um) {
        answer *= (value.second.size() + 1); // +1을 하는 이유는 각 카테고리에서 아이템을 착용하거나 아무것도 착용하지 않는 선택을 할 수 있기 때문
    }
    
    return answer-1;        
}