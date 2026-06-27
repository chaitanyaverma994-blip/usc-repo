#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
int cnt = 0;
int ans = -1;
void reverseInorder(Node* root, int k) {
    if (root == NULL || cnt >= k)
        return;
    reverseInorder(root->right, k);
    cnt++;
    if (cnt == k) {
        ans = root->data;
        return;
    }
    reverseInorder(root->left, k);
}
int main() {
    int N;
    cin >> N;
    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    int K;
    cin >> K;
    reverseInorder(root, K);
    cout << ans << endl;
    return 0;
}