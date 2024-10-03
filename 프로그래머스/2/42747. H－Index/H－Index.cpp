#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    
    int h_idx = 0;
    int n  = citations.size();
    
    while (true) {
        int cnt = 0;
        for(auto c: citations){
            if(c >= h_idx){
                cnt++;
            }
        }
        if(cnt >= h_idx && n-cnt <= h_idx){
            h_idx++;
            cout << cnt << " " << h_idx << endl;
        }
        else{
            break;
        }
    }
    return h_idx-1;
}