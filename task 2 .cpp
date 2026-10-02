#include <iostream>

using namespace std;

int findMax(int A[], int n) {
    if (n == 1) return A[0];
    int maxOfRest = findMax(A, n - 1);
    return (A[n - 1] > maxOfRest) ? A[n - 1] : maxOfRest;
}

int main() {
    int A[] = {4, 15, 7, 22, 9, 1};
    int n = sizeof(A) / sizeof(A[0]);
    
    cout << "Maximum element: " << findMax(A, n) << endl;
    
    return 0;
}
