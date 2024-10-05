#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int isPrime(const int &num){
    for(int i=2; i < num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int solution(vector<int> nums) {
    sort(nums.begin(), nums.end());
    
    int answer = 0;

    for(int i = 0; i < nums.size() - 2; i++){
        for(int j = i + 1; j < nums.size() - 1; j++){
            for(int k = j + 1; k < nums.size(); k++){
                int number = nums[i] + nums[j] + nums[k];
                answer += isPrime(number);
            }
        }
    }

    return answer;
}