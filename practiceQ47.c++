#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> x(m, vector<int>(n, 0));
        vector<vector<int>> y(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                x[i][j] = (grid[i][j] == 'X');
                y[i][j] = (grid[i][j] == 'Y');

                if (i > 0) {
                    x[i][j] += x[i-1][j];
                    y[i][j] += y[i-1][j];
                }

                if (j > 0) {
                    x[i][j] += x[i][j-1];
                    y[i][j] += y[i][j-1];
                }

                if (i > 0 && j > 0) {
                    x[i][j] -= x[i-1][j-1];
                    y[i][j] -= y[i-1][j-1];
                }

                if (x[i][j] > 0 && x[i][j] == y[i][j])
                    ans++;
            }
        }

        return ans;
    }
};

int main() {
    
    Solution obj;

    vector<vector<char>> grid = {
        {'X','Y','.'},
        {'Y','.','.'}
    };

    cout << obj.numberOfSubmatrices(grid);

    return 0;
}