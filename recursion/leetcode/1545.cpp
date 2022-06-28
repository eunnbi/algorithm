
char findKthBit(int n, int k){
    if (n == 1) return '0';
    int i = 1 << (n - 1);
    if (k < i) return findKthBit(n - 1, k);
    else if (k == i) return '1';
    else return '0' + '1' - findKthBit(n - 1, (1 << n) - k);
}

// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/