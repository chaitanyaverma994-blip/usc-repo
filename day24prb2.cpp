#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

int main() {
    int N;
    cin >> N;

    if (N == 0) return 0;

    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* tail = head;

    for (int i = 1; i < N; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << slow->data;

    return 0;
}