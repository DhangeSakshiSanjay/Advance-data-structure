#include <iostream>
using namespace std;

int majorityElementRec(int arr[], int left, int right) {
    if (left == right) return arr[left];

    int mid = (left + right) / 2;
    int l = majorityElementRec(arr, left, mid);
    int r = majorityElementRec(arr, mid + 1, right);

    if (l == r) return l;

    int l_count = 0, r_count = 0;
    for (int i = left; i <= right; i++) {
        if (arr[i] == l) l_count++;
        if (arr[i] == r) r_count++;
    }
    return l_count > r_count ? l : r;
}

int majorityElement(int arr[], int size) {
    return majorityElementRec(arr, 0, size - 1);
}

int main() {
    int arr[] = {3, 2, 3};
    cout << majorityElement(arr, 3);
    return 0;
}
