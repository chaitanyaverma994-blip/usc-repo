#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> data(n);
    vector<int> random(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    for (int i = 0; i < n; i++)
        cin >> random[i];

    for (int i = 0; i < n; i++)
        cout << data[i] << " " << random[i] << "\n";

    return 0;
}