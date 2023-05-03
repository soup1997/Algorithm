#include <iostream>
#include <string>

int main(int argc, char** argv){
    std::string str;
    std::cin >> str;
    
    for(auto i = 'a'; i <= 'z'; i++) {
        int cnt = 0;
        for(const auto alphabet: str) {
            if (i == alphabet) {
                cnt += 1;
            }
        }
        std::cout << cnt << ' ';
    }
}