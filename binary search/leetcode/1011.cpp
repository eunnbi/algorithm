// Capacity To Ship Packages Within D Days

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