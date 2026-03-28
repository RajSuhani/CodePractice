#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string ans(n, '#');

        char ch = 'a';

        for (int i = 0; i < n; i++) {
            if (ans[i] != '#') continue;

            if (ch > 'z') return "";

            ans[i] = ch;

            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    ans[j] = ch;
                }
            }

            ch++;
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (ans[i] == ans[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = 0;
                }

                if (dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> lcp = {
        {4,0,2,0},
        {0,3,0,1},
        {2,0,2,0},
        {0,1,0,1}
    };

    cout << obj.findTheString(lcp);

    return 0;
}