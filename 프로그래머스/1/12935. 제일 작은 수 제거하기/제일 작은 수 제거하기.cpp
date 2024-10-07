#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size() == 1){
        return {-1};
    }
    
    else{
        int minNum = *min_element(arr.begin(), arr.end());
        for(const auto &a : arr){
            if(a != minNum){
                answer.emplace_back(a);
            }
        }
    }
    return answer;
}