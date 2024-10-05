#include <cmath>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long a = sqrt(n);
    
    if (a*a == n) {	// 양의 정수x의 제곱인 경우
        answer= (a+1) * (a+1);
    }
    else {	// 아닌 경우
        answer=-1;
    }
    return answer;
}