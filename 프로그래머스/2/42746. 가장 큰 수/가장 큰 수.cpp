#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    string sa = to_string(a); // 숫자를 문자열로 변환
    string sb = to_string(b); // 숫자를 문자열로 변환
    
    string n1 = sa + sb; // 문자열 합치기
    string n2 = sb + sa; // 문자열 합치기
    
    
    int num1 = stoi(n1);
    int num2 = stoi(n2);
    
    return num1 > num2;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    
    string answer = "";
    
    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    
    if (answer[0] == '0') {
        return "0";
    }
    
    else{
        return answer;
    }
}
