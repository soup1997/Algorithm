#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> s;
    vector<int> ans;
    
    for(int a: arr){
        if (s.empty()){
            s.push(a);
            ans.push_back(a);
        }
        
        else if(s.top() != a){
            s.push(a);
            ans.push_back(a);
        }
    }
    return ans;
}