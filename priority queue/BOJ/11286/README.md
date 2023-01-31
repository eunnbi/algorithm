# 절댓값 힙 🥈

```cpp
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;


// prioriry queue에 사용할 비교함수를 정의할 때는 클래스를 이용해야 한다!
class compare {
    public:
        bool operator() (int a, int b) {
            if (abs(a) != abs(b)) return abs(a) > abs(b);
            else return a > b;
        }
};

int main() {
    int n;
    priority_queue<int, vector<int>, compare> pq; // 절댓값 힙

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(num);
    }
    return 0;
}
```

👉 비교함수를 새로 정의하여 절댓값 힙을 구현한다.

> **최대힙**
>
> ```cpp
> priority_queue<int> pq;
> ```
>
> **최소힙**
>
> ```cpp
> priority_queue<int, vector<int>, greater<int>> pq;
> ```

> [문제 보러가기](https://www.acmicpc.net/problem/11286)
