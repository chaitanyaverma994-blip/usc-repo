#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int removeIndex = n - k;

    for(int i = 0; i < n; i++) {
        if(i != removeIndex) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}