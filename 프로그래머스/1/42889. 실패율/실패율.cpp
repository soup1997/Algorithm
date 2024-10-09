#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    unordered_map<int, pair<int, int>> board;
    
    for(int i = 1; i <= N; i++){
        board[i] = {0, 0};
    }
    
    for(auto s: stages){
        if(board.find(s) != board.end()){
            board[s].first += 1;
        }
        
        for(int i = 1; i <= N; i++){
            if(board.find(i) != board.end()){
            board[i].second += 1;
            }
        }
    
    
        
    }
    
    vector<int> answer;
    return answer;
}