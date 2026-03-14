#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void solve(int n, string curr, vector<string>& ans) {
        
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            
            if (curr.empty() || curr.back() != ch) {
                solve(n, curr + ch, ans);
            }
        }
    }

    string getHappyString(int n, int k) {
        
        vector<string> ans;

        solve(n, "", ans);

        if (k > ans.size())
            return "";

        return ans[k - 1];
    }
};

int main() {
    
    Solution obj;
    
    int n, k;
    
    cout << "Enter n and k: ";
    cin >> n >> k;

    string result = obj.getHappyString(n, k);

    cout << "Answer: " << result << endl;

    return 0;
}