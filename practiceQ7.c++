#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorAll = 0;

        for (int num : nums) {
            xorAll ^= num;
        }

        long diffBit = xorAll & (-xorAll);

        int a = 0, b = 0;

        for (int num : nums) {
            if (num & diffBit)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    vector<int> result = sol.singleNumber(nums);

    cout << "The two single numbers are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
