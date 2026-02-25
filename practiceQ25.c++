#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bitsA = __builtin_popcount(a);
            int bitsB = __builtin_popcount(b);
            
            if (bitsA == bitsB)
                return a < b;
            return bitsA < bitsB;
        });
        
        return arr;
    }
};

int main() {
    Solution obj;
    
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    
    vector<int> result = obj.sortByBits(arr);
    
    for (int x : result) {
        cout << x << " ";
    }
    
    return 0;
}