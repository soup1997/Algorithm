#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end()); // 오름차순 정렬
    
    if(numbers[0] < 0 && numbers[1] < 0){
        int tmpMax1 = numbers[0] * numbers[1];
        int tmpMax2 = numbers[numbers.size()-2] * numbers[numbers.size()-1];
        
        if(tmpMax1 > tmpMax2) return tmpMax1;
        else return tmpMax2;
    }
    
    return numbers[numbers.size()-2] * numbers[numbers.size()-1];
}