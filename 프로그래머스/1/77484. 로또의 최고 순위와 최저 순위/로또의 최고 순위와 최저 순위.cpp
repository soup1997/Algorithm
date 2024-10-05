#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int convert2Rank(const int &cnt){
    switch(cnt){
        case 6:
            return 1;  // 6개 맞춘 경우 1등
        case 5:
            return 2;  // 5개 맞춘 경우 2등
        case 4:
            return 3;  // 4개 맞춘 경우 3등
        case 3:
            return 4;  // 3개 맞춘 경우 4등
        case 2:
            return 5;  // 2개 맞춘 경우 5등
        default:
            return 6;  // 그 외는 6등
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int matched = 0, zeroCount = 0;
    
    // 당첨 번호를 쉽게 찾기 위한 정렬
    sort(win_nums.begin(), win_nums.end());
    
    // 로또 번호와 당첨 번호 비교
    for (int num : lottos) {
        if (num == 0) {
            zeroCount++;  // 0의 개수를 카운트
        } else if (find(win_nums.begin(), win_nums.end(), num) != win_nums.end()) {
            matched++;  // 일치하는 번호가 있으면 카운트
        }
    }
    
    // 최고 순위: 0의 개수만큼 추가로 맞힐 수 있음
    int maxRank = convert2Rank(matched + zeroCount);
    // 최저 순위: 0을 모두 틀린 것으로 가정
    int minRank = convert2Rank(matched);
    
    return {maxRank, minRank};
}