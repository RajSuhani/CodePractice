#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};

int main() {
    Solution obj;
    
    string s;
    cout << "Enter binary string: ";
    cin >> s;
    
    if(obj.checkOnesSegment(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}