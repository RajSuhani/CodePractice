#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;
        bool digitAfterE = true; 

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                seenDigit = true;
                digitAfterE = true;
            }
            else if (s[i] == '+' || s[i] == '-') {
                
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (s[i] == '.') {
               
                if (seenDot || seenE)
                    return false;
                seenDot = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                
                if (seenE || !seenDigit)
                    return false;
                seenE = true;
                digitAfterE = false;  
            }
            else {
                return false;
            }
        }

        return seenDigit && digitAfterE;
    }
};

int main() {
    Solution obj;
    
    string s;
    cin >> s;
    
    cout << (obj.isNumber(s) ? "true" : "false") << endl;
    
    return 0;
}
