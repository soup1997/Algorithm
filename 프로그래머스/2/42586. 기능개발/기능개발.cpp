#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    for(int i=0; i < speeds.size(); i++){
        double rest = 100.0 - static_cast<double>(progresses[i]);
        int finish = static_cast<int>(ceil(rest / static_cast<double>(speeds[i])));
        q.push(finish);
    }
    
    while(!q.empty()){
        int top = q.front(); q.pop();
        int cnt = 1;
        
        while(!q.empty() && top >= q.front()){
            q.pop();
            cnt += 1;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}