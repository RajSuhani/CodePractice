#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                vector<int> vals;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        vals.push_back(grid[x][y]);
                    }
                }

                sort(vals.begin(), vals.end());

                vals.erase(unique(vals.begin(), vals.end()), vals.end());

                if (vals.size() == 1) {
                    ans[i][j] = 0;
                    continue;
                }

                int mn = INT_MAX;
                for (int t = 1; t < vals.size(); t++) {
                    mn = min(mn, vals[t] - vals[t - 1]);
                }

                ans[i][j] = mn;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1, -2, 3},
        {2, 3, 5}
    };

    int k = 2;

    vector<vector<int>> result = obj.minAbsDiff(grid, k);

    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}