#include <iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        
        if (n == 0)
            return 1;

        int mask = 0;
        int temp = n;

        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp = temp >> 1;
        }

        return mask ^ n;
    }
};

int main() {
    
    Solution obj;
    int n;

    cout << "Enter number: ";
    cin >> n;

    int result = obj.bitwiseComplement(n);

    cout << "Complement = " << result << endl;

    return 0;
}