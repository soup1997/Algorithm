#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {  
    priority_queue<int> pq; // 디폴드는 최대 힙!!!
    
    for(int s: scoville){
        pq.push(-s); // 가장 작은 값이 가장 큰 값이 되도록 변경
    }
    
    int cnt = 0;
        
    while (-pq.top() < K){
        if (pq.size() < 2){
            return -1;
        }
        
        int min1 = -pq.top(); pq.pop();
        int min2 = -pq.top(); pq.pop();
        int n = -(min1 + (min2 * 2));
        pq.push(n);
        cnt++;
    }
        
    return cnt;
    }