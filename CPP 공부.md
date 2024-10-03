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

`map: pair<const Key, T>` 로 이루어진 컨테이너. Key값 기준으로 sorting 되어있음. 이진탐색트리로 구현되면서 sorting하므로 unordered_map보다 value값을 찾는 데에 오래걸릴 수 있음, `#include <map>`에 포함

`unordered_map`: map과는 달리 Key 혹은 Value 기준으로 sorting 되어있지 않은 컨테이너. Key값으로 hash value를 찾는 데에 시간이 적게 걸림.(Average: O(1)) 우리가 흔히 사용하는 hash 자료구조에 해당된다고 보면 됨, `#include <unordered_map>`에 포함


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
    priority_queue<int> pq; // 힙 생성 (디폴트는 최대 힙!!!, 파이썬과 다름!!!)
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

# 실전문제 [백준, 프로그래스, 코드트리]

## Hash

### 폰켓몬 - 프로그래머스
```cpp
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    if (nums.size() == 1){
        return 1;
    }
    
    else{
        int targetNum = nums.size() / 2;
        
        map<int, int> bag;
        for(auto n: nums){
            bag[n]++;  // Simply increment the count of each number
        }
        
        int monsterType = bag.size(); // 몬스터 종류갯수
        
        if(monsterType > targetNum){ // 몬스터 종류 갯수가 더 많으면 N/2 가져가면 된다.
            return targetNum;
        }
        
        else{ // 아니라면 몬스터 종류만큼 가져가면 된다.
            return monsterType;
        }
    }
}
```

> Hash를 이용해서 중복을 처리하는 기법을 외워놓자

> 어찌보면 이 문제는 해시에 속하긴 하지만 그리디에 가까운 문제라고 생각한다.
> 문제를 푸는 전략 자체가, 총 몬스터의 갯수 N/2 만큼 가져가야 하므로

> 1. 몬스터의 종류가 N/2보다 많다면 몬스터의 종류만큼 가져가면 된다.
> 2. 몬스터의 종류가 N/2보다 적다면 N/2만큼 가져간다.

---

### 완주하지 못한 선수 - 프로그래머스

```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> people;
    
    for (auto p: participant){
        people[p]++;
    }
    
    for (auto p: completion){
        people[p]--;
    }
    
    for(auto person: people){ // map을 for문으로 순회할때는 pair<const Key, T>, auto의 장점
        if (person.second != 0){
            return person.first;
        }
    }
}
```

> map에 대한 사용법을 좀더 확실하게 알 수 있는 문제 였다.

> 풀이 자체는 직관적으로 떠올라서 분석내용은 딱히 없다.

---

### 전화번호 목록 - 프로그래머스

```cpp
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    for(int i=0; i < phone_book.size()-1; i++){
        string prefix = phone_book[i];
        for(int j=i+1; j < phone_book.size(); j++){
            string check = phone_book[j].substr(0, prefix.length());
            if(check == prefix){
                return false;
            }  
        }
    }
    return true;
}
```

> 처음에 풀었던 방식, 정확성: 70.8, 반례를 찾자

```cpp
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
```

> 반례를 찾기보다 문자열이 정렬될때의 정확한 기준을 알고 있으면 쉽게 풀 수 있는 문제이다

> 주석에 적어놓았듯이 prefix가 동일한 경우 ascii가 작은 순서대로 정렬된다, 그렇다면 반복문 한번에 확인할 수 있다는 것을 명심할 것!

> substr(0, index)의 사용법도 배울 수 있었다.

---

### 의상- 프로그래머스

```cpp
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int num = 0, ans = 1; // 총 가짓 수, 정답
    unordered_map<string, vector<string>> um;
    
    for (const auto &c: clothes){ // &는 reference(참조자, 복사가 이루어지지 않음)
        string clothing_item = c[0];
        string clothing_type = c[1];     
        um[clothing_type].push_back(clothing_item);
        num++;
    }
    
    int answer = 1;
    for (const auto& value : um) {
        answer *= (value.second.size() + 1); // +1을 하는 이유는 각 카테고리에서 아이템을 착용하거나 아무것도 착용하지 않는 선택을 할 수 있기 때문
    }
    
    return answer-1;        
}
```

> 전형적인 패턴을 찾아서 조합을 구하는 문제, `size()+1`은 공집합 포함

> n = size() + 1, r = 1이라 할때 각 카테고리 당 nCr로 가능한 조합을 모두 곱한다

> size()+1에 공집합이 포함되어있으므로 -1을 뺴서 모두 공집합인 경우의 수를 제외한다.

## 스택/큐

### 같은 숫자는 싫어 - 프로그래머스
```cpp
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> s;
    vector<int> ans;
    
    for(int a: arr){
        if (s.empty()){
            s.push(a);
            ans.push_back(a);
        }
        
        else if(s.top() != a){
            s.push(a);
            ans.push_back(a);
        }
    }
    return ans;
}
```

> 중복제거 때문에 맨처음에 map을 떠올렸다가 순서를 기억해야 하므로 스택이 더 적합하다는 사실을 깨달음

---

