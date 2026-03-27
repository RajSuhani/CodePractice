#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n;   

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i % 2 == 0) {
                    if (mat[i][j] != mat[i][(j + k) % n]) {
                        return false;
                    }
                }
                else {
                    if (mat[i][j] != mat[i][(j - k + n) % n]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {1,2,1,2},
        {5,5,5,5},
        {6,3,6,3}
    };

    int k = 2;

    if (obj.areSimilar(mat, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}