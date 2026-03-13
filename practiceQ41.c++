#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canFinish(long long time, int mountainHeight, vector<int>& workerTimes) {
        
        long long total = 0;

        for (int t : workerTimes) {
            
            // Solve: t*x*(x+1)/2 <= time
            // x² + x - (2*time/t) <= 0

            long long val = (2LL * time) / t;

            long long x = (sqrt(1 + 4LL * val) - 1) / 2;

            total += x;

            if (total >= mountainHeight)
                return true;
        }

        return total >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long left = 1;
        long long right = 1e18;
        long long ans = right;

        while (left <= right) {
            
            long long mid = left + (right - left) / 2;

            if (canFinish(mid, mountainHeight, workerTimes)) {
                ans = mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};