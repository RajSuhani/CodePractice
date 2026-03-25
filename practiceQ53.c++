#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        for (auto &row : grid) {
            for (auto val : row) {
                total += val;
            }
        }

        long long sum = 0;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum * 2 == total) return true;
        }
        sum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
            }
            if (sum * 2 == total) return true;
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1,4},
        {2,3}
    };

    if (obj.canPartitionGrid(grid))
        cout << "true";
    else
        cout << "false";

    return 0;
}