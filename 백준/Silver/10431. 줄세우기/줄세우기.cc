#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int p;
    cin >> p;
    
    for(int k=0; k<p; k++){
        int c;
        cin >> c;
        
        int cnt = 0;
        vector<int> students(20);
        for(int i = 0; i < 20; i++){
            cin >> students[i]; // 학생 입력 받기
        }
        
        for(int i = 0; i < 19; i++){
            for(int j = i + 1; j < 20; j++){
                if(students[i] > students[j] && i != j){ // i가 더 크면
                    auto tmp = students[i];
                    students[i] = students[j]; // 큰 학생 뒤로 보내기
                    students[j] = tmp; // 작은 학생 앞으로 보내기
                    cnt ++;
                }
            }
        }
        cout << c << ' ' << cnt << "\n";
    }
    return 0;
}