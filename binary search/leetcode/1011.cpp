
// given "capacity", function returns possible["capacity"]
int isPossible(int* weights, int weightsSize, int days, int capacity){
    int sum = 0;
    int res = 1;
    for (int i = 0; i < weightsSize; i++){
        if (capacity < weights[i]) return 0;
        sum += weights[i];
        if (sum > capacity){
            res++;
            sum = weights[i];
        }
    }
    return res <= days;
}

// find the first occurence of 1
int shipWithinDays(int* weights, int weightsSize, int days){
    int res = 0;
    int left = 0;
    int right = 50000 * 500;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (isPossible(weights, weightsSize, days, mid)){
            res = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return res;
}

/*
👉 Approach
- We want to find the least weight capacity
- If a capacity 'c' is too small, it would be impossible to ship on time
- If 'c' is too big, it would be always possible
- 'c' is possible, 'c + 1' is also possible
⇒ These observations give us a hint on the solution space

📝 Solution Space
- capacity: 0, 1, 2, 3, 4, 5, 6,....
- possible[capacity]: 0, 0, 0, 0, 0, ... , 1, 1, 1, 1

🚀 Conclusion
- We want to find the first occurrence of 1 int the "possible" array ⇒ BS problem
- We can compute "possible[c]" on the fly!
*/

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/