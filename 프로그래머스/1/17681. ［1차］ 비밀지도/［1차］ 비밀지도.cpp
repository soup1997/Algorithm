#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<string, string> convBin(int num1, int num2, int n) {
    string s1 = "";
    string s2 = "";

    while (num1 != 0) {
        s1 = to_string(num1 % 2) + s1;
        num1 /= 2;
    }

    while (num2 != 0) {
        s2 = to_string(num2 % 2) + s2;
        num2 /= 2;
    }

    while (s1.length() < n) {
        s1 = "0" + s1;
    }
    
    while (s2.length() < n) {
        s2 = "0" + s2;
    }
    return {s1, s2};
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> grid(n); // 지도를 만들 공간 생성
    
    for(int i = 0; i < n; i++){
        int a = arr1[i];
        int b = arr2[i];
        pair<string, string>res = convBin(a, b, n);
        
        string row = "";
        for(int j = 0; j < n; j++){
            if (res.first[j] == '1' || res.second[j] == '1'){
                row += '#';
            }
            else row += ' ';
        }
        grid[i] = row;
    }
    return grid;
}