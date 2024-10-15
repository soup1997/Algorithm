#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    long long N = static_cast<long long>(n);
    
    while(N > 0){ // N >= 0이면 무한 실행 된다
        
        if (N % 2 == 0){ // 텔레포트
            N /= 2;
        } else{ // 점프
            N -= 1;
            ans++;
        }
    }

    return ans;
}