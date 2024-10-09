#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    // 기약분수를 만들기 위해서 최대 공약수를 구함
    int maxNumber = 1;
    for(int i = 1; i <= a; i++) {
        if(a % i == 0 && b % i == 0) {
            maxNumber = i;
        }
    }
    // 기약분수로 바꾸기
    b /= maxNumber;
    a /= maxNumber;
    
    // 분모 b의 소인수가 2 또는 5로만 이루어져 있는지 확인
    while(b % 2 == 0) b /= 2;
    while(b % 5 == 0) b /= 5;
    
    // b가 1이면 분모는 2 또는 5로만 이루어져 있다는 뜻
    if(b == 1) {
        return 1;
    }
    
    return 2;
}
