#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;

        for(char c : n) {
            maxi = max(maxi, c - '0');
        }

        return maxi;
    }
};

int main() {
    Solution obj;

    string n;
    cout << "Enter number: ";
    cin >> n;

    int result = obj.minPartitions(n);

    cout << "Minimum number of deci-binary numbers: " << result << endl;

    return 0;
}