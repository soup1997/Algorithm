#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {
        string a;
        getline(cin, a);
        
        stack<char> s;
        bool isValid = true;
        
        
        if(a == ".") break;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == '(' || a[i] == '[') {
                s.push(a[i]);
            }
            
            else if(a[i]==')') {
                if(s.empty() || s.top() != '(') {
                    isValid = false;
                    break;
                }
                s.pop();
            }
            
            else if(a[i]==']') {
                if(s.empty() || s.top() != '[') {
                    isValid = false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) isValid = false;
        if(isValid) cout << "yes\n";
        else cout << "no\n";
    }
}