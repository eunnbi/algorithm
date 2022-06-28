
// stack and two pointer (pushed, popped)
int stack[1002];
int top;
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    top = 0;
    int j = 0; // index of popped
    for (int  i = 0; i < pushedSize; i++){
        stack[top++] = pushed[i];
        while (top > 0 && stack[top - 1] == popped[j]){
            top--;
            j++;
        }
    }
    return j == poppedSize;
}

// https://leetcode.com/problems/validate-stack-sequences/