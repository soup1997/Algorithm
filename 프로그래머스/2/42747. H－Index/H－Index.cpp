#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<>()); // 오름차순 정렬

    if (!citations[0]) return 0; // 제일 많은 인용횟수가 0이면 볼 필요도 없음

    for(int i=0; i<citations.size(); i++){ // {6, 5, 3, 1, 0}
        if(citations[i] >= i+1){
            answer++;
        }  
    }
    return answer;
}