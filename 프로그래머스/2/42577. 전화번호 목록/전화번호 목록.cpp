#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    // 아스키 코드 값을 기준으로 정렬됨 
    // 첫 번째 문자가 동일할 경우, 두 번째 문자를 비교하여 ASCII 값이 작은 쪽이 앞에 위치합니다.
    // 정렬 전: {"119", "97674223", "1195524421"};
    // 정렬 후: {"119", "1195524421", "97674223"};
    
    sort(phone_book.begin(), phone_book.end());
        
    for(int i=0; i < phone_book.size()-1; i++){
        string prefix = phone_book[i];
        string check = phone_book[i+1].substr(0, prefix.length());
        
        if(check == prefix){
            return false;
        }      
    }
    return true;
}