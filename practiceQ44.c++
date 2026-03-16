#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> sums;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                sums.insert(grid[i][j]);

                for (int k = 1; ; k++) {

                    if (i-k < 0 || i+k >= m || j-k < 0 || j+k >= n)
                        break;

                    int sum = 0;

                    for (int t = 0; t < k; t++)
                        sum += grid[i-k+t][j+t];

                    for (int t = 0; t < k; t++)
                        sum += grid[i+t][j+k-t];

                    for (int t = 0; t < k; t++)
                        sum += grid[i+k-t][j-t];

                    for (int t = 0; t < k; t++)
                        sum += grid[i-t][j-k+t];

                    sum -= grid[i-k][j];
                    sum -= grid[i][j+k];
                    sum -= grid[i+k][j];
                    sum -= grid[i][j-k];

                    sums.insert(sum);
                }
            }
        }

        vector<int> ans;

        for (int x : sums) {
            ans.push_back(x);
            if (ans.size() == 3)
                break;
        }

        return ans;
    }
};

int main() {
    
    Solution obj;

    vector<vector<int>> grid = {
        {3,4,5,1,3},
        {3,3,4,2,3},
        {20,30,200,40,10},
        {1,5,5,4,1},
        {4,3,2,2,5}
    };

    vector<int> ans = obj.getBiggestThree(grid);

    for (int x : ans)
        cout << x << " ";

    return 0;
}