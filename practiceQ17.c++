#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, ans = 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        
        ans += min(prev, curr);
        return ans;
    }
};

int main() {
    Solution obj;
    
    string s;
    cin >> s;   
    
    cout << obj.countBinarySubstrings(s) << endl;
    
    return 0;
}
