#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecSlice(vector<int> inp, int a, int b) {
    return vector<int>(inp.begin() + a, inp.begin() + b);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i < commands.size(); i++){
        vector<int> new_arr = vecSlice(array, commands[i][0]-1, commands[i][1]); // a이상 b미만
        sort(new_arr.begin(), new_arr.end());
        
        int num = new_arr[commands[i][2]-1];
        answer.emplace_back(num);
    }
    return answer;
}