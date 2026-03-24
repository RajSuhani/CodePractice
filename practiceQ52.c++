#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;

        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;

        vector<long long> arr;

        for (auto &row : grid) {
            for (auto x : row) {
                arr.push_back(x % MOD);
            }
        }

        vector<long long> prefix(total, 1), suffix(total, 1);

        for (int i = 1; i < total; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }

        for (int i = total - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < total; i++) {
            ans[i / m][i % m] = (prefix[i] * suffix[i]) % MOD;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> result = obj.constructProductMatrix(grid);

    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}