#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;

    cout << "Enter number of bracelet IDs: ";
    cin >> N;

    int arr[N];

    cout << "Enter bracelet IDs: ";
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int xorResult = 0;

    for(int i = 0; i < N; i++) {
        xorResult = xorResult ^ arr[i];
    }

    cout << "\nFinal XOR Value = " << xorResult << endl;

    if(xorResult == 0) {
        cout << "BALANCED" << endl;
    }
    else {
        cout << "UNBALANCED" << endl;
    }
}