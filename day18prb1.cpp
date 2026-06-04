#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool hasLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << "NO";
        return 0;
    }

    int x;
    cin >> x;

    Node* head = new Node(x);
    Node* tail = head;

    Node* loopNode = NULL;

    for (int i = 1; i < N; i++) {
        cin >> x;

        Node* newNode = new Node(x);
        tail->next = newNode;
        tail = newNode;
    }

    int POS;
    cin >> POS;

    // Find the node at POS
    if (POS != -1) {
        Node* temp = head;
        for (int i = 0; i < POS; i++) {
            temp = temp->next;
        }
        loopNode = temp;
        tail->next = loopNode;
    }

    cout << (hasLoop(head) ? "YES" : "NO");

}