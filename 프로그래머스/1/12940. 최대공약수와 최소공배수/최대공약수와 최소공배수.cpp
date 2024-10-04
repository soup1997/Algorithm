#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if(m % n == 0){
        answer.push_back(n);
        answer.push_back(m);
    } 
    else{
        int maxNum = 1;
        for(int i=1; i < n; i++){
            if(n % i == 0 && m % i == 0){
                maxNum = max(maxNum, i);
            }
        }
        answer.push_back(maxNum);
        int n1 = n / maxNum;
        int n2 = m / maxNum;
        answer.push_back(maxNum * n1 * n2);
    }
    
    return answer;
}