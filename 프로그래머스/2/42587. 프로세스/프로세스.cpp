#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    priority_queue<int> pq; // 우선순위 대로 정렬되서 들어감 (최대 Heap) 
    queue<pair<int, int>> q; // {인덱스, 우선순위} 를 저장할 큐 선언
    
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]}); 
        pq.push(priorities[i]);
    }
    
    int cnt = 1;
    
    while(!q.empty()){
        pair<int, int> tmp = q.front(); // 현재 queue의 top
        q.pop(); // pop 실행
        
        if(tmp.second != pq.top()){ // 현재 top의 우선순위가 pq와 같은 우선순위가 아니라면
            q.push(tmp); // 다시 뒤에 push
        }
        
        else{ // 현재 top의 우선순위가 pq와 같은 우선순위를 가진다면
            if(tmp.first == location){ // 같은 우선순위를 가지고 top의 인덱스가 location값과 같다면
                return cnt; // 찾으려는 정답
            }
            cnt++; 
            pq.pop();
        }
    }
    
    return 0;
}