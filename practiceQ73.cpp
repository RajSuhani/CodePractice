#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                for (int k = l; k < r; k++) {
                    long long leftSum = prefix[k + 1] - prefix[l];
                    long long rightSum = prefix[r + 1] - prefix[k + 1];

                    if (leftSum < rightSum) {
                        dp[l][r] = max(dp[l][r],
                                       dp[l][k] + (int)leftSum);
                    } 
                    else if (leftSum > rightSum) {
                        dp[l][r] = max(dp[l][r],
                                       dp[k + 1][r] + (int)rightSum);
                    } 
                    else {
                        dp[l][r] = max(dp[l][r],
                                       max(dp[l][k], dp[k + 1][r]) + (int)leftSum);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};