#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    if (p.length() == t.length()){
        if(stol(t) <= stol(p)){
            return 1;
        }
        return 0;
    }
    
    for(int i = 0; i <= t.length() - p.length(); i++){
        string seg = t.substr(i, p.length());
        if(stol(seg)<= stol(p)){
            answer++;
        }
    }
    return answer;
}