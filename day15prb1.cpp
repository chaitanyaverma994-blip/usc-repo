#include<bits/stdc++.h>
using namespace std;

int countVowels(string s) {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            cnt++;
    }
    return cnt;
}

bool compare(string a, string b) {
    int va = countVowels(a);
    int vb = countVowels(b);

    // More vowels first
    if (va != vb)
        return va > vb;

    // Shorter length first
    if (a.length() != b.length())
        return a.length() < b.length();

    // Lexicographically smaller first
    return a < b;
}

int main() {
    int N;
    cin >> N;

    string usernames[1000]; // Adjust size if needed

    for (int i = 0; i < N; i++) {
        cin >> usernames[i];
    }

    sort(usernames, usernames + N, compare);

    for (int i = 0; i < N; i++) {
        cout << usernames[i] << endl;
    }

    return 0;
}