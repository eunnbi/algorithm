#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

class compare {
    public:
        bool operator() (int a, int b) {
            if (abs(a) != abs(b)) return abs(a) > abs(b);
            else return a > b;
        }
};

int main() {
    int n;
    priority_queue<int, vector<int>, compare> pq;

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