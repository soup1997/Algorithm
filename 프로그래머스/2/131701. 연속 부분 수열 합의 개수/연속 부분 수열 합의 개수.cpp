#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int length = 1;
    vector<int> cases;
    
    while (length <= elements.size()) {
        for (int i = 0; i < elements.size(); i++) {
            int sum = 0;
            for (int j = i; j < i + length; j++) {
                sum += elements[j % elements.size()];
            }
            cases.push_back(sum);
        }
        length++;
    }
    
    set<int> s(cases.begin(), cases.end());
    return s.size();
}
