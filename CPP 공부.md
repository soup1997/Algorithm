# C++ 코딩테스트 때 자주 사용하는 STL 및 알고리즘 정리

## 1. std::vector

가장 많이 사용하는 벡터 자료형

```cpp
#include <vector>
using namespace std;

int main(){
    vector<int> v;

    auto iter = find(v.begin(), v.end(), 178); // 178의 반복자 찾기
    auto idx = find(v.begin(), v.end(), 178) - v.begin() // 178의 인덱스 찾기
    
    v.insert(v.begin(), 100) // 100을 제일 처음에 추가
    v.insert(v.begin()+5, 5) // 5를 (처음주소 + 5)에 추가
    v.insert(v.end(), 9) // 9를 제일 마지막에 추가

    v.erase(v.begin()); // 제일 첫번째 원소 제거
    v.erase(v.end()-1); // 마지막에서 한 칸 앞에 원소 제거
    return 0;
}
```

## 2. std::map

cpp의 딕셔너리와 동일

```cpp
#include <map>

using namespace std;

int main(){
    map<string, int> m;
    m["12345678"] = 1234; // 삽입, 문자열 "12345678"에 저장된 값은 정수형 1234

    auto iter = m.find("12345678")
    if (um.find("bigbigpark") != um.end() ) // 찾지 못한다면 end()를 반환

    auto key = iter->first; // key에 접근한다, 문자열 "12345678" 반환
    auto value = iter->second; // value에 접근한다, 정수형 1234 반환

    m.erase("12345678") // 없으면 m.end()를 반환한다

    // vector의 경우 아래와 같이 반복문을 순회하며 값에 접근이 가능하다.

    vector<int> v = {1, 2, 3, 4, 5};
    for(auto n: v) // n으로 원소가 넘어옴
    {
        cout << n << endl;
    }

    // map의 경우 어떨까?
    map<string, int> um;
    um["A"] = 1111;
    um["B"] = 2222;

    for(auto it: um) // it으로 주소값이 넘어옴
    {
        // key-value의 특성에 따라 접근하면 된다.
        cout << "key  : " << it->first << endl; // 문자열 A, B 출력
        cout << "value: " << it->second << endl; // 정수형 1111, 2222 출력
    }

    return 0;
}
```

## 3. std::string

문자열에 필수적인 라이브러리

```cpp
#include <string>
#include <algorithm>

int main(){
    string s = "bigbigpark";

    if (s.find("big") != std::string::npos) // 찾았을때 반환값은 해당 인덱스
    s.replace(pos, length, "big") // pos 위치에서 length 길이만큼 "big"으로 채운다
    s.erase(pos, len) // pos에서 len길이 만큼 삭제한다
    s.erase(s.begin()+len) // len 길이 만큼 삭제한다
    s.erase(remove(s.begin(), s.end(), 'A'), s.end()) // 문자열 s에서 'A'가 들어간 부분을 모조리 지운다
    
    string new_string = s.substr(5); // 5번 인덱스부터 끝까지 가져오기
    string new_string = s.substr(5, 1); // 5번 인덱스부터 1길이 만큼 가져오기

    string str = "bigbigpark";
    char c = str[0];

    int num = 5;
    string str = to_string(num);
    string n_str = "1122";
    int n1 = stoi(n_str); // string에서 int 변환
    double n2 = stod(n_str); // string에서 double 변환

    char ch = '9';
    int n = ch - '0'; // '0'를 빼게 되면 보이는 그대로 숫자가 저장되게 된다.
}
```

## 4. std::sort

모든 코딩테스트에서 거의 필수적인 정렬 알고리즘 사용법

```cpp
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int i, int j){
    return i < j; // true면 j가 앞으로, 아니라면 i가 앞으로
}

int main(){
    vector<int> v = {4, 2, 3, 5, 1};

    sort(v.begin(), v.end()); // 오름차순 정렬
    sort(v.begin(), v.end(), compare) // 내림차순 정렬

    return 0;
}
```
## 4. std::stack

```cpp
#include <stack>

using namespace std;

int main(int argc, char** argv){
    stack<int> st;
    s.push(10); // 스택에 10추가
    cout << s.size(); // 1 출력

    if (s.empty()) // empty면 true
    s.pop(); // top에 있는 값 뽑기 (10을 반환하지 않음)
    s.top(); // top에 있는 값 확인
}
```

## 5. std::queue

```cpp
#include <queue>

using namespace std;

int main(int argc, char** argv){
    queue<int> q;
    q.push(10); // 10추가
    cout << q.size(); // 1 출력
    q.pop(); // 가장 먼저들어온 10 뽑기 (10을 반환하지 않음)
    q.front(); // 가장 앞에 있는 값 확인
    q.back(); // 가장 뒤에 있는 값 확인
}
```

