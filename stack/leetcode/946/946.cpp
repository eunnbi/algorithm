#include <stack>
#include <string>
#include <vector>

using namespace std;

// 1. using stack with array
int st[1002];
int top;
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    top = 0;
    int j = 0; // index of popped
    for (int  i = 0; i < pushedSize; i++){
        st[top++] = pushed[i];
        while (top > 0 && st[top - 1] == popped[j]){
            top--;
            j++;
        }
    }
    return j == poppedSize;
}


// 2. STL stack
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int j = 0;
    int pushedSize = pushed.size();
    for (int i = 0; i < pushedSize; i++){
        st.push(pushed[i]);
        while (!st.empty() && st.top() == popped[j]){
            st.pop();
            j++;
        }
    }
    return j == popped.size();
}


// 👉 stack and two pointer (pushed, popped)
// https://leetcode.com/problems/validate-stack-sequences/