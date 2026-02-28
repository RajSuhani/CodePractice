#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long long ans = 0;
        int len = 0;

        for(int i = 1; i <= n; i++) {
            
            if((i & (i - 1)) == 0) {
                len++;
            }

            ans = ((ans << len) | i) % mod;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;

    cout << obj.concatenatedBinary(n);

    return 0;
}