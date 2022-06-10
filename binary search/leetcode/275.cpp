// H-index 2

int hIndex(int* citations, int citationsSize){
    int res = 0;
    int left = 0;
    int right = citationsSize - 1;
    
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (citations[mid] >= citationsSize - mid){
            res = citationsSize - mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return res;
}