#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();

        vector<int> seg(4 * n);

        auto merge = [](int a, int b) {
            return max(a, b);
        };

        function<void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                seg[node] = 1;
                return;
            }

            int mid = (l + r) / 2;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);

            seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
        };

        build(1, 0, n - 1);

        function<void(int, int, int, int)> update =
            [&](int node, int l, int r, int idx) {
                if (l == r) {
                    seg[node] = 1;
                    return;
                }

                int mid = (l + r) / 2;

                if (idx <= mid)
                    update(node * 2, l, mid, idx);
                else
                    update(node * 2 + 1, mid + 1, r, idx);

                seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
            };

        vector<int> ans;

        for (int q = 0; q < queryIndices.size(); q++) {
            int idx = queryIndices[q];
            s[idx] = queryCharacters[q];

            update(1, 0, n - 1, idx);

            int best = 1;
            int cur = 1;

            for (int i = 1; i < n; i++) {
                if (s[i] == s[i - 1])
                    cur++;
                else
                    cur = 1;

                best = max(best, cur);
            }

            ans.push_back(best);
        }

        return ans;
    }
};