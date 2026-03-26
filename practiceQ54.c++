#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    bool check(vector<vector<int>>& grid, int r1, int r2, int c1, int c2, int val) {
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {

                if (grid[i][j] != val) continue;

                if (rows == 1) {
                    if (j == c1 || j == c2) return true;
                }

                else if (cols == 1) {
                    if (i == r1 || i == r2) return true;
                }

                else {
                    if (i == r1 || i == r2 || j == c1 || j == c2)
                        return true;
                }
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        for (auto &row : grid) {
            for (auto x : row) {
                total += x;
            }
        }

        long long top = 0;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                top += grid[i][j];
            }

            long long bottom = total - top;

            if (top == bottom) return true;

            if (top > bottom) {
                if (check(grid, 0, i, 0, n - 1, top - bottom))
                    return true;
            } 
            else {
                if (check(grid, i + 1, m - 1, 0, n - 1, bottom - top))
                    return true;
            }
        }

        long long left = 0;

        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                left += grid[i][j];
            }

            long long right = total - left;

            if (left == right) return true;

            if (left > right) {
                if (check(grid, 0, m - 1, 0, j, left - right))
                    return true;
            } 
            else {
                if (check(grid, 0, m - 1, j + 1, n - 1, right - left))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1,2},
        {3,4}
    };

    if (obj.canPartitionGrid(grid))
        cout << "true";
    else
        cout << "false";

    return 0;
}