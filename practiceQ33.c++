#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> row(m, 0), col(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution obj;
    
    vector<vector<int>> mat = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    
    cout << "Number of special positions: " 
         << obj.numSpecial(mat) << endl;

    return 0;
}