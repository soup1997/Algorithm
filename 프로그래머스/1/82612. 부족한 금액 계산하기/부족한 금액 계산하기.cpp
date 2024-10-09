using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    int cnt = 1;
    
    while(cnt <= count){
        long long newPrice = price * cnt;
        answer += newPrice;
        cnt++;
    }
    
    if(answer > static_cast<long long>(money)){
        return answer - static_cast<long long>(money);
    }
    
    else{
        return 0;
    }
}