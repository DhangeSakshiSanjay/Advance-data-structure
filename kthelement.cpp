#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right], i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] >= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pi = partition(arr, left, right);
        if (pi == k - 1) return arr[pi];
        else if (pi > k - 1) return quickSelect(arr, left, pi - 1, k);
        else return quickSelect(arr, pi + 1, right, k);
    }
    return -1;
}

int main() {
    int arr[] = {3,2,1,5,6,4};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << k << "-th largest: " << quickSelect(arr, 0, n - 1, k);
    return 0;
}
