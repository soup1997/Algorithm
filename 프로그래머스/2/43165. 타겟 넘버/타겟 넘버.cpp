#include <string>
#include <vector>

using namespace std;

int answer = 0;
int n;

void dfs(vector<int> &v, int idx, int sum, int &target){
    int tmp1 = sum + v[idx]; // + 조합
    int tmp2 = sum - v[idx]; // - 조합
    
    // 주어진 numbers에 끝에 도달 했으므로 idx가 끝을 가리킴
    if((idx == n-1) && (target == tmp1 || target == tmp2)){
        answer++;
    }
    
    else if(idx <= n-1){
        dfs(v, idx+1, tmp1, target);
        dfs(v, idx+1, tmp2, target);
    }
}
 
int solution(vector<int> numbers, int target) {
    n = numbers.size();
    dfs(numbers, 0, 0, target);
    
    return answer;
}