#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int compute(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

void waysToCompute(char expr[], int results[], int &resCount) {
    int len = strlen(expr);
    resCount = 0;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
            char left[20], right[20];
            strncpy(left, expr, i); left[i] = '\0';
            strcpy(right, expr + i + 1);

            int leftResults[50], rightResults[50];
            int leftCount = 0, rightCount = 0;
            waysToCompute(left, leftResults, leftCount);
            waysToCompute(right, rightResults, rightCount);

            for (int j = 0; j < leftCount; j++) {
                for (int k = 0; k < rightCount; k++) {
                    results[resCount++] = compute(leftResults[j], rightResults[k], expr[i]);
                }
            }
            return;
        }
    }
    results[resCount++] = atoi(expr);  // single number
}

int main() {
    char expr[] = "2-1-1";
    int results[50], resCount;
    waysToCompute(expr, results, resCount);
    for (int i = 0; i < resCount; i++) cout << results[i] << " ";
    return 0;
}