### 기능개발 - 프로그래머스 
```cpp
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    for(int i=0; i < speeds.size(); i++){
        double rest = 100.0 - static_cast<double>(progresses[i]);
        int finish = static_cast<int>(ceil(rest / static_cast<double>(speeds[i])));
        q.push(finish);
    }
    
    while(!q.empty()){
        int top = q.front(); q.pop();
        int cnt = 1;
        
        while(!q.empty() && top >= q.front()){
            q.pop();
            cnt += 1;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
```

### 올바른 괄호 - 프로그래머스
```cpp
#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{   
    if(s[0] == ')') return false; // 바로 리턴
    
    bool answer = true;
    stack<char> check;
    
    for(char c: s){
        if(c == '('){
            check.push(c);
        }
        
        else{
            if(!check.empty() && c == ')' && check.top() == '('){
                check.pop();
            }
        }
    }
    
    if(check.empty()){
        return true;
    } else{
        return false;
    }
}
```

> top 확인할 떄 비어있으면 segmentation falut 발생함, empty()인지 먼저 체크할 것

### 주식가격 - 프로그래머스
```cpp
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer;

    for(int i=0; i < prices.size(); i++){
        int cnt = 0;       
        for(int j=i+1; j < prices.size(); j++){
            cnt++;
            if(prices[i] > prices[j]) break;
        }
        answer.emplace_back(cnt);
    }
    
    return answer;
}
```

> prices의 최대 길이 100,000 이면 이중 반복문 돌리면 큰일 날법한데 중간에 break 들어가고 j가 N-1만큼 돌아서 시간초과 발생 X

## Heap


### 더 맵게 - 프로그래머스

```cpp
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {  
    priority_queue<int> pq; // 디폴드는 최대 힙!!!
    
    for(int s: scoville){
        pq.push(-s); // 가장 작은 값이 가장 큰 값이 되도록 변경
    }
    
    int cnt = 0;
        
    while (-pq.top() < K){
        if (pq.size() < 2){
            return -1;
        }
        
        int min1 = -pq.top(); pq.pop();
        int min2 = -pq.top(); pq.pop();
        int n = -(min1 + (min2 * 2));
        pq.push(n);
        cnt++;
    }
        
    return cnt;
    }
```

> Heap의 정확한 사용법을 배울 수 있었던 문제, push(), pop()할때 python과 달리 값을 반환하지 않는다!!


## 정렬

### K번쨰 수 - 프로그래머스
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecSlice(vector<int> inp, int a, int b) { // vector slicing 함수
    return vector<int>(inp.begin() + a, inp.begin() + b);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i < commands.size(); i++){
        vector<int> new_arr = vecSlice(array, commands[i][0]-1, commands[i][1]); // a이상 b미만
        sort(new_arr.begin(), new_arr.end());
        
        int num = new_arr[commands[i][2]-1];
        answer.emplace_back(num);
    }
    return answer;
}
```

> vector slicing 하는법을 정확히 알아놓자

> index 접근하는 법도 명확하게 알아 놓아야 함, b미만임을 명심

---

### 가장 큰 수 - 프로그래머스

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    string sa = to_string(a); // 숫자를 문자열로 변환
    string sb = to_string(b); // 숫자를 문자열로 변환
    
    string n1 = sa + sb; // 문자열 합치기
    string n2 = sb + sa; // 문자열 합치기
    
    
    int num1 = stoi(n1);
    int num2 = stoi(n2);
    
    return num1 > num2;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    
    string answer = "";
    
    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    
    if (answer[0] == '0') {
        return "0";
    }
    
    else{
        return answer;
    }
}
```

> 이미 풀이법을 외워버린 문제, 맨앞에 "0"이 왔다는 것은 입력이 {0, 0, 0, 0} 이라는 의미이므로 바로 "0"을 리턴한다.

---

### H-index - 프로그래머스

```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int h_idx = 0;
    int n  = citations.size();
    
    while (true) {
        int cnt = 0;
        for(auto c: citations){
            if(c >= h_idx){
                cnt++;
            }
        }
        if(cnt >= h_idx && n-cnt <= h_idx){
            h_idx++;
        }
        else{
            break;
        }
    }
    return h_idx-1;
}
```
> 굳이 정렬을 쓰지 않아도 풀 수 있는문제, 마지막에 h_idx-1을 하는 이유는 조건맞으면 h_idx++해주기 때문에 마지막에는 -1을 뺴주는 게 올바른 구현

```cpp
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<>()); // 오름차순 정렬

    if (!citations[0]) return 0; // 제일 많은 인용횟수가 0이면 볼 필요도 없음

    for(int i=0; i<citations.size(); i++){ // {6, 5, 3, 1, 0}
        if(citations[i] >= i+1){ // i+1이 h_index
            answer = i+1;
        }  
    }
    return answer;
}
```
> 다른 풀이는 i 값을 토대로 순차적으로 풀었다. 이렇게 하면 오름차순 정렬이 필수적이긴 하겠다.

## 완전탐색

## 그리디

### 돌 게임 - 백준

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

## DFS/BFS

## 구현

### ZOAC 4  - 백준

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
### 삼각형과 세변 - 백준

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

### 단어공부 - 백준

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

### 디지털 티비 - 백준

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

### 대피소

N이 얼마 안되므로 완전탐색 돌려도 무방하다는 것을 눈치 채야함.


```cpp
```

> 내껄로 다시 만들자!

---

### 집합 - 백준

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


###  줄세우기 - 백준

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