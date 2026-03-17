#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i-1][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            vector<int> temp = matrix[i];
            sort(temp.begin(), temp.end(), greater<int>());

            for (int j = 0; j < n; j++) {
                ans = max(ans, temp[j] * (j + 1));
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {0,0,1},
        {1,1,1},
        {1,0,1}
    };

    cout << obj.largestSubmatrix(matrix);

    return 0;
}