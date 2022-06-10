// Nth Digit

int tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

long long num_digits(int m){
    long long count = 0;
    for (int i = 0;; i++){
        if (tens[i + 1] <= m){
            int num_between = tens[i + 1] - tens[i];
            count += (i + 1) * num_between;
        }
        else {
            count += (long long) (i + 1) * (m - tens[i] + 1);
            break;
        }
    }
    return count;
}
int findNthDigit(int n){
    int l = 0, r = 1000000000;
    int t;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (num_digits(mid) < n){
            t = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    
    int k = n - num_digits(t);
    t++;
    int len = num_digits(t) - num_digits(t - 1);
    while (k != len){
        t /= 10;
        k++;
    }
    return t % 10;
}