#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int getDivisor(const int &number){
    if(number == 1){
        return 1;
    }
    
    else{
        vector<int> divisor;
        int rootN = static_cast<int>(sqrt(number));

        for(int i=1; i <= rootN; i++){
            if(number % i == 0){
                divisor.emplace_back(i);
                if(i != number / i){
                    divisor.emplace_back(number / i);
                }
            }
        }
        return divisor.size();
    }
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; i++){
        int cnt = getDivisor(i);
        
        if(cnt > limit){
            answer += power;
        }
        else{
            answer += cnt;
        }
    }
    
    return answer;
}