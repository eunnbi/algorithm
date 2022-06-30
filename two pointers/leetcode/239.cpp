#include <deque>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> dq; // 💜 Key Point :  using deque!!

    // Enqueue the first K numbers to a deque
    for (int i = 0; i < k; i++){
        // Each time nums[i] enqueued, remove all numbers that are smaller than nums[i] from the back of the dequeue
        while (!dq.empty() && dq.back() < nums[i]) dq.pop_back(); 
        dq.push_back(nums[i]);
    }
    res.push_back(dq.front());  // the front of the dequeue is the maximum

    int size = nums.size();
    for (int i = 0; i < size - k; i++){   // For each iteration i
        if (dq.front() == nums[i]) dq.pop_front(); // if the front of the dequeue == nums[i], remove the front of the dequeue

        // Each time nums[i + k] enqueued, remove all numbers that are smaller than nums[i + k] from the back of the dequeue
        while (!dq.empty() && dq.back() < nums[i + k]) dq.pop_back(); 
        dq.push_back(nums[i + k]);
        res.push_back(dq.front());  // the front of the dequeue is the maximum
    }
    return res;
}

// https://leetcode.com/problems/sliding-window-maximum/