#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> series; // 수열 미리 만들어 놓기
vector<int> combs; // 경우의 수를 담아놓을 벡터

void makeComb(){
    if(combs.size() == m){
        for(auto c: combs){
            cout << c << " "; // 경우의 수 출력하기
        }
        cout << "\n";
    }
    else{
        for(auto s: series){
            if(combs.size() == 0 || find(combs.begin(), combs.end(), s) == combs.end()){
                combs.push_back(s);
                makeComb();
                combs.pop_back();
            }
        }
    }
}

int main(int argc, char** argv){
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        series.push_back(i);
    }
    makeComb();
    
    return 0;
}