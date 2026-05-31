#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;

    cout << "Enter number of people: ";
    cin >> N;

    int height[N];

    cout << "Enter heights: ";
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    int left = 0;
    int right = N - 1;
    long long maxScore = 0;

    while (left < right) {
        long long score = (long long)min(height[left], height[right]) * (right - left);

        if (score > maxScore) {
            maxScore = score;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    cout << "Maximum visibility score: " << maxScore << endl;

}