#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// vector를 slice하는 함수
vector<int> slice(vector<int> &score, int a, int b) {
    return vector<int>(score.begin() + a, score.begin() + b); // Corrected slice bounds
}

int solution(int k, int m, vector<int> score) {
    int price = 0;
    
    sort(score.begin(), score.end(), greater<>()); // 내림차순 정렬
    
    int idx = 0;
    while (idx + m - 1 < score.size()) {
        vector<int> segScore = slice(score, idx, idx + m); // Slice m elements
        price += (segScore[m-1] * m); // Multiply smallest value by m
        idx += m; // Move forward by m
    }
    
    return price;
}