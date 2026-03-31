#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        int len = n + m - 1;

        string ans(len, '#');
        vector<bool> fixed(len, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (ans[i + j] == '#' || ans[i + j] == str2[j]) {
                        ans[i + j] = str2[j];
                        fixed[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (ans[i] == '#') ans[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {

                bool equal = true;

                for (int j = 0; j < m; j++) {
                    if (ans[i + j] != str2[j]) {
                        equal = false;
                        break;
                    }
                }

                if (equal) {
                    bool changed = false;

                    for (int j = m - 1; j >= 0; j--) {
                        if (!fixed[i + j]) {
                            ans[i + j] = (ans[i + j] == 'a') ? 'b' : 'a';
                            changed = true;
                            break;
                        }
                    }

                    if (!changed) return "";
                }
            }
        }
        for (int i = 0; i < n; i++) {
            bool equal = true;

            for (int j = 0; j < m; j++) {
                if (ans[i + j] != str2[j]) {
                    equal = false;
                    break;
                }
            }

            if (str1[i] == 'T' && !equal) return "";
            if (str1[i] == 'F' && equal) return "";
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string str1 = "TFTF";
    string str2 = "ab";

    cout << obj.generateString(str1, str2);

    return 0;
}