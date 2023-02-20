#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num;
    cin >> n;
    while (n--) {
        cin >> num;
        if (maxHeap.size() <= minHeap.size()) maxHeap.push(num);
        else minHeap.push(num);
        if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
        cout << maxHeap.top() << '\n';
    }
    return 0;
}