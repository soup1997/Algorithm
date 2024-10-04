#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    if(accumulate(d.begin(), d.end(), 0) == budget){
        return d.size();
    }
    else{
        sort(d.begin(), d.end()); // 오름차순 정렬
        int cnt = 0;
        
        for(int i=0; i<d.size(); i++){
            budget -= d[i];
            
            if(budget >= 0){
                cnt++;
            }
            else break;
        }
        return cnt;
    }
}