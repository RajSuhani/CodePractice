#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = false, even = false;

        for (int x : nums1) {
            if (x % 2)
                odd = true;
            else
                even = true;
        }

        if (!odd || !even)
            return true;

        return true;
    }
};