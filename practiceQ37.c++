#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        
        for(int i = 0; i < n; i++) {
            if(nums[i][i] == '0')
                ans += '1';
            else
                ans += '0';
        }
        
        return ans;
    }
};

int main() {
    Solution obj;

    vector<string> nums = {"111","011","001"};

    cout << obj.findDifferentBinaryString(nums) << endl;

    return 0;
}