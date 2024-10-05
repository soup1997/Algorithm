#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int iteration = 0;
    
    long long cNum = static_cast<long long>(num); // int 자료형 범위를 넘어갈 수 있으므로 long long으로 변환
    
    while(iteration < 500){
        if(cNum == 1){
            return iteration;
        }
        
        else{
            if(cNum % 2 == 0){
                cNum /= 2;
            } else{
                cNum = (cNum * 3) + 1;
            }
            iteration++;
        }
    }
    return -1;
}