#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            cnt[target[i] - 'a']++;

            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] == 0)
                    continue;

                cnt[c]--;

                string ans = target.substr(0, i);
                ans += char('a' + c);

                for (int j = 0; j < 26; j++) {
                    ans += string(cnt[j], char('a' + j));
                }

                return ans;
            }

            cnt[target[i] - 'a']--;
        }

        return "";
    }
};