#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s;

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;

        for (int i = 0; i < s2.size(); i++) {

           
            if (s2[i] != (i % 2 ? '1' : '0')) diff1++;

            if (s2[i] != (i % 2 ? '0' : '1')) diff2++;

            
            if (i >= n) {
                if (s2[i - n] != ((i - n) % 2 ? '1' : '0')) diff1--;
                if (s2[i - n] != ((i - n) % 2 ? '0' : '1')) diff2--;
            }

            if (i >= n - 1) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter binary string: ";
    cin >> s;

    cout << "Minimum flips required: "
         << obj.minFlips(s) << endl;

    return 0;
}