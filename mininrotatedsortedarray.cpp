#include <iostream>
using namespace std;

int findMin(int arr[], int l, int r) {
    if (r < l) return arr[0];
    if (r == l) return arr[l];

    int mid = (l + r) / 2;

    if (mid < r && arr[mid + 1] < arr[mid])
        return arr[mid + 1];
    if (mid > l && arr[mid] < arr[mid - 1])
        return arr[mid];

    if (arr[r] > arr[mid])
        return findMin(arr, l, mid - 1);
    return findMin(arr, mid + 1, r);
}

int main() {
    int arr[5] = {3, 4, 5, 1, 2};
    cout << findMin(arr, 0, 4);
    return 0;
}