#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;

    cout << "Enter size of array: ";
    cin >> N;

    int arr[1000];

    cout << "Enter array elements: ";
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int left = 0;
    int right = N - 1;

    int minSum = INT_MAX;
    int first, second;

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            first = arr[left];
            second = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    cout << "Pair whose sum is closest to zero: ";
    cout << first << " " << second << endl;

}