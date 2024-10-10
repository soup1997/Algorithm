#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Function to slice the vector (optional, not strictly needed)
vector<char> slice(const vector<char> &vec, int a) {
    return vector<char>(vec.end() - a, vec.end());
}

int main(int argc, char** argv) {
    string in, bomb;
    cin >> in >> bomb;
    
    vector<char> stack;
    
    for(char c: in) {
        stack.push_back(c);
        if (stack.size() >= bomb.length()) {
            bool flag = true;
            for (int i = 0; i < bomb.length(); i++) {
                if (stack[i + stack.size() - bomb.length()] != bomb[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (int i = 0; i < bomb.length(); i++) {
                    stack.pop_back();
                }
            }
        }
    }
    
    if (stack.empty()) {
        cout << "FRULA\n";
    } else {
        string tmp(stack.begin(), stack.end()); // 복사를 간편하게 할 수 있다, 기억해 놓을 것
        cout << tmp << "\n";
    }
    
    return 0;
}