#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    
    cout << "Enter number of students: ";
    cin >> N;

    int arr[N];

    cout << "Enter roll numbers: ";
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "\nResult:\n";

    for(int i = 0; i < N; i++) {
        int num = arr[i];
        int count = 0;

        while(num > 0) {
            if(num % 2 == 1) {
                count++;
            }
            num /= 2;
        }

        if(count % 2 == 1) {
            cout << arr[i] << " -> ANSWER" << endl;
        }
        else {
            cout << arr[i] << " -> SAFE" << endl;
        }
    }

}