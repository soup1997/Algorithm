#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
    int n;
    cin >> n;
    
    if (n % 2 == 0){
        cout << "CY\n";
    }
    
    else{
        cout << "SK\n";
    }
    return 0;
}