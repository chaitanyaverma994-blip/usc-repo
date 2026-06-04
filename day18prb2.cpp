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

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    while (head1 && head2) {
        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int N;
    cin >> N;

    Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (!head1) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    int M;
    cin >> M;

    Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (!head2) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    int X;
    cin >> X;

    if (X != -1) {
        Node* temp = head1;

        while (temp && temp->data != X)
            temp = temp->next;

        if (temp)
            tail2->next = temp;
    }

    Node* ans = getIntersection(head1, head2);

    if (ans)
        cout << ans->data;
    else
        cout << -1;

}