```cpp
#include <queue>

using namespace std;

int main(int argc, char** argv){
    priority_queue<int> pq; // 힙 생성 (디폴트는 최소 힙)
    pq.push(10); // 10추가
    pq.pop(); // 루트 값 뽑기
    pq.top(); // 루트 값 출력
}
```

## 6. std::deque

```cpp
#include <deque>

using namespace std;

int main(int argc, char** argv){
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
    cout << dq.front() << endl; // 10
    
    dq[2] = 17; // 10 72 17
    
    dq.insert(dq.begin()+1, 33); // 10 33 72 17
    dq.erase(dq.begin() + 3); // 10 33 72
    dq.clear(); // clear
}
```


# [프로그래머스](https://school.programmers.co.kr/learn/challenges?tab=algorithm_practice_kit)

## Hash

## 스택/큐

## Heap

## 정렬

## 완전탐색

## 그리디

## DFS/BFS

# [백준](https://www.acmicpc.net/workbook/view/8708)

## Bronze

### 23971 - ZOAC 4 
`수학, 사칙연산`

이 문제에서 얻은 것은 문제를 깊게 고민하고 그다음에 풀이를 시작하자, 시간 급하다고 마구잡이로 하면 시간초과 뜬다!
```cpp
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    double H, W, N, M;
    
    cin >> H >> W >> N >> M;
    
    double row = ceil(H / (N + 1.0));
    double col = ceil(W / (M + 1.0));
    
    int cnt = static_cast<int>(row * col);
    
    cout << cnt << "\n";
    
    return 0;
}
```
> 1행에 앉을 수 있는 사람수를 구하고, 1열에 앉을 수 있는 사람 수를 구해서 곱하면 전체 앉을 수 있는 사람의 수 이다. 따라서 이중 반복문 돌릴 필요없이 규칙만 찾으면 해결되는 문제

---
### 5073 - 삼각형과 세변
`수학, 구현, 기하학`

총 4개의 조건을 판별해야 한다. 따라서 큰 대분류로 먼저 묶고 난 다음에 세부 분류로 하는 것이 좋은 코드 작성 방법이다!
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
    while (true) {
        int n;
        vector<int> vec;
        
        for(int i = 0; i < 3; i++){
            cin >> n;
            vec.push_back(n);
        }
        
        sort(vec.begin(), vec.end());
        
        if(vec[2] == 0 && vec[1] == 0 && vec[0] == 0){ 
            break;
        }
        
        if (vec[2] >= vec[1] + vec[0]) {
            cout << "Invalid\n";
        } 
        else {
            if (vec[0] == vec[1] && vec[1] == vec[2]) {
                cout << "Equilateral\n";
            } 
            else if (vec[0] == vec[1] || vec[1] == vec[2] || vec[0] == vec[2]) {
                cout << "Isosceles\n";
            } 
            else {
                cout << "Scalene\n";
            }
        }
    }
    return 0;
}

```

> sort 알고리즘 사용하려면 `#include <algorithm>` 필수임 

---

### 1157 - 단어공부
`구현, 문자열`

```cpp
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
```

> 감이 안잡혀서 조금 참고한 문제, 알파벳의 갯수는 26개이다.

> `toupper`함수는 대문자로 변환하는 함수이다.

> `arr[str[i] - 'A']++;` 이문제의 핵심

---

### 2816 - 디지털 티비
`구현, 해 찾기`
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 1번과 4번만 이용해서 풀이

using namespace std;

int main(int argc, char** argv){
    int n;
    
    vector<string> channels;
    vector<char> commands;
    
    cin >> n;
    
    for(int i=0; i < n; i++){
        string channel;
        cin >> channel;
        channels.push_back(channel);
    }
    
    int idx1 = find(channels.begin(), channels.end(), "KBS1") - channels.begin();
    int idx2 = find(channels.begin(), channels.end(), "KBS2") - channels.begin();
    
    if (idx1 > idx2){
        idx2++;
    }
    
    for(int i=0; i < idx1; i++){
        commands.push_back('1');
    }
    
    for(int j= idx1; j > 0; j--){
        commands.push_back('4');
    }
    
    for(int i=0; i < idx2; i++){
        commands.push_back('1');
    }
    
    for(int j=idx2; j > 1; j--){
        commands.push_back('4');
    }
    
    for (char c : commands) {
        cout << c;
    }
    return 0;
}
```

> 입력하나에 여러개의 해가 존재할 수 있는 문제이다. 따라서 1번, 4번 버튼만 이용하도록 제한하고 푸는 문제, 제약 조건에 방법의 길이는 500보다 작아야한다.

> 채널이 최대 100개면, KBS1, KBS2가 리스트에 마지막에 연속적으로 있다고 해도 400언저리이다. 따라서 1번, 4번만 이용

## Silver

### 28125 - 대피소

N이 얼마 안되므로 완전탐색 돌려도 무방하다는 것을 눈치 채야함.


```cpp
```

> 내껄로 다시 만들자!

---

### 11723 - 집합
`구현, 비트마스킹`

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M;
    cin >> M;
    
    vector<int> set;
    vector<int> all = {1, 2, 3, 4, 5, 
                       6, 7, 8, 9, 10, 
                       11, 12, 13, 14, 15, 
                       16, 17, 18, 19, 20};
    
    for(int i = 0; i < M; i++) {
        string command; 
        cin >> command;
        
        vector<int>::iterator iter; // 중요!
        
        if (command == "add" || command == "remove" || command == "check" || command == "toggle") {
            int elem;
            cin >> elem;
            iter = find(set.begin(), set.end(), elem);
        }
        
        if (command == "add") {
            if (iter == set.end()) {
                set.push_back(elem);
            }
        }
        
        else if (command == "remove") {
            if (iter != set.end()) {
                set.erase(iter);
            }
        }
        
        else if (command == "check") {
            if (iter != set.end()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        
        else if (command == "toggle") {
            if (iter == set.end()) {
                set.push_back(elem);
            } 
            else {
                set.erase(iter);
            }
        }
        
        else if (command == "all") {
            set = all;
        }
        
        else if (command == "empty") {
            set.clear();
        }
    }
    return 0;
}
```

