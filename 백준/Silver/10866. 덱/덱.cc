#include <iostream>
#include <deque>
#include <string>

using namespace std;

void command(deque<int> &dq, string &str) {
    if (str == "push_back") {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    
    else if (str == "push_front") {
        int x;
        cin >> x;
        dq.push_front(x);
    }
    
    else if (str == "front") {
        if(!dq.empty()) cout << dq.front() << "\n";
        else cout << -1 << "\n";
    }
    
    else if (str == "back") {
        if(!dq.empty()) cout << dq.back() << "\n";
        else cout << -1 << "\n";
    }
    
    else if (str == "size") {
        cout << dq.size() << "\n";
    }
    
    else if (str == "empty") {
        cout << dq.empty() << "\n";
    }
    
    else if (str == "pop_front") {
        if(!dq.empty()) {
            cout << dq.front() << "\n";
            dq.pop_front();
        } 
        else cout << -1 << "\n";
    }
    
    else if (str == "pop_back") {
        if(!dq.empty()) {
            cout << dq.back() << "\n";
            dq.pop_back();
        } 
        else cout << -1 << "\n";
    }
    
    else;
}

int main(int argc, char** argv) {
    int N;
    deque<int> dq;
    cin >> N;
    
    for(auto i = 0; i < N; i++) {
        string str;
        cin >> str;
        command(dq, str);
    }
    
    return 0;
}