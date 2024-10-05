#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    
    if(k == 1){
        return numbers[0];
    }
    
    else{
        int idx = 0, cnt = 0;
        int target;
        while(cnt != k){
            target = numbers[idx % numbers.size()];
            idx += 2;
            cnt++;
        } 
        answer = target;
    }
    return answer;
}