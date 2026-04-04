#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        string ans;

        for(int start = 0; start < cols; start++) {
            int i = 0, j = start;

            while(i < rows && j < cols) {
                ans += encodedText[i * cols + j];
                i++;
                j++;
            }
        }

        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string encodedText = "ch   ie   pr";
    int rows = 3;

    string result = obj.decodeCiphertext(encodedText, rows);

    cout << "Decoded Text: " << result << endl;

    return 0;
}