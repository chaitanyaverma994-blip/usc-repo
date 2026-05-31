#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;

    cout << "Enter number of elements: ";
    cin >> N;

    int arr[N];

    cout << "Enter array elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int swapCount = 0;

    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swapCount++;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "Total swaps: " << swapCount << endl;

    return 0;
}