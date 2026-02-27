#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int z = 0;

        for (char c : s) {
            if (c == '0') z++;
        }

        if (z == 0) return 0;

        if (k % 2 == 0 && z % 2 == 1) {
            return -1;
        }
        int t = (z + k - 1) / k;

        if (k % 2 == 1) {
            if (t % 2 != z % 2) {
                t++;
            }
        }

        return t;
    }
};