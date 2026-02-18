#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n ^ (n >> 1);

        return (x & (x + 1)) == 0;
    }
};

int main() {
    Solution obj;
    
    int n = 5;
    if(obj.hasAlternatingBits(n)) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}
