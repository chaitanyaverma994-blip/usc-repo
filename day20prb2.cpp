#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* npx; // XOR of prev and next

    Node(int val) {
        data = val;
        npx = nullptr;
    }
};

Node* XOR(Node* a, Node* b) {
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

int main() {
    int N;
    cin >> N;

    if (N == 0) return 0;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Create XOR Linked List
    Node* head = new Node(arr[0]);
    Node* prev = nullptr;
    Node* curr = head;

    for (int i = 1; i < N; i++) {
        Node* node = new Node(arr[i]);

        curr->npx = XOR(prev, node);

        prev = curr;
        curr = node;
    }

    curr->npx = XOR(prev, nullptr);

    // Traverse and print
    Node* current = head;
    Node* previous = nullptr;

    while (current) {
        cout << current->data;

        Node* next = XOR(previous, current->npx);

        if (next) cout << " ";

        previous = current;
        current = next;
    }

    return 0;
}