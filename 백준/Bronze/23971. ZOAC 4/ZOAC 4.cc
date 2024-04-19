#include <iostream>
#include <cmath>

int main(){
    int H, W, N, M;
    std::cin >> H >> W >> N >> M;
    
    double row = ceil(H / (N + 1.0));
    double col = ceil(W / (M + 1.0));
    
    int cnt = static_cast<int>(row * col);
    
    std::cout << cnt << "\n";
    return 0;
}