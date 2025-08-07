#include <iostream>
using namespace std;

int kthSmallest(int A[], int m, int B[], int n, int k) {
    if (m > n) return kthSmallest(B, n, A, m, k);
    if (m == 0) return B[k - 1];
    if (k == 1) return min(A[0], B[0]);

    int i = min(m, k / 2), j = min(n, k / 2);
    if (A[i - 1] < B[j - 1])
        return kthSmallest(A + i, m - i, B, n, k - i);
    else
        return kthSmallest(A, m, B + j, n - j, k - j);
}

int main() {
    int A[] = {1, 3};
    int B[] = {2};
    int k = 2;
    cout << "K-th smallest: " << kthSmallest(A, 2, B, 1, k) << endl;
    return 0;
}
