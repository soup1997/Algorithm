#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> reward;
    int explode = 0;
    
    for(int j = 0; j < moves.size(); j++){
        for(int i = 0; i < board.size(); i++){
            if(board[i][moves[j]-1] != 0){
                if(!reward.empty() && reward.top() == board[i][moves[j]-1]){ // 스택의 탑이랑 같은지 확인
                    reward.pop(); // 같은 모양 폭발
                    explode += 2;
                }
                else{ // 스택이 비어있고 top이랑 같지 않다면 바로 스택에 추가
                    reward.push(board[i][moves[j]-1]);
                }
                
                board[i][moves[j]-1] = 0; // 비어있다는 표시로 0으로 바꿈
                break; // 인형을 하나 꺼냈으면 그 열에서 더 이상 찾지 않음
            }
        }
    }
    return explode;
}