#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int maxNum = 0;
    
	// 정수와 해당 정수의 등장 횟수를 저장하기 위한 unordered_map
    unordered_map<int, int> um; 

    // 배열을 순회하며 각 숫자의 등장 횟수를 세는 과정
    for (const auto num : array) {
        um[num]++;
    }

    // unordered_map을 순회하며 최빈값을 찾는 과정
    for (const auto& num : um) {
        if (num.second > maxNum) { // 현재 등장 횟수가 최빈값보다 큰 경우
            maxNum = num.second; // 최빈값을 업데이트
            answer = num.first; // 해당 숫자를 정답으로 설정
        } else if (num.second == maxNum) { // 현재 등장 횟수가 최빈값과 같은 경우
            answer = -1; // 최빈값이 여러 개인 경우 -1을 정답으로 설정
        }
    }
    return answer;
}