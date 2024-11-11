#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> um1;
    
    for(int i = 0; i < want.size(); i++){
        um1[want[i]] = number[i];
    }
    
    for(int i = 0; i < discount.size(); i++){
        if(i + 10 <= discount.size()){
            unordered_map<string, int> um2;
            bool flag = true;
            
            for(int j = i; j < i + 10; j++){
                um2[discount[j]]++;
            }
            
            for(const auto &item: um1){
                if(um2[item.first] != item.second){
                    flag = false;
                    break;
                }
            }
            
            if(flag) answer++;
        }
    }
    
    return answer;
}