#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (odd != -1)
                    return "";
                odd = i;
            }
        }

        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int m = n / 2;

        auto build = [&](const string& h) {
            string res = h;
            if (odd != -1)
                res += char('a' + odd);

            for (int i = m - 1; i >= 0; i--)
                res += h[i];

            return res;
        };

        string halfTarget = target.substr(0, m);

        string best = "";

        for (int i = m - 1; i >= 0; i--) {
            for (int c = halfTarget[i] - 'a' + 1; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                vector<int> temp = half;

                bool possible = true;

                for (int j = 0; j < i; j++) {
                    int x = halfTarget[j] - 'a';

                    if (temp[x] == 0) {
                        possible = false;
                        break;
                    }

                    temp[x]--;
                }

                if (!possible)
                    continue;

                temp[c]--;

                string h = halfTarget.substr(0, i);
                h += char('a' + c);

                for (int x = 0; x < 26; x++)
                    h += string(temp[x], char('a' + x));

                string candidate = build(h);

                if (candidate > target &&
                    (best.empty() || candidate < best))
                    best = candidate;
            }
        }

        string h;

        for (int i = 0; i < m; i++) {
            int x = halfTarget[i] - 'a';

            if (half[x] == 0)
                break;

            half[x]--;
            h += halfTarget[i];

            if (i == m - 1) {
                string candidate = build(h);

                if (candidate > target &&
                    (best.empty() || candidate < best))
                    best = candidate;
            }
        }

        return best;
    }
};