#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

        dp0[0][0] = dp1[0][0] = 1;

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                if (i > 0) {
                    for (int k = 1; k <= limit && k <= i; k++) {
                        dp0[i][j] = (dp0[i][j] + dp1[i - k][j]) % MOD;
                    }
                }

                if (j > 0) {
                    for (int k = 1; k <= limit && k <= j; k++) {
                        dp1[i][j] = (dp1[i][j] + dp0[i][j - k]) % MOD;
                    }
                }
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};

int main() {
    Solution obj;

    int zero, one, limit;
    cout << "Enter number of zeros: ";
    cin >> zero;

    cout << "Enter number of ones: ";
    cin >> one;

    cout << "Enter limit: ";
    cin >> limit;

    cout << "Total stable arrays: "
         << obj.numberOfStableArrays(zero, one, limit) << endl;

    return 0;
}