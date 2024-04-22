#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char** argv){
    while(true){
      int a, b, c;
      std::cin >> a >> b >> c;
      
      std::vector<int>lines = {a, b, c};
      std::sort(lines.begin(), lines.end());
      int max_line = lines[2];
 
      if(lines[0] == max_line && lines[1] == max_line && lines[0] == lines[1]){
          if(max_line != 0){
            std::cout << "Equilateral" <<"\n";  
          } 
          else {
              break;
          }
      }
      
      else if(max_line >= lines[0] + lines[1]){
          std::cout << "Invalid" << "\n";
      }
        
      else if(lines[0] != lines[1] && lines[0] != max_line && lines[1] != max_line){
          std::cout << "Scalene" << "\n";
      }
          
      else std::cout << "Isosceles" << "\n";
    }
    
    return 0;
}