#include <iostream>
using namespace std;

int merge(int arr[], int temp[], int l, int m, int r) {
    int i = l, j = m, k = l, inv = 0;
    while (i <= m - 1 && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += (m - i);
        }
    }
    while (i <= m - 1) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (i = l; i <= r; i++) arr[i] = temp[i];
    return inv;
}

int countInversions(int arr[], int temp[], int l, int r) {
    int inv = 0;
    if (l < r) {
        int m = (l + r) / 2;
        inv += countInversions(arr, temp, l, m);
        inv += countInversions(arr, temp, m + 1, r);
        inv += merge(arr, temp, l, m + 1, r);
    }
    return inv;
}

int main() {
    int arr[5] = {2, 4, 1, 3, 5};
    int temp[5];
    cout << countInversions(arr, temp, 0, 4);
    return 0;
}