#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";

        int left = 0;
        int ones = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {
                while (left <= right && s[left] == '0')
                    left++;

                int len = right - left + 1;
                string cur = s.substr(left, len);

                if (len < minLen) {
                    minLen = len;
                    ans = cur;
                } else if (len == minLen && cur < ans) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};