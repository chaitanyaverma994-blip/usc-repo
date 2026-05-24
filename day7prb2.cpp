#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    cout << "Enter the string: ";
    cin >> s;

    int count = 1;

    cout << "Compressed string: ";

    for (int i = 0; i < s.length(); i++) {

        // Count consecutive repeating characters
        while (i + 1 < s.length() && s[i] == s[i + 1]) {
            count++;
            i++;
        }

        // Print character with count
        cout << s[i] << count;

        count = 1;
    }

    return 0;
}