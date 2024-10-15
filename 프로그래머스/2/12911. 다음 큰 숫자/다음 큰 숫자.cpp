#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

bitset<20> convertToBinary(const int &n){ // n이 최대 1,000,000이므로 최대 20자리의 이진 수
    bitset<20> binary(n);
    return binary;
}


int solution(int n) {
    int answer = 0;
    bitset<20> n_bin = convertToBinary(n);
    int n_cnt = n_bin.count(); // 1의 갯수 세기

    for(int i = n+1; i <= 1000000; i++){
        bitset<20> i_bin = convertToBinary(i);
        int i_cnt = i_bin.count();
        
        if(n_cnt == i_cnt){
            answer = static_cast<int>(i_bin.to_ulong());
            break;
        }
    }
    
    return answer;
}