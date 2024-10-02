#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string str;
    int arr[26] = {0}; // 알바벳의 갯수

    cin >> str;

    for (auto i = 0; i < str.size(); i++) {
        str[i] = toupper(str[i]); // 대문자로 변환
        arr[str[i] - 'A']++; // A의 아스키 코드 65, a의 아스키 코드 97 
    }

    int max = 0; // 가장 많이 나온 문자 횟수
    int index = -1; // 해당 문자의 인덱스
    int max_count = 0; // 최대가 몇번 나왔는지 확인

    for (auto i = 0; i < 26; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
            max_count = 1;
        } else if (arr[i] == max) {
            max_count++;
        }
    }

    if (max_count > 1) {
        cout << "?\n";
    } else {
        cout << static_cast<char>(index + 'A') << '\n'; 
    }

    return 0;
}