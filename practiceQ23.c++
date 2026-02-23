#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();

        int total = 1 << k;
        
        vector<bool> seen(total, false);
        int count = 0;
        
        int num = 0;
        
        for (int i = 0; i < n; i++) {
            
            num = (num << 1) | (s[i] - '0');

            num = num & ((1 << k) - 1);
    
            if (i >= k - 1) {
                if (!seen[num]) {
                    seen[num] = true;
                    count++;

                    if (count == total) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution obj;

    string s;
    int k;

    cout << "Enter binary string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    if (obj.hasAllCodes(s, k)) {
        cout << "True (All binary codes present)" << endl;
    } else {
        cout << "False (Missing some codes)" << endl;
    }

    return 0;
}