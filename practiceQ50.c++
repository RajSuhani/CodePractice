#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> rotate90(vector<vector<int>> mat) {
        int n = mat.size();
        vector<vector<int>> res(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j][n - 1 - i] = mat[i][j];
            }
        }

        return res;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        for (int i = 0; i < 4; i++) {
            if (mat == target) return true;
            mat = rotate90(mat);
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> target = {
        {1, 0},
        {0, 1}
    };

    if (obj.findRotation(mat, target))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}