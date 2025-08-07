#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void helper(char num[], int target, int pos, long eval, long mult, char expr[], int exprLen) {
    int len = strlen(num);
    if (pos == len) {
        if (eval == target) {
            expr[exprLen] = '\0';
            cout << expr << endl;
        }
        return;
    }

    char currStr[20];
    long currNum = 0;
    for (int i = pos; i < len; i++) {
        currNum = currNum * 10 + (num[i] - '0');
        int digits = i - pos + 1;
        strncpy(currStr, num + pos, digits);
        currStr[digits] = '\0';

        if (pos == 0) {
            strcpy(expr, currStr);
            helper(num, target, i + 1, currNum, currNum, expr, digits);
        } else {
            expr[exprLen] = '+'; strcpy(expr + exprLen + 1, currStr);
            helper(num, target, i + 1, eval + currNum, currNum, expr, exprLen + digits + 1);

            expr[exprLen] = '-'; strcpy(expr + exprLen + 1, currStr);
            helper(num, target, i + 1, eval - currNum, -currNum, expr, exprLen + digits + 1);

            expr[exprLen] = '*'; strcpy(expr + exprLen + 1, currStr);
            helper(num, target, i + 1, eval - mult + mult * currNum, mult * currNum, expr, exprLen + digits + 1);
        }

        if (num[pos] == '0') break;  // Avoid numbers like 05
    }
}

int main() {
    char num[] = "123";
    int target = 6;
    char expr[100];
    helper(num, target, 0, 0, 0, expr, 0);
    return 0;
}
