#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;

    cout << "Enter the string: ";
    getline(cin, s);

    string words[1000];
    int count = 0;

    stringstream ss(s);
    string word;

    while (ss >> word) {
        words[count++] = word;
    }

    cout << "Formatted string: ";

    for (int i = count - 1; i >= 0; i--) {
        cout << words[i];
        if (i > 0) {
            cout << " ";
        }
    }

    cout << endl;

}