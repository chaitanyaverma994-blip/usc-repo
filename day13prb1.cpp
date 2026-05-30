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

    long long shifts = 0;

    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total shifts: " << shifts << endl;

}