> 맨처음에 toggle 발생할 때 마다 for문 돌리는 방식으로 작성했는데, 매우 비효율적이라고 판단되어 미리 [1, ..., 20] 까지 리스트를 생성하고 이를 복사하는 방식으로 변경했다.

---

### 9655 -  돌 게임
`DP, 수학, 게임이론`

코드 자체가 너무 단순해서 놀랐던 문제, 다이나믹 프로그래밍이 무엇인지 조금 더 알 수 있는 문제 였다고 생각한다. 
이러한 유형의 문제를 풀기 위해서는 결국 패턴을 파악해야 한다.

주어진 돌의 갯수가 홀수일 경우 항상 상근이가 이기고 짝수일 경우 항상 창영이가 이긴다라는 패턴을 찾아야함!

```cpp
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
```

---

### 10431 - 줄세우기
`구현, 정렬, 시뮬레이션`

정렬 문제를 처음 접하다 보니 어떻게 풀어야할지 감이 안잡혔던 문제, 정렬 방식 중 가장 구현이 간단한 Bubble Sort 방식으로 풀면 되는 문제다
```cpp
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
                if(students[i] > students[j] && i != j){ // 앞에 있는 학생이 더 크면
                    auto tmp = students[i];
                    students[i] = students[j]; // 뒤에 있는 학생을 앞으로 보내고
                    students[j] = tmp; // 앞에 있는 학생을 뒤로 보냄
                    cnt ++;
                }
            }
        }
        cout << c << ' ' << cnt << "\n";
    }
    return 0;
}
```

> 버블정렬

---

### 8979 - 올림픽
`구현, 정렬`

```cpp

```
> cpp의 sort 함수에서 key까지는 알았는데 reverse에 대한 사용법도 알게 되었다. 특히 정렬 후에 동일한 우선순위를 가진다면 입력이 먼저온 순서대로 정렬된다는 것을 명심하자

> medals[idx][1:] == medals[i][1:] 이 코드가 좀 의심이 가서 GPT에게 물어보았다. 리스트의 주소값을 비교한다고 생각했는데 각 원소가 완전히 동일한지 비교 가능하다는 것이다! 앞으로 자주 써먹자

---

### 7568 - 덩치
`구현, 브루트포스`

N이 최대 50 밖에 안되므로 브루트포스임을 눈치채야 한다. ranking을 1로 초기화 하고 자기 자신보다 덩치가 큰 사람이 있을 떄만 ranking에 1을 더해주는 방식으로 구현!

```cpp
import sys

n = int(sys.stdin.readline())
data = [list(map(int, sys.stdin.readline().split()))for _ in range(n)]

for i in range(len(data)):
    ranking = 1
    for j in range(len(data)):
        if data[i][0] < data[j][0] and data[i][1] < data[j][1]:
            ranking += 1
    print(ranking, end=' ')
```
### 4659 - 비밀번호 발음하기
`문자열, 구현`

