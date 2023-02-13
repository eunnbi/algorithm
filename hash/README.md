# Hash

> 해시는 키에 대응되는 값을 저장하는 자료구조이다. 이떼 해시함수가 쓰이는데, 해시함수는 임믜 길이의 값을 고정된 길이의 키로 대용시키는 함수이다.

## Collision

좋은 해시 함수는 테이블에 값들이 균일하게 분포되도록 한다, 하지만, 다른 값들이 같은 키로 대응되는 충돌이 발생할 수 있다. 충돌을 회피하는 방법으로 `Chaining`과 `Open addressing`이 있다.

## Chaining

해시 테이블의 버킷마다 연결리스트를 두고 요소가 추가될 때 해당하는 버킷의 연결리스트에 값을 추가한다.

## Open addressing

- 값을 추가할 때, 빈 버킷이 나올 때까지 해시 함수를 적용하고 빈 버킷이 나오면 해당 버컷에 값을 추가한다. -값을 찾을 때도 빈 버킷이 나올 때까지 해시 함수를 적용한다. 그 과정에서 만약 값을 찾았다면 성공, 값을 못 찾고 빈 버컷이 나왔다면 실패이다.

### Linear probing

```
 h(k, i) - (h'(k) + i) mod m (h'(k) = k mod m)
```

- 충돌이 발생하면 오른쪽 방향으로 다음 버킷을 확인한다. (마지막 버킷에서 충돌이 발생했다면 첫번째 버킷을 확인한다.)
- 구현이 간단하고, cache hit rate가 높다.
- clustering (특정 영역에 많은 값들이 모여 있는 것) 이 발생해 값을 찾는 데 평균 시간이 증가한다.

### Quadratic Probing

```
 h(k, i) - (h'(k) + i * i) mod m (h'(k) = k mod m)
```

- Linear probing과 비슷하지만, 충돌이 발생하면 다음 버킷이 아니라 오른쪽으로 1, 3, 5... 칸 씩 이동하여 버킷을 확인하다.
- Cache hit rate가 나쁘지 않다.
- Linear probing에 비해 clustering을 어느 정도 피할 수 있지만, 처음 해시 값이 동일하다면 계속 똑같은 경로로 버킷을 확인하기 때문에 여전히 clustering이 발생한다.

### Double Hashing

```
h(k, i) = (h1(k) + h2(k) * i) mod m
```

- 충돌 발싱 시 이동할 칸의 수를 새로운 해시함수로 계산하는 방식이다. 또 다른 해시 함수를 사용해서 rehashing이라고도 한다.
- `h2(k)` 값이 `m`과 소수여야 값들이 해시 테이블에 균일하게 분포될 수 있다.
- cache hit rate가 낮지만, clustering을 피할 수 있다.

# STL

```cpp
#include <bits/stdc++.h>
using namespace std;

void unordered_set_example(){
  unordered_set<int> s;
  s.insert(-10); s.insert(100); s.insert(15); // {-10, 100, 15}
  s.insert(-10); // {-10, 100, 15}
  cout << s.erase(100) << '\n'; // {-10, 15}, 1
  cout << s.erase(20) << '\n'; // {-10, 15}, 0
  if(s.find(15) != s.end()) cout << "15 in s\n";
  else cout << "15 not in s\n";
  cout << s.size() << '\n'; // 2
  cout << s.count(50) << '\n'; // 0
  for(auto e : s) cout << e << ' ';
  cout << '\n';
}

void unordered_multiset_example(){
  unordered_multiset<int> ms;
  ms.insert(-10); ms.insert(100); ms.insert(15); // {-10, 100, 15}
  ms.insert(-10); ms.insert(15);// {-10, -10, 100, 15, 15}
  cout << ms.size() << '\n'; // 5
  for(auto e : ms) cout << e << ' ';
  cout << '\n';
  cout << ms.erase(15) << '\n'; // {-10, -10, 100}, 2
  ms.erase(ms.find(-10)); // {-10, 100}
  ms.insert(100); // {-10, 100, 100}
  cout << ms.count(100) << '\n'; // 2
}

void unordered_map_example(){
  unordered_map<string, int> m;
  m["hi"] = 123;
  m["bkd"] = 1000;
  m["gogo"] = 165; // ("hi", 123), ("bkd", 1000), ("gogo", 165)
  cout << m.size() << '\n'; // 3
  m["hi"] = -7;  // ("hi", -7), ("bkd", 1000), ("gogo", 165)
  if(m.find("hi") != m.end()) cout << "hi in m\n";
  else cout << "hi not in m\n";
  m.erase("bkd"); // ("hi", 123), ("gogo", 165)
  for(auto e : m)
    cout << e.first << ' ' << e.second << '\n';
}

int main(void){
  unordered_set_example();
  unordered_multiset_example();
  unordered_map_example();
}
```
