#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool checkPrimeNumber(int n){
    int root_n = static_cast<int>(sqrt(n));
    
    for(int i = 2; i <= root_n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    
    for(int i = 2; i <= n; i++){
        if(checkPrimeNumber(i)) answer++;
    }
    
    return answer;
}