카운트 변수를 어떻게 적절하게 써야 하는지 알 수 있었던 문제, 특히 지금까지 푼 문제들 경험 상 연속적으로 같은 문자가 나오는지 확인하는 문제가 굉장히 많았다. 이 때 while문 돌릴 필요 없이 cnt 변수 적절히 초기화 +1 해주면 된다!
```cpp
import sys

def condition(string):
    moeum = ['a', 'e', 'i', 'o', 'u']
    
    # 조건 1: 모음 하나를 반드시 포함하여야 한다.
    moeum_cnt = 0
    
    for m in moeum:
        if m in string:
            moeum_cnt += 1
    
    if moeum_cnt == 0:
        return f'<{string}> is not acceptable.'
    
    # 조건 2: 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
    moeum_cnt = 0
    jaeum_cnt = 0
    for s in string: # 조건 2
        if s in moeum:
            moeum_cnt += 1
            jaeum_cnt = 0
        
        else:
            jaeum_cnt += 1
            moeum_cnt = 0
            
        if moeum_cnt >= 3 or jaeum_cnt >= 3:
            return f'<{string}> is not acceptable.'
        
    # 조건 3: 같은 글자가 연속적으로 두번 오면 안되나, ee와 oo는 허용한다.
    sequence_cnt = 1
    sequence_init = string[0]
    
    for i in range(1, len(string)):
        if string[i] != sequence_init:
            sequence_init = string[i]
            sequence_cnt = 1
        
        else:
            sequence_cnt += 1
        
        if sequence_cnt == 2:
            if sequence_init == 'e' or sequence_init == 'o':
                sequence_cnt = 1
            else:
                return f'<{string}> is not acceptable.'
    
    # 조건 1, 2, 3 모두 안겹친 경우 acceptable
    return f'<{string}> is acceptable.'   

while True:
    string = sys.stdin.readline().strip()
    
    if string == "end":
        break
        
    print(condition(string))
```

---

### 25757 - 임스와 함께하는 미니게임
`자료 구조, 문자열, 해시`

```cpp
# 임스와 여러 번 미니게임을 플레이 하고자 하는 사람이 있으나, 
# 임스는 한 번 같이 플레이한 사람과는 다시 플레이하지 않습니다.

import sys

n, game = sys.stdin.readline().split()
mini_game = {"Y": 2, "F": 3, "O": 4}
players = [] # 중복 확인용
cnt = 0

for _ in range(int(n)):
    player = sys.stdin.readline().strip()
    
    if player not in players:
        players.append(player)
        
    if len(players) % mini_game[game] == 0:
        cnt += 1
        
print(cnt)
```
> 시간 초과 코드, 중복을 확인하기 위해 in을 사용하다 보니 이 부분이 시간초과를 발생시킨다. 중복 검사를 어떻게 해야 효율적일까?

```cpp
# 임스와 여러 번 미니게임을 플레이하고자 하는 사람이 있으나, 
# 임스는 한 번 같이 플레이한 사람과는 다시 플레이하지 않습니다.

import sys

n, game = sys.stdin.readline().split()
mini_game = {"Y": 2-1, "F": 3-1, "O": 4-1} # 임스를 포함해야 하므로 1씩 빼기
players = [sys.stdin.readline().strip() for _ in range(int(n))]
players = set(players)

answer = len(players) // mini_game[game]
print(answer)
```
> 가장 먼저 임스를 포함해야 하므로 -1씩 빼주는 것을 누락했다 이 부분을 추가

> 사람이 입장할때마다 리스트에 추가하고 조건을 검사할 필요가 없다. 한번에 입력을 다 받은 다음에 set으로 중복제거를 하고, 각 게임에 필요한 인원 수 만큼 나누어주면 바로 해결된다!

---

### 20125 - 쿠키의 신체 측정
`구현`
```cpp
import sys

n = int(sys.stdin.readline())
cookie = [list(sys.stdin.readline().strip()) for _ in range(n)] # 문자열이라서 통째로 입력받음, split 불가

def find_heart():
    heart_pos = [1, 1]
    for i in range(n):
        for j in range(n):
            if cookie[i][j].count("*") == 1: # cookie[i]가 하나의 문자열이므로 [j]까지 접근해야함
                heart_pos[0] = i + 1 + 1 # 머리는 심장 바로 윗 칸에 1칸 크기로 있다.
                heart_pos[1] = cookie[i].index("*") + 1 # 심장의 열 위치 찾음
                print(*heart_pos)       
                heart_pos[0] -= 1
                heart_pos[1] -= 1
            
                return heart_pos

h_pos = find_heart()
left_arm = cookie[h_pos[0]][:h_pos[1]].count("*")
right_arm = cookie[h_pos[0]][h_pos[1]+1:].count("*")
waist, left_leg, right_leg = 0, 0, 0

for i in range(h_pos[0]+1, n):
    if cookie[i][h_pos[1]] == "*":
        waist += 1
    
    else:
        if cookie[i][h_pos[1]-1] == "*":
            left_leg += 1
    
        if cookie[i][h_pos[1]+1] == "*":
            right_leg += 1

print(left_arm, right_arm, waist, left_leg, right_leg)
```
> 전형적인 구현 문제면서 거지같은 문제였다. 입력이 문자열로 통째로 들어와서 split이 안먹힘, 그래서 cookie[i]가 문자열 하나가 통째로 들어와서 cookie[i][j]까지 해야 각 요소에 접근이 가능하다.

---


### 1205 - 등수 구하기
`구현`

```cpp
import sys

# N >= 0, 리스트에 있는 점수의 갯수
# 10 <= P <= 50, 랭킹에 올라갈 수 있는 점수의 갯수
n, taesu, p = map(int, sys.stdin.readline().split())

scores = list(map(int, sys.stdin.readline().split()))
scores = scores[:]

ranking = 1

if n == 0:
    print(ranking)

else:
    if n >= p and min(scores) >= taesu:
        print(-1)
    
    else:
        for score in scores:
            if score > taesu:
                ranking += 1
         
        print(ranking)
```
> 입력이 많고, 조건이 까다로운 문제, 문제만 잘읽으면 구현 자체는 너무나 쉽다!

---

### 1244 - 스위치 켜고 끄기
`구현, 시뮬레이션`

```cpp
import sys 
import math

def change_state(x):
    return 0 if x == 1 else 1

switch_num = int(sys.stdin.readline())  # 스위치의 갯수 (positive integer <= 100)
switch = list(map(int, sys.stdin.readline().split()))  # 스위치 상태 (1 for on, 0 for off)

student_num = int(sys.stdin.readline())  # 학생 수 (positive integer <= 100)
earned_switch = [list(map(int, sys.stdin.readline().split())) for _ in range(student_num)]

for s, c in earned_switch:
    if s == 1:  # 남자라면
        switch_index = switch_num // c
        switch_index = [coefficient * c for coefficient in range(1, switch_index + 1)]
        
        for si in switch_index:
            si -= 1
            switch[si] = change_state(switch[si])
    
    else:  # 여자라면
        c -= 1
        index = 0
        
        while (c-index >= 0 and c+index < len(switch) and switch[c+index] == switch[c-index]):
            switch[c + index] = change_state(switch[c + index])
            switch[c - index] = change_state(switch[c - index])
            index += 1
        
        switch[c] = change_state(switch[c]) # 인덱스가 0부터 시작하므로 자기 자신을 한번 더 바꿔야 함

for i in range(switch_num):
    print(switch[i], end=" ")
    if (i + 1) % 20 == 0: # 20개 이상 출력시 줄 바꿈
        print()
```
> 왜 정답률이 20% 언저리인지 알겠다. 출력이 거지 같다, 구현자체는 쉬웠음

---

### 9017 - 크로스 컨트리
`구현`

전형적인 구현인데 dictionary도 sorted() 할 수 있다는 것을 알아야 하는 문제

```cpp
import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    teams = list(map(int, sys.stdin.readline().split())) # 팀 번호를 나타내는 n개의 정수
    notQualified = []
    
    # 자격없는 팀 걸러내기
    for i in set(teams):
        if teams.count(i) < 6: # 6명 미만이므로 자격 X
            notQualified.append(i)
    
    # 차집합 이용, 자격있는 팀만 board 생성
    team_list = list(set(teams) - set(notQualified))
    board = {team:[0, 0, 0] for team in team_list} # 자격이 있는 팀 [총점, 카운트 변수, 5번째 선수의 점수]
    
    # 자격있는 팀만 board 업데이트
    score = 1
    for j in teams:
        if j not in notQualified:
            board[j][1] += 1 # 5번째 선수 카운트를 위한 카운팅 변수
            
            if board[j][1] <= 4:
                board[j][0] += score 
            
            if board[j][1] == 5: # 5번째 선수라면
                board[j][2] = score
            
            score += 1
     
    board = sorted(board, key=lambda x:(board[x][0], board[x][2])) # 반환 값은 key를 기준으로 sorting 된 key값!
    print(board[0])
```
> 구현문제인데도 불구하고 꽤 많은 것을 배울 수 있었던 문제, 특히나 딕셔너리의 sorted() 이용을 알 수 있었다.

> 딕셔너리를 sorted(dict) 할 경우 딕셔너리의 value에 따라 sorting되는 것을 확인 할 수 있음, 반환 값은 key를 기준으로 sorting 된 key값!

> 항상 dictionary는 키 값을 이용해야만 접근 할 수 있다는 사실을 잊지말자

---

### 17266 - 어두운 굴다리
`구현, 이분탐색`

1시간 고민해도 안풀려서 유튜브 참고해서 푼 문제
```cpp
import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
lights = list(map(int, sys.stdin.readline().split()))

# 실패 케이스를 생각해보자
# 1. lights[0] - h > 0 --> 실패
# 2. lights[-1] + h < n --> 실패
# 3. lights[i]+h < light[i+1]-h --> 실패

for h in range(1, n+1):
    flag = True
    # 맨 왼쪽 가로등
    if lights[0] - h > 0:
        flag = False
    
    elif lights[-1] + h < n:
        flag = False
    
    else:
        for i in range(m-1):
            if lights[i] + h < lights[i+1] - h:
                flag = False
                break
         
    if flag:
        print(h)
        break
```

> 케이스 1, 2까지는 생각했다. 케이스 3를 생각못한 문제

> 이분탐색 기법으로 어떻게 푸는지 한번 참고해서 완벽히 이해하자!
---

### 2164 - 카드2
`자료구조, 큐`

누가봐도 덱 써서 푸는 문제
```cpp
import sys
from collections import deque

# 회전하는 큐 문제
n = int(sys.stdin.readline())
cards = deque([i for i in range(1, n+1)])

while len(cards) > 2:
    cards.popleft()
    cards.append(cards.popleft())

print(cards[-1])
```

> 전형적인 자료구조를 활용하는 문제, 쉽다!

---

### 11047 - 동전 0
`그리디`

코드트리에서 풀어본 문제, 동전이 서로 배수 관계에 있으므로 가장 높은 금액부터 쓰면 된다.

```cpp
# 동전을 적절히 사용해서 그 가치의 합을 K
# 이때 필요한 동전 개수의 최솟값을 구하는 프로그램

import sys

n, k = map(int, sys.stdin.readline().split())
coins = [int(sys.stdin.readline()) for _ in range(n)] # 동전의 가치 Ai가 오름차순, 배수 관계

cnt = 0

for i in range(len(coins)-1, -1, -1):
    if k == 0:
        break
        
    cnt += k // coins[i]
    k %= coins[i]

print(cnt)
```

> 동전이 배수관계가 아니라면 적용 불가능한 풀이방법

---

### 1931 - 회의실 배정
`그리디, 정렬`

코드트리에서 풀어본 문제, 회의가 빨리 끝나는 순서대로 오름차순 정렬하면 최대한 많은 회의를 진행할 수 있다

```cpp
import sys

n = int(sys.stdin.readline())
meetings = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

# 회의가 빨리 끝나는 순서대로 정렬, 끝나는 시간이 같으면 시작하는 순서대로 정렬
meetings.sort(key=lambda x: (x[1], x[0]))

cnt = 1 # 최소 1개의 회의는 진행할 수 있으므로 1로 초기화

curr_meeting = meetings[0]

for i in range(1, len(meetings)):
    next_meeting = meetings[i]
    
    if curr_meeting[1] <= next_meeting[0]:
        cnt += 1
        curr_meeting = next_meeting
        
print(cnt)
```

> 조건이 맞을때만 비교해야 할 현재 미팅을 바꿔준다

> 정렬 시 만약 끝나는 시간이 동일하다면, 회의 시작 시간이 빠른 순서대로 정렬하는 것이 맞다!

---

### 2217 - 로프
`그리디, 수학, 정렬`

```cpp
import sys

# k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 
# 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.

n = int(sys.stdin.readline()) # 로프의 갯수
weight = [int(sys.stdin.readline()) for _ in range(n)] # 각 로프가 버틸 수 있는 최대 중량

if n == 1:
    print(weight[0])

else:
    weight.sort()
    idx = 0

    minWeight = weight[idx]
    maxWeight = weight[-1]
    ans = maxWeight
    
    for k in range(n, 1, -1): # 사용할 로프의 갯수
        if maxWeight <= minWeight * k:
            if idx == n-1:
                break
            
            else:
                ans = max(maxWeight, minWeight * k)
                idx += 1
                minWeight = weight[idx] # next min

                if idx == n-1:
                    break

    print(ans)
```
> 초기 접근방법, minimum 값을 순차적으로 옮겨주면 되지 않을까? 

> 그리디 풀때는 항상 테스트 케이스 몇개 나열하고 규칙을 찾아가면 된다

```cpp
import sys
n = int(sys.stdin.readline())
weight = [int(sys.stdin.readline()) for _ in range(n)] # 각 로프가 버틸 수 있는 최대 중량

weight.sort(reverse=True) # 내림차순 정렬
ans = max(weight)
for i in range(n):
    ans = max(ans, (weight[i] * (i+1)))

print(ans)
```

> 참고한 답, 먼저 최대 무게를 weight의 max값으로 초기화 한다.

> 모든 로프를 사용할 필요가 없으므로, weight를 순회하면서 weight[i]* i를 해준다!

최종적으로 수정한 답은 아래와 같다.

```cpp
import sys

# k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 
# 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.

n = int(sys.stdin.readline()) # 로프의 갯수
weight = [int(sys.stdin.readline()) for _ in range(n)] # 각 로프가 버틸 수 있는 최대 중량

if n == 1:
    print(weight[0])

else:
    weight.sort()
    maxWeight = weight[-1]
    
    for k in range(n, 0, -1): # 사용할 로프의 갯수
        minWeight = weight[n-k]
        maxWeight = max(maxWeight, minWeight * k)

    print(maxWeight)
```

---

### 1026 - 보물
`그리디, 수학, 정렬`

B가 재배열하면 안된다고 하지만, 배열해도 뭔상관임? B를 내림차순으로 정렬하자

```cpp
import sys

# S = A[0] × B[0] + ... + A[N-1] × B[N-1] 를 작게하는 최소 값
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

# 전략: B의 max와 A의 min이 곱해지면 된다

A_new = sorted(A) # 오름차순 정렬 
B_new = sorted(B, reverse=True) # 내림차순 정렬
total = sum([A_new[i]*B_new[i] for i in range(n)])

print(total)
```

> A의 최소와 B의 최대가 서로 곱해지면 되는 단순한 문제!

---

### 13305 - 주유소
`그리디`

한번에 안풀려서 참고한 문제, 전반적인 생각 방법은 거의 동일했다.

```cpp
import sys

n = int(sys.stdin.readline()) # 도시의 갯수
length = list(map(int, sys.stdin.readline().split())) # 도로의 길이
price = list(map(int, sys.stdin.readline().split())) # 주유소의 가격

minPrice = price[0]
cost = price[0] * length[0] # 처음에 기름 무조건 넣어야 함

# 가격을 최소화 하기 위해, 가장 싼 곳에서 가장 많이 구해야 한다. 따라서 가격의 최솟값을 찾아야 한다.
# 가장 싼곳에서 가야할 길이 만큼 기름을 구매한다.
for i in range(1, n-1):
    minPrice = min(minPrice, price[i])
    cost += minPrice * length[i]
    
print(cost)
```

> 주석에 써놓은 대로 가격을 최소화 하기 위해 가장 싼 곳에서 가장 많이 구매해야 한다.

> 초반에는 index를 2개를 놓고 while문으로 접근했으나 세상에 어느 문제가 while문을 두개씩이나 쓰면서 접근하겠나

> (다음 주유소와도 비교했을 때) 현재 주유소 가격이 최소라면 거리 값을 그대로 곱해서 비용에 더한다라는게 이 문제를 푸는 방식 

---

### 20920 - 영단어 암기는 외로워
`문자열, 정렬, 해시`

cpp의 강력한 sorted()를 이용하면 되는 문제
```cpp
# 우선순위
# 1.자주 나오는 단어일수록 앞에 배치한다.
# 2.해당 단어의 길이가 길수록 앞에 배치한다.
# 3.알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다 (이건 건드릴 수가 없음)
import sys

n, m = map(int, sys.stdin.readline().split()) # 단어의 갯수, 외울 단어의 길이 기준
dictionary = {}

for _ in range(n):
    word = sys.stdin.readline().strip()
    if len(word) >= m: # 길이가 m 이상이어야 함
        if word not in dictionary:  # 'None' 체크 대신 'in' 사용
            dictionary[word] = 0
        
        else:
            dictionary[word] += 1

# 가장 많이 나오는 단어가 가장 앞에 배치됨 (제일 작은 -값)
# 단어가 길수록 앞에 배치됨 (제일 작은 -값)
# 알파벳 사전 순으로 정렬됨
dictionary = sorted(dictionary, key=lambda x: (-dictionary[x], -len(x), x))
print(*dictionary, sep="\n")
```

> if word not in dictionary의 존재를 알 수 있었다. 꽤 어려웠던 문제!

> sorted 부분이 문제였는데 우선순위 1, 2는 내가 정할 수 있어도 우선순위 3은 건들수가 없었다. 생각해본 결과 우선순위 1, 2에 -값을 주면 원하는대로 정렬이 나온다는 것을 깨달아야 했던 문제

> 정렬 문제는 이제 좀 감을 잡은 것 같다

---

### 2512 - 예산

### 21921 - 블로그

### 1515 - 수 이어 쓰기
`구현, 그리디, 문자열, 브루트포스`

```cpp
import sys

series = list(sys.stdin.readline().rstrip())
s_dict = {i: series.count(i) for i in set(series)}
num = 1

while True:
    s_num = str(num)
    
    for s in s_num:
        if s in s_dict:
            s_dict[s] -= 1
    
    if sum(s_dict.values()) == 0:
        print(num)
        break

    else:
        num += 1
```

> 시간초과 코드, 나도 안다 num이 최대 3000자리의 숫자이므로 시간초과 뜨는게 당연함

> 무엇보다도 이 코드가 틀린건 s_dict로 바꾸면서 입력받은 수열을 고려하지 않는다는 점

> N=20이고 입력이 234092일때, 12에서 s_dict={'2':0}이 되버림

```cpp
import sys

series = list(sys.stdin.readline().rstrip())

idx = 0
num = 1

while True:
    s_num = str(num)
    for s in s_num:
        if series[idx] == s:
            idx += 1
    
            if idx == len(series):
                print(num)
                exit()

    num += 1
```
> for 문 돈다음에 조건 맞으면 while 문까지 나가야함, exit()로 코드 종료 시켜버리기

### 19941 - 햄버거 분배

### 17484 - 진우의 달 여행

### 2607 - 비슷한 단어

### 3758 - KCPC

### 20310 - 타노스

### 19637 - IF문좀 대신 써줘

### 22233 - 가희와 키워드
`자료 구조, 문자열, 해시`

