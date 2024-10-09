#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a){
        int coke = (n / a) * b; // 새로 받은 콜라
        answer += coke;
        n = (n % a) + coke;
    }
    
    return answer;
}