#include <iostream>
using namespace std;

struct Building {
    int left, right, height;
};

void skyline(Building b[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << b[i].left << "," << b[i].height << "], ";
        cout << "[" << b[i].right << ",0]\n";
    }
}

int main() {
    Building b[3] = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}};
    skyline(b, 3);
    return 0;
}