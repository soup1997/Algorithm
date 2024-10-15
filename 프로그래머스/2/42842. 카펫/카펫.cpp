#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// brown + yellow 를 합친 수의 약수를 구하기
vector<int> getDivisor(int num){
    vector<int> divisor;
    
    int end = static_cast<int>(sqrt(num));
    
    for(int i = 1; i <= end; i++){
        if(num % i == 0){
            divisor.push_back(i);
            if(i != num / i){
                divisor.push_back(num /i);
            }
        }
    }
    sort(divisor.begin(), divisor.end()); // 구해진 약수를 오름차순으로 정렬
    return divisor;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> divisor = getDivisor(brown+yellow); // 약수 구하기
    
    int idx1 = 0, idx2 = divisor.size() - 1;
    
    while(idx1 <= idx2){ // 투 포인터로 pair씩 가져오기
        int num1 = divisor[idx1], num2 = divisor[idx2];
        
        if((num1 - 2) * (num2 - 2) == yellow){ // 양끝에서 2씩 뺀값이 노란색 타일의 사이즈
            answer.push_back(num2);
            answer.push_back(num1);
            break;
        }
        idx1++;
        idx2--;
    }
    
    return answer;
}