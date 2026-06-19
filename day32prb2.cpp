#include <bits/stdc++.h>
using namespace std;
int main() {
    int K, Q;
    cin >> K >> Q;
    vector<int> q(K);
    int front = 0;
    int rear = -1;
    int size = 0;
    while (Q--) {
        string op;
        cin >> op;
        if (op == "ENQUEUE") {
            int x;
            cin >> x;
            if (size == K) {
                cout << "FULL\n";
            } else {
                rear = (rear + 1) % K;
                q[rear] = x;
                size++;
            }
        }
        else if (op == "DEQUEUE") {
            if (size == 0) {
                cout << "EMPTY\n";
            } else {
                front = (front + 1) % K;
                size--;
            }
        }
        else if (op == "FRONT") {
            if (size == 0) {
                cout << -1 << "\n";
            } else {
                cout << q[front] << "\n";
            }
        }
    }

    return 0;
}