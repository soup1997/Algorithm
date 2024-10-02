#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> people;
    
    for (auto p: participant){
        people[p]++;
    }
    
    for (auto p: completion){
        people[p]--;
    }
    
    for(auto person: people){ // map을 for문으로 순회할때는 주소값을 받아온다(정확히는 Iterator)
        if (person.second != 0){
            return person.first;
        }
    }
}