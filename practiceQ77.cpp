#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        auto count = [&](long long x) {
            long long res = 0;
            int n = coins.size();

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool ok = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;
                        long long g = gcd(lcm, (long long)coins[i]);
                        lcm = lcm / g * coins[i];

                        if (lcm > x) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok) continue;

                long long cnt = x / lcm;

                if (bits % 2)
                    res += cnt;
                else
                    res -= cnt;
            }

            return res;
        };

        long long left = 1;
        long long right = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (count(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};