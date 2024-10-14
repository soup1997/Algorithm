#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    // a는 오름차순, b는 내림차순 정렬
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    for(int i = 0; i < A.size(); i++){
        answer += A[i] * B[i];
    }

    return answer;
}