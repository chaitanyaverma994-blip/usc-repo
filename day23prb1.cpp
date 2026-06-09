#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> segMin, segMax;
    int n;

    void build(int idx, int low, int high, const vector<int>& arr) {
        if (low == high) {
            segMin[idx] = arr[low];
            segMax[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        segMin[idx] = min(segMin[2 * idx + 1], segMin[2 * idx + 2]);
        segMax[idx] = max(segMax[2 * idx + 1], segMax[2 * idx + 2]);
    }

    int queryMin(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return INT_MAX;

        if (l <= low && high <= r) return segMin[idx];

        int mid = (low + high) / 2;
        return min(
            queryMin(2 * idx + 1, low, mid, l, r),
            queryMin(2 * idx + 2, mid + 1, high, l, r)
        );
    }

    int queryMax(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return INT_MIN;

        if (l <= low && high <= r) return segMax[idx];

        int mid = (low + high) / 2;
        return max(
            queryMax(2 * idx + 1, low, mid, l, r),
            queryMax(2 * idx + 2, mid + 1, high, l, r)
        );
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        segMin.resize(4 * n);
        segMax.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    int rangeDifference(int l, int r) {
        int mn = queryMin(0, 0, n - 1, l, r);
        int mx = queryMax(0, 0, n - 1, l, r);
        return mx - mn;
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    SegmentTree st(arr);

    int Q;
    cin >> Q;

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << st.rangeDifference(L, R) << "\n";
    }

    return 0;
}