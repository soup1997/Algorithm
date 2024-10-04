#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {   
    int fusionNum = 0;
    
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 2; j < i; j++){ // 자기자신과 1은 제외
            if(i % j == 0) cnt++;
            
            if(cnt >= 1){
                fusionNum++; // 자기자신과 1은 제외하므로 cnt가 1이상이면 됨
                break;
            }
        }
    }
    
    return fusionNum;
}