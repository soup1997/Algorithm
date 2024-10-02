#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    if (nums.size() == 1){
        return 1;
    }
    
    else{
        int targetNum = nums.size() / 2;
        
        map<int, int> bag;
        for(auto n: nums){
            bag[n]++;  // Simply increment the count of each number
        }
        
        int monsterType = bag.size(); // 몬스터 종류갯수
        
        if(monsterType > targetNum){ // 몬스터 종류 갯수가 더 많으면 N/2 가져가면 된다.
            return targetNum;
        }
        
        else{ // 아니라면 몬스터 종류만큼 가져가면 된다.
            return monsterType;
        }
    }
}