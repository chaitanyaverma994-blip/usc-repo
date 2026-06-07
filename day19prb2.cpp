#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    int n = 1;
    Node* tail = head;

    while (tail->next) {
        tail = tail->next;
        n++;
    }

    k %= n;
    if (k == 0)
        return head;

    // Make circular
    tail->next = head;
    head->prev = tail;

    int steps = n - k;
    Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    // Break the circle
    newTail->next = nullptr;
    newHead->prev = nullptr;

    return newHead;
}

int main() {
    int N, K;
    cin >> N >> K;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        Node* node = new Node(x);

        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    head = rotateRight(head, K);

    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
}