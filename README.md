# Algorithm
### [바킹독의 실전 알고리즘](https://blog.encrypted.gg/category/%EA%B0%95%EC%A2%8C/%EC%8B%A4%EC%A0%84%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98?page=)
# 0x03 - 배열
![image](https://user-images.githubusercontent.com/86957779/235830792-23e96213-2212-46ab-b441-7ff6d06f4ab6.png)

메모리 상에 원소를 연속하게 배치한 자료구조

## 배열의 성질
1. O(1)에 k번째 원소를 확인/변경 가능
2. 추가적으로 소모되는 오버헤드가 거의 없음
3. Cache hit ratio가 높음(메모리 상에 데이터가 연속적으로 배치되어있으므로)
4. 메모리 상에 연속된 구간을 할당해야 하기 때문에 할당에 제약이 존재
5. 임의의 위치에 존재한 원소를 추가/제거 하는 동작은 O(N), 그 뒤의 원소들을 한칸 씩 밀거나 한칸 씩 당겨야 되기 때문

## Erase & Insert
```cpp
// c++
int main() {
 vector<int> vec = {1, 2, 3, 4};
 vector<int> vec(4); // {0, 0, 0, 0} 으로 초기화
 vector<int> vec(4, 1); // 크기 4짜리 {1, 1, 1, 1}로된 vector

 vec.insert(vec.begin() + index);
 vec.erase(vec.begin() + index);
}
```
```python
# python
if __name__ == '__main__':
 vec = [1, 2, 3, 4]
 vec.insert(index, 5);
 vec.remove(item)
 vec.pop(index)
```

## 연습 문제
**BOJ 10808: 알파벳 개수**
```cpp
// c++
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::string str;
    std::cin >> str;

    for (auto i = 'a'; i <= 'z'; i++) {
        int cnt = 0;
        for (const auto alphabet : str) {
            if (i == alphabet) {
                cnt += 1;
            }
        }
        std::cout << cnt << ' ';
    }
}
```
처음에는 std::string str = {'a', 'b', ...}와 같이 생각했으나 너무 비효율적,\
문자하나가 ascii 코드이므로 1씩 증가시키면서 입력받은 str의 문자 하나와 일치하면 카운트를 증가시키는 식으로 해결

```python
# python
string = input()
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

for i in alphabet:
    cnt = string.count(i)
    print(cnt, end=' ')
```

python에서 제공하는 count()함수가 직관적으로 바로 떠오름\
그걸 이용하기 위해서는 alphabet을 일일이 작성후 반복문을 돌리면서 해당 문자를 카운트 하는게 낫다는 판단 

# 0x05 - 스택
![image](https://user-images.githubusercontent.com/86957779/236835642-26ddedbe-1fa3-4947-a4aa-4a7cfc31028f.png)

Last In First Out (LIFO)

## 스택의 성질
1. 원소의 추가가 O(1)
2. 원소의 제거가 O(1)
3. 제일 상단의 원소 확인이 O(1)
4. 제일 상단이 아닌 나머지 원소들의 확인 및 변경이 원칙적으로 불가능

## STL Stack
```cpp
#include <iostream>
#include <stack>

using namespace std;
int main(void) {
 stack<int> s;
 s.push(10);
 s.push(20);
 s.push(30);
 cout << s.size() << endl; // 3
 
 if(s.empty()) cout << "stack is empty" << endl;
 else cout << "s is not empty" << endl;

 s.pop(); // 10, 20
 cout << s.top() << endl; // 20
 s.pop(); // 10
 cout << s.top << endl; // 10
 s.pop(); // empty

 cout << s.top() << endl; // Error 발생
}
```

## 연습문제
**BOJ 10828: 스택**
```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> s;

void command(string& str) {
    if (str == "pop") {
        if (!s.empty()) {
           cout << s.top() << endl;
           s.pop(); 
        }
        else cout << -1 << endl;
    }
    
    else if (str == "top") {
        if (!s.empty()) {
            cout << s.top() << endl;
        }
        else cout << -1 << endl;
    }
    
    else if (str == "empty") {
        if(s.empty()) cout << 1 << endl;
        else cout << 0 << endl;
    }
    
    else if (str == "size") {
        cout << s.size() << endl;
    }
    
    else if (str == "push") {
        int X;
        cin >> X;
        s.push(X);
    }
}

int main(int argc, char** argv) {
    int N;
    cin >> N;
    
    for(auto i = 0; i < N; i++) {
        string c;
        cin >> c;
        command(c);
    }
    
    return 0;
}
```
push X에서 공백까지 입력받는 `getline(cin, c)`으로 처음에 접근, 하지만 X를 또 형변환 한다는거 자체에서 코드가 너무 길어짐
`cin >>` 에서 공백전까지 입력 받고 다시 `cin >>` 호출이 훨씬 깔끔함.

```python
import sys
n = int(sys.stdin.readline())

stack=[]

for i in range(n):
    command = sys.stdin.readline().split()

    if command[0]=='push':
        x = int(command[1])
        stack.append(x)
        
    elif command[0]=='pop':
        if len(stack)!=0:
            print(stack.pop())
        else:
            print(-1)
            
    elif command[0] == 'size':
        print(len(stack))
        
    elif command[0] == 'empty':
        if len(stack)==0:
            print(1)
        else:
            print(0)
            
    elif command[0] == 'top':
        if len(stack)!=0:
            print(stack[-1])
        else:
            print(-1)
```
입력 받는 실행속도 `sys.stdin.readline()` >>>> `input()` 자주 활용하자!

# 0x06 - 큐
![image](https://github.com/AlgorithmChippo/Algorithm_Study/assets/86957779/fdfe678c-3f32-44b6-ad38-365546bc5ab5)

First In First Out (FIFO)

## 큐의 성질
1. 원소의 추가가 O(1)
2. 원소의 제거가 O(1)
3. 제일 앞(front)/뒤(rear)의 원소 확인이 O(1)
4. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능

## STL queue
```cpp
#include <iostream>
#include <queue>

int main(void) {
 queue<int> q;
 q.push(10); // 10
 q.push(20); // 10 20
 q.push(30); // 10 20 30
 cout << q.size() << endl; // 3
 
 if (q.empty()) cout << "Queue is empty" << endl;
 
 q.pop(); // 20 30
 cout << q.front() << endl; // 20
 cout << q.back() << endl; // 30
 q.push(40); // 20 30 40
 q.pop(); // 30 40
 cout << q.front() << endl; // 30
}
```

```python
# push: put(), pop: get()
# 사실 잘 안쓰이고 from collections import deque가 훨씬 많이 쓰임
from queue import Queue

q = Queue()
q.put(0) // 0
q.put(1) // 0 1 
q.put(2) // 0 1 2

q.get() // 1 2
q.qsize() // 2

print(q.empty())
```

## 연습문제
**BOJ 10845: 큐**
```cpp
#include <iostream>
#include <queue>
#include <string>

using namespace std;

template<typename T>
void command(queue<T> &q, string &str) {
    if (str == "push") {
        int x;
        cin >> x;
        q.push(x);
    }
    
    else if (str == "pop") {
        if(!q.empty()) {
            cout << q.front() << endl;
            q.pop();
        }
        
        else cout << -1 << endl;
    }
    
    else if (str == "size") {
        cout << q.size() << endl;
    }
    
    else if (str == "empty") {
        if(q.empty()) cout << 1 << endl;
        else cout << 0 << endl;
    }
    
    else if (str == "front") {
        if(!q.empty()) {
            cout << q.front() << endl;
        }
        else cout << -1 << endl;
    }
    
    else if (str == "back") {
        if(!q.empty()) {
            cout << q.back() << endl;
        }
        else cout << -1 << endl;
    }
    
    else;
}

int main(int argc, char** argv) {
    int N;
    queue<int> q;
    
    cin >> N;
    
    for(auto i = 0; i < N; i++) {
        string str;
        cin >> str;
        command<int>(q, str);
    }
    
    return 0;
}
```
```python
import sys

N = int(sys.stdin.readline())
q = []

for i in range(N) :
    command = sys.stdin.readline().split()

    if command[0] == 'push' : q.append(command[1])

    elif command[0] == 'pop' : 
        print(q.pop(0)) if len(q) != 0 else print(-1)

    elif command[0] == 'size' : print(len(q))

    elif command[0] == 'empty' :
        print(1) if len(q) == 0 else print(0)
            
    elif command[0] == 'front' :
        print(-1) if len(q) == 0 else print(q[0])
    
    elif command[0] == 'back' :
        print(-1) if len(q) == 0 else print(q[-1])
```
# 0x07 - 덱
![image](https://github.com/AlgorithmChippo/Algorithm_Study/assets/86957779/99416f8b-19c6-43d5-a96a-97d254b9c4e2)

양쪽 끝에서 삽입과 삭제가 전부 가능 (Double Ended Queue)

## 덱의 성질
1. 원소의 추가가 O(1)
2. 원소의 제거가 O(1)
3. 제일 앞/뒤의 원소 확인이 O(1)
4. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능

## STL deque
```cpp
#include <iostream>
#include <deque>

using namespace std;

int main(void) {
 deque<int> dq;
 dq.push_front(10); // 10
 dq.push_back(50); // 10 50
 dq.push_front(24); // 24 10 50

 for(auto x: dq) cout << x << ' '; // 24 10 50

 cout << dq.size() << endl; // 3
 cout << dq.empty() << endl; // False
 
 dq.pop_front(); // 10 50
 dq.pop_back(); // 10

 cout << dq.back() << endl; // 10
 dq.push_back(72); // 10 72
 cout << dq.pront() << endl; // 10
 
 dq[2] = 17; // 10 72 17
 
 dq.insert(dq.begin()+1, 33); // 10 33 72 17
 dq.erase(dq.begin() + 3); // 10 33 72
 dq.clear(); // clear
}
```

```python 
from collections import deque

dq = deque([1,2,3,4,5])
dq.append(6) # 1 2 3 4 5 6

dq.appendleft(0) # 0 1 2 3 4 5 6

dq.pop() # 6

dq.popleft() # 0

print(dq) # deque([1, 2, 3, 4, 5])

# 그 이외의 함수들
dq.extend(array) # dq의 끝에 array 추가
dq.extendleft(array) # dq의 왼쪽에 array 추가
dq.remove(item) # 해당 item을 q에서 찾아 삭제
dq.rotate(number) # 해당 숫자만큼 회전(양수: 시계방향, 음수: 반시계방향)
```

## 연습 문제
**BOJ 10866: 덱**
```cpp
#include <iostream>
#include <deque>
#include <string>

using namespace std;

void command(deque<int> &dq, const string &str) {
    if (str == "push_back") {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    
    else if (str == "push_front") {
        int x;
        cin >> x;
        dq.push_front(x);
    }
    
    else if (str == "front") {
        if(!dq.empty()) cout << dq.front() << "\n";
        else cout << -1 << "\n";
    }
    
    else if (str == "back") {
        if(!dq.empty()) cout << dq.back() << "\n";
        else cout << -1 << "\n";
    }
    
    else if (str == "size") {
        cout << dq.size() << "\n";
    }
    
    else if (str == "empty") {
        cout << dq.empty() << "\n";
    }
    
    else if (str == "pop_front") {
        if(!dq.empty()) {
            cout << dq.front() << "\n";
            dq.pop_front();
        } 
        else cout << -1 << "\n";
    }
    
    else if (str == "pop_back") {
        if(!dq.empty()) {
            cout << dq.back() << "\n";
            dq.pop_back();
        } 
        else cout << -1 << "\n";
    }
    
    else;
}

int main(int argc, char** argv) {
    int N;
    deque<int> dq;
    cin >> N;
    
    for(auto i = 0; i < N; i++) {
        string str;
        cin >> str;
        command(dq, str);
    }
    
    return 0;
}
```
# 0x08 - 스택 활용(수식의 괄호 쌍)
스택의 대표적인 활용 사례로 수식의 괄호 쌍이랑 전위/중위/후위 표기법, DFS, Flood Fill등이 있다.

## 수식의 괄호 쌍이란?
![image](https://github.com/soup1997/Algorithm/assets/86957779/6d7048ad-fd87-4ecd-9397-f1bcad57992e)

위의 그림과 같이 수식의 괄호 쌍이란, 주어진 괄호 문자열이 올바른지 판단하는 문제이다.
문자열을 앞에서부터 읽어나갈 때, 닫는 괄호는 남아있는 괄호 중에서 가장 최근에 들어온 여는 괄호와 짝을 지어 없애버리는 명령이라고 생각하면 된다.

## 문제 해결 방법
1. 여는 괄호가 나오면 스택에 추가
2. 닫는 괄호가 나왔을 경우
- 스택이 비어있으면 올바르지 않은 괄호 쌍
- 스택의 top이 짝이 맞지 않는 괄호일 경우 올바르지 않는 괄호 쌍
- 스택의 top이 짝이 맞는 괄호일 경우 pop
3. 모든 과정을 끝낸 후 스택에 괄호가 남아있으면 올바르지 않은 괄호 쌍, 남아있지 않으면 올바른 괄호 쌍

## 연습 문제
**BOJ 4949: 균형잡힌 세상**
```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char** argv){
    
    while(true){
        bool check = true;
        string input;
        stack<char> s;
        
        getline(cin, input); // 공백을 포함해 문자열 입력받기
        cin.clear() ; // 입력 버퍼 비우기
        
        if(input == ".") break;
        
        for(auto c: input){
            if(c == '[' || c == '('){
                s.push(c);
            }
            
            else if(c == ')'){
                if(!s.empty() && s.top() == '(') s.pop(); // stack이 empty일때 top()하면 RuntimeError 발생
                
                else {
                  check = false;
                  break;
                } 
            }
            
            else if(c == ']'){
                if(!s.empty() && s.top() == '[') s.pop();
               
                else {
                  check = false;
                  break;
                } 
            }
        }
        
        if(s.empty() && check) cout << "yes\n";
        else cout << "no\n";;
    }
    return 0;
}
```
```python
import sys

while True:
    s = []
    check = True
    string = sys.stdin.readline().rstrip() # sys.stdin.readline에는 자동적으로 "\n"을 추가시킴, rstrip()으로 개행문자제거
    
    if string == ".": break
    
    for c in string:
        if (c == '(') or (c == '['): s.append(c)
    
        elif (c == ')'):
            if (len(s)!= 0) and (s[-1] == '('): s.pop()
            
            else:
                check = False
                break
    
        elif (c == ']'):
            if (len(s)!= 0) and (s[-1] == '['): s.pop()
            
            else:
                check = False
                break
    
    if (len(s) == 0) and (check): print("yes")
    else: print("no")
```
# 0x09 - BFS (Breadth First Search)
다차원 배열에서 각 칸을 방문할 떄 너비를 우선으로 방문하는 알고리즘, queue를 사용하여 해결

## 예시
![image](https://github.com/soup1997/Algorithm/assets/86957779/06beebc6-432b-409f-ae7f-af7bf38dc7f7)

![image](https://github.com/soup1997/Algorithm/assets/86957779/810c8ba8-33c6-4f89-aed7-d21419f98714)

1. 시작하는 칸을 큐에 넣고 방문했다는 표시를 남김
2. 방문한 위치를 나타내는 큐의 원소를 꺼내어 그 칸에 상하좌우로 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 아무것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
4. 큐가 빌 때 까지 2번을 반복
모든 칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(N)

```cpp
#include <iostream>
#include <vector> // vector안의 utility 헤더 정의되어 있음

int board[502][502] = {...}; // 1이면 파란 칸, 0이면 빨간 칸
bool vis[502][502]; // 방문 여부를 저장할 변수

int n = 7, m = 10; // 7행 10열짜리 board

// dx, dy 열을 기준으로, 좌상우하
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char** argv) {
 queue<pair<int, int>> Q;
 vis[0][0] = 1; // 초기 시작 위치, 방문 표시
 Q.push({0, 0});
 
 while(!Q.empty()) { // Queue가 빌때까지 반복
  pair<int, int> curr = Q.front();
  Q.pop();
  cout << '(' << curr.first << "," << curr.second << ") -> ";
  for(int dir = 0; dir < 4; dir++) {
   int nx = curr.first + dx[dir];
   int ny = curr.second + dy[dir];
   if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위제한
   if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문했거나 또는 파란칸이 아니라면 pass
   vis[nx][ny] = 1; // 방문 표시
   Q.push({nx, ny}); // 방문했으므로 queue에 삽입
  }
 }
}
```

## 연습 문제
1. **BOJ 1926: 그림**

![image](https://github.com/soup1997/Algorithm/assets/86957779/e4dffc0e-0cf9-4b9a-9b0b-24aeebeec020)

1. 상하좌우로 연결된 그림의 크기를 알아내기, fload fill
2. 도화지에 있는 모든 그림을 찾아내기, 총 4개의 그림 존재(이중 for문을 돌면서 BFS의 시작점이 될 수 있는 곳을 찾아야함)
```cpp
#include <iostream>
#include <queue>
#include <utility> // pair
#include <algorithm> // max

using namespace std;

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char** argv) {
    int n, m;
    int max_size = 0, num = 0;
    cin >> n >> m;
    queue<pair<int, int>> Q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1 && vis[i][j] == 0){
                int size = 0;
                queue<pair<int, int>> Q;
                
                vis[i][j] = 1; // 시작점 방문 표시
                Q.push(make_pair(i, j)); // 시작점 큐에 삽입, bfs 시작
                       
                while(!Q.empty()){
                    pair<int, int> curr = Q.front();
                    Q.pop();
                    size++;
                    
                    for(int dir = 0; dir < 4; dir++){
                        int nx = curr.first + dx[dir];
                        int ny = curr.second + dy[dir];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push(make_pair(nx, ny));
                    }
                }
                max_size = max(max_size, size);
                num++;
            }
        }
    }
    cout << num << "\n" << max_size;
    return 0;
}
```
2. **BOJ 1926: 미로탐색**

![image](https://github.com/soup1997/Algorithm/assets/86957779/c5a85eee-9c59-4c55-8955-22ec8eb584cd)

BFS를 이용한 다차원 배열에서의 거리 측정 문제, 거리 저장을 위한 배열 
```cpp
#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

char board[100][100];
bool visit[100][100];
int dist[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char** argv){
    int N, M;
    queue<pair<int, int>> Q;
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++){
            board[i][j] = str[j];
        }
    }
    
    dist[0][0] = 0; // origin point
    visit[0][0] = 1;
    Q.push(make_pair(0, 0));
    
    while(!Q.empty()){
        pair<int, int> curr = Q.front();
        Q.pop();
        
        for(int dir = 0; dir < 4; dir++){
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visit[nx][ny] || board[nx][ny] == '0') continue;
            visit[nx][ny] = 1;
            dist[nx][ny] = dist[curr.first][curr.second] + 1;        
            Q.push(make_pair(nx, ny));
        }
    }
    cout << dist[N-1][M-1] + 1;
    return 0;
}
```
# 0x0A - DFS

# 0x0B - 재귀

# 0x0C - 백트래킹

# 0x0D - 시뮬레이션

# 0x0E - 정렬 I

# 0x0F - 정렬 II

# 0x10 - DP(Dynamic Programming)

# 0x11 - Greedy