중복된 키워드가 있으면 n에서 얼마를 뺼 것인가를 결정하는 문제
```cpp
import sys
n, m = map(int, sys.stdin.readline().split())
note = {sys.stdin.readline().rstrip(): 1 for _ in range(n)}

for _ in range(m):
    keywords = sys.stdin.readline().rstrip().split(",")
    
    for k in keywords:
        if k in note:
            note[k] -= 1
            
            if not note[k] < 0:
                n -= 1
    print(n)
```

> 일단 키워드가 무조건 한번씩 등장하므로 hash 이용해서 노트를 구성

> 중복되는 키워드에 대해서 이미 1이 빼진 경우 n에서 카운트 빼는 것을 수행하지 않는다!


---

### 1927 - 최소 힙
`자료 구조, 우선순위 큐`

단순하게 힙 써서 푸는 문제
```cpp
import sys
import heapq

n = int(sys.stdin.readline())
hq = []

for _ in range(n):
    num = int(sys.stdin.readline())
    
    if num == 0:
        if len(hq) != 0:
            print(heapq.heappop(hq))
        else:
            print(0)
    
    else:
        heapq.heappush(hq, num)
```

> heapq.heapify()는 이미 완성된 리스트에만 적용할 수 있다라는 걸 명심하자

> heapq 처음에 선언할 때 리스트로 선언하고 풀면 된다!

---

### 20006 - 랭킹전 대기열
`구현, 시뮬레이션`

대기자가 있는 방을 어떻게 관리할 것이냐가 이 문제의 핵심이다

```cpp
import sys

p, m = map(int, sys.stdin.readline().split())
rooms = []

for i in range(p):
    level, name = sys.stdin.readline().split()
    level = int(level)

    if i == 0:
        rooms.append([]) # 방 생성
        rooms[-1].append([level, name]) # 유저 추가
        
    else:
        flag = False
        
        for j in range(len(rooms)):
            if (level >= (rooms[j][0][0]-10) and level <= (rooms[j][0][0]+10)) and len(rooms[j]) < m:
                    rooms[j].append([level, name])
                    flag = True
                    break
            
        if not flag: # 유저가 방에 추가되지 못함
            rooms.append([]) # 방 생성
            rooms[-1].append([level, name]) # 유저 추가

for r in range(len(rooms)):
    rooms[r].sort(key=lambda x : x[1])
    print("Started!" if len(rooms[r]) == m else "Waiting!")

    for level, name in rooms[r]:
        print(level, name)
```

> 가장 먼저 시도한 방식은 rooms 리스트를 만들때 `[[]] * (p//m)` 으로 진행

> `1<=m<=p` 라는 조건이 없으므로 일단 rooms list를 그냥 `[]`으로 두는게 맞다

> 오랜만에 flag를 사용해서 해결한 문제이다

---

### 11501 - 주식
`그리디`

### 1406 - 에디터

### 2304 - 창고 다각형

### 2075 - N번째 큰 수

### 1138 - 한 줄로 서기

---

### 1260 - DFS와 BFS
`DFS, BFS`

복습만이 살길이다. DFS/BFS 복습하자!

```cpp
import sys
from collections import deque
sys.setrecursionlimit(10000)

n, m, v = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]

# 양방향 그래프
for _ in range(m):
    start, end = map(int, sys.stdin.readline().split())
    graph[start].append(end)
    graph[end].append(start)

# 정점 번호가 작은 것부터 방문
for i in range(1, n+1):
    graph[i].sort()

def dfs(x):
    visited[x] = True # 현재 기준 정점 방문 처리
    print(x, end=" ")
    
    for currV in graph[x]:
        if not visited[currV]: # 방문되지 않았다면
            dfs(currV) # currV와 연결된 다른 정점들 탐색

def bfs(x):
    q = deque([x])
    visited[x] = True
    print(x, end=" ")
    
    while q:
        currV = q.popleft()
        for i in graph[currV]: # currV와 연결된 다른 정점들 탐색
            if not visited[i]:
                visited[i] = True # 방문 처리
                print(i, end=" ")
                q.append(i)

# DFS
visited = [False for _ in range(n+1)]
dfs(v)
print()

# BFS
visited = [False for _ in range(n+1)]
bfs(v)
```
> 오랜만에 푸니까 기억이 안나네, 양방향 그래프를 만들 때 grid형식보다 연결리스트 방식이 공간복잡도가 훨씬 적다는 것을 명심하자!

---

### 14940 - 쉬운 최단거리

### 20922 - 겹치는 건 싫어

### 1446 - 지름길

### 17615 - 볼 모으기

### 2531 - 회전 초밥

### 1522 - 문자열 교환

## Gold

### 15989 1, 2, 3 더하기 4

### 13549 - 숨바꼭질 3

### 12919 - A와 B 2

### 20055 - 컨베이어 벨트 위의 로봇

### 20437 - 문자열 게임 2

### 2493 - 탑

### 14719 - 빗물

### 5972 - 택배 배송

### 2467 - 용액

### 7682 - 틱택토

### 2668 - 숫자고르기

### 22251 - 빌런 호석

### 7490 - 0 만들기
