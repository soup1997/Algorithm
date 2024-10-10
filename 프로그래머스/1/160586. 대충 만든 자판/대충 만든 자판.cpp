#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> um;
    
    for(string k: keymap){
        for(int i=0; i < k.length(); i++){
            if(um.find(k[i]) == um.end()){
                um[k[i]] = i+1;
            }
            else{
                um[k[i]] = min(i+1, um[k[i]]);
            }
        }
    }
    
    for(string t: targets){
        int cnt = 0;
        for(char c: t){
            if(um.find(c) != um.end()){
                cnt += um[c];
            } else{
                cnt = -1;
                break;
            }
        }
        answer.emplace_back(cnt);
    }
    return answer;
}