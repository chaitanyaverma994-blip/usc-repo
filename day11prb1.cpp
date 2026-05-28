#include<bits/stdc++.h>
using namespace std;

int main()
 {

    int N;

    cout << "Enter number of students: ";
    cin >> N;

    int arr[1000];

    cout << "Enter the elements (0, 1, 2): ";

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int mid = 0;
    int high = N - 1;

    while (mid <= high) {

        if (arr[mid] == 0) {

            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;

            low++;
            mid++;
        }

        else if (arr[mid] == 1) {
            mid++;
        }

        else {

            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;

            high--;
        }
    }

    cout << "Sorted array: ";

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

}