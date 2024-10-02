#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 1번과 4번만 이용해서 풀이

using namespace std;

int main(int argc, char** argv){
    int n;
    
    vector<string> channels;
    vector<char> commands;
    
    cin >> n;
    
    for(int i=0; i < n; i++){
        string channel;
        cin >> channel;
        channels.push_back(channel);
    }
    
    int idx1 = find(channels.begin(), channels.end(), "KBS1") - channels.begin();
    int idx2 = find(channels.begin(), channels.end(), "KBS2") - channels.begin();
    
    if (idx1 > idx2){
        idx2++;
    }
    
    for(int i=0; i < idx1; i++){
        commands.push_back('1');
    }
    
    for(int j= idx1; j > 0; j--){
        commands.push_back('4');
    }
    
    for(int i=0; i < idx2; i++){
        commands.push_back('1');
    }
    
    for(int j=idx2; j > 1; j--){
        commands.push_back('4');
    }
    
    for (char c : commands) {
        cout << c;
    }
    return 0;
}