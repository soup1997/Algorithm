#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int idx1 = 0, idx2 = people.size() - 1;
    while (idx1 <= idx2){
        int minWeight = people[idx1];
        int maxWeight = people[idx2];
        
        if(minWeight + maxWeight > limit){
            idx2--;
        }
        
        else{
            idx1++;
            idx2--;
        }
        answer++;
    }
    return answer;
}