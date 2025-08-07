#include <iostream>
using namespace std;

int searchRotated(int arr[], int left, int right, int target) {
    if (left > right) return -1;

    int mid = (left + right) / 2;
    if (arr[mid] == target) return mid;

    if (arr[left] <= arr[mid]) {
        if (target >= arr[left] && target < arr[mid])
            return searchRotated(arr, left, mid - 1, target);
        else
            return searchRotated(arr, mid + 1, right, target);
    } else {
        if (target > arr[mid] && target <= arr[right])
            return searchRotated(arr, mid + 1, right, target);
        else
            return searchRotated(arr, left, mid - 1, target);
    }
}

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 0;
    int index = searchRotated(arr, 0, n - 1, target);
    cout << "Index of " << target << " is: " << index << endl;
    return 0;
}
