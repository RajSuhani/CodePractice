#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> res;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            if (count == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                res.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        sort(res.begin(), res.end(), greater<string>());

        string ans = "";
        for (string &str : res) {
            ans += str;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    
    string s = "11011000";
    cout << obj.makeLargestSpecial(s) << endl;

    return 0;
}