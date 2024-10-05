#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, int> m; // ordered map (오름차순 정렬)
    
    for(int i = 0; i < numbers.size() - 1; i++){
        for(int j = i + 1; j < numbers.size(); j++){
            int comb = numbers[i] + numbers[j];
            m[comb] = 0;
        }
    }
    
    for (auto it = m.begin(); it != m.end(); ++it) {
        answer.push_back(it->first);
    }
    
    return answer;
}