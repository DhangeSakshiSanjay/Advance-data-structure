#include <iostream>
using namespace std;

int maxCrossingSum(int arr[], int l, int m, int h) {
    int left_sum = -999999, sum = 0;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }

    int right_sum = -999999; sum = 0;
    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if (sum > right_sum) right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h) {
    if (l == h) return arr[l];
    int m = (l + h) / 2;
    return max(max(maxSubArraySum(arr, l, m),
                   maxSubArraySum(arr, m + 1, h)),
               maxCrossingSum(arr, l, m, h));
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max subarray sum: " << maxSubArraySum(arr, 0, n - 1);
    return 0;
}
