#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(3, -1e18))
        );

        for (int k = 0; k < 3; k++) {
            if (coins[0][0] >= 0) {
                dp[0][0][k] = coins[0][0];
            } else {
                dp[0][0][k] = coins[0][0];
                if (k > 0) dp[0][0][k] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; k++) {

                    long long best = -1e18;

                    if (i > 0) best = max(best, dp[i-1][j][k]);
                    if (j > 0) best = max(best, dp[i][j-1][k]);

                    dp[i][j][k] = best + coins[i][j];

                    if (coins[i][j] < 0 && k > 0) {
                        long long prev = -1e18;

                        if (i > 0) prev = max(prev, dp[i-1][j][k-1]);
                        if (j > 0) prev = max(prev, dp[i][j-1][k-1]);

                        dp[i][j][k] = max(dp[i][j][k], prev);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};

int main() {
    Solution obj;

    vector<vector<int>> coins = {
        {0,1,-1},
        {1,-2,3},
        {2,-3,4}
    };

    cout << obj.maximumAmount(coins);

    return 0;
}