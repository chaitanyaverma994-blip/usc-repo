#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int main() {
    int N;
    cin >> N;
    if (N == 0) return 0;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    if (arr[0] == -1) return 0;
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < N) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < N && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i < N && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    TreeNode *first = NULL, *second = NULL, *prev = NULL;
    TreeNode *curr = root;
    while (curr) {
        if (!curr->left) {
            if (prev && prev->val > curr->val) {
                if (!first) first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr)
                pred = pred->right;

            if (!pred->right) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;

                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }
    if (first && second)
        swap(first->val, second->val);
    queue<TreeNode*> out;
    out.push(root);
    vector<int> ans;
    while (!out.empty() && ans.size() < (size_t)N) {
        TreeNode* node = out.front();
        out.pop();
        if (node) {
            ans.push_back(node->val);
            out.push(node->left);
            out.push(node->right);
        } else {
            ans.push_back(-1);
        }
    }
    for (int j = 0; j < N; j++) {
        cout << ans[j];
        if (j + 1 < N) cout << " ";
    }
    return 0;
}