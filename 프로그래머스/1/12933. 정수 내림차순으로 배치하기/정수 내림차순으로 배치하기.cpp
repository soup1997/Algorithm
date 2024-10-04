#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string s = to_string(n);
    vector<char> nums(s.length());
    for(char c: s){
        nums.push_back(c);
    }
    
    sort(nums.begin(), nums.end(), greater<>()); // 내림차순 정렬
    
    string answer;
    
    for(char n:nums){
        answer += n;
    }
    
    return stoull(answer);
}