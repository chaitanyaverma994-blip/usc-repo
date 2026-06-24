#include <bits/stdc++.h>
using namespace std;

vector<string> result;
vector<string> keypad = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

void generateCombinations(string digits, int index, string current) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

    string letters = keypad[digits[index] - '0'];

    for (char ch : letters) {
        generateCombinations(digits, index + 1, current + ch);
    }
}

int main() {
    string digits;
    cin >> digits;

    if (digits.empty()) {
        return 0;
    }

    generateCombinations(digits, 0, "");

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << " ";
    }

    return 0;
}