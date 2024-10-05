#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string convert2Triple(int n){
    string s = "";
    
    // n이 0보다 클 때까지 3으로 나누면서 나머지를 문자열에 추가
    while(n > 0){
        s += to_string(n % 3); // 나머지를 문자열에 추가
        n /= 3;  // n을 3으로 나눔
    }
    return s;  // 3진법으로 변환된 문자열 (역순으로 저장됨)
}

int solution(int n) {
    string s = convert2Triple(n);  // 3진법으로 변환된 문자열
    int power = s.length()-1;  // 역순으로 처리되기 때문에 power는 처음에 0으로 시작
    int answer = 0;
    
    for(char c: s){
        answer += (c - '0') * pow(3, power);  // 3의 제곱을 계산하여 더함
        power--;
    }
    
    return answer;
}