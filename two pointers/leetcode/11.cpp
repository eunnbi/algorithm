#define min(a, b) ((a) > (b) ? (b) : (a))
int maxArea(int* height, int heightSize){
    // Narrowing two pointers ✌️
    int left = 0;
    int right = heightSize - 1;

    int res = 0;
    int area;
    
    while (left < right){
        area = min(height[left], height[right]) * (right - left);
        if (res < area) res = area;
        if (height[left] < height[right]) left++;
        else right--;
    }
    return res;
}

/*
👀 Approach

- Find the maximum of "min(height[left], height[right]) * (right - left)" (left < right)
- Narrowing two pointers
- Both "i++" and "j--" will decrease the with of container by 1.
- Therefore, to increase the area, we need to "increase the height."
- But, if "a[i] < a[j]" , "j--" will never increase the height.
- So, if "a[i] < a[j]" , "i++", and  if "a[i] > a[j]" , "j--"
*/

// https://leetcode.com/problems/container-with-most-water/