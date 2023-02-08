#include <iostream>
#include <vector>
using namespace std;

int a[4000002];
vector<int> nums;

int main() {
    int n;
    cin >> n;
    
	// 💡 에라토스테네스의 체 이용
    for (int i = 2; i <= n; i++) {
        a[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) continue;
        for (int j = 2*i; j <= n; j += i) a[j] = 0;
        nums.push_back(i);
    }
    
    int res = 0;
    int i = 0;
    int j = 0;
    int size = nums.size();
    int sum = nums.empty() ? 0 : nums[0];
    while (i <= j && j < size) {
        if (sum < n) sum += nums[++j];
        else if (sum > n) sum -= nums[i++];
        else {
            res++;
            sum -= nums[i++];
        }
    }
    cout << res;
    return 0;
}