#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void constructLowerArray(int arr[], int countSmaller[], int n) {
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            countSmaller[st.top()] = n - i - 1;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        countSmaller[st.top()] = n - st.top() - 1;
        st.pop();
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {12, 1, 2, 3, 0, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low[n];  // Use a standard array

    constructLowerArray(arr, low, n);
    printArray(low, n);

    return 0;
}
