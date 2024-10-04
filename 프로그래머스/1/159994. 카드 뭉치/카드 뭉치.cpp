#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    queue<string> c1;
    queue<string> c2;
    queue<string> g;
    
    for(int i= 0; i < cards1.size(); i++){
        c1.push(cards1[i]);
    }
    for(int j= 0; j < cards2.size(); j++){
        c2.push(cards2[j]);
    }
    for(int k = 0; k < goal.size(); k++){
        g.push(goal[k]);
    }
    
    for(int l = 0; l < goal.size(); l++){
        if(g.empty()){
            return "Yes";
        }
        
        else{
            if(!c1.empty() && g.front() == c1.front()){
                g.pop();
                c1.pop();
            }
        
            else if(!c2.empty() && g.front() == c2.front()){
                g.pop();
                c2.pop();
            }
        }
    }
    
    if(g.empty()){
        return "Yes";
    } else{
        return "No";
    }
}