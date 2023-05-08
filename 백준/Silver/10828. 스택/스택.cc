#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> s;

void command(string& str) {
    if (str == "pop") {
        if (!s.empty()) {
           cout << s.top() << endl;
           s.pop(); 
        }
        else cout << -1 << endl;
    }
    
    else if (str == "top") {
        if (!s.empty()) {
            cout << s.top() << endl;
        }
        else cout << -1 << endl;
    }
    
    else if (str == "empty") {
        if(s.empty()) cout << 1 << endl;
        else cout << 0 << endl;
    }
    
    else if (str == "size") {
        cout << s.size() << endl;
    }
    
    else if (str == "push") {
        int X;
        cin >> X;
        s.push(X);
    }
}

int main(int argc, char** argv) {
    int N;
    cin >> N;
    
    for(auto i = 0; i < N; i++) {
        string c;
        cin >> c;
        command(c);
    }
    
    return 0;
}