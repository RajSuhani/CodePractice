#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:

    bool isValidCode(string &s) {
        if (s.empty()) return false;
        
        for (char c : s) {
            if (!(isalnum(c) || c == '_')) {
                return false;
            }
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        
        vector<pair<int, string>> validCoupons;

        int n = code.size();
        
        for (int i = 0; i < n; i++) {

            if (!isValidCode(code[i])) continue;
            if (!isActive[i]) continue;
            if (priority.find(businessLine[i]) == priority.end()) continue;

            validCoupons.push_back({priority[businessLine[i]], code[i]});
        }

        sort(validCoupons.begin(), validCoupons.end());

        vector<string> result;
        for (auto &p : validCoupons) {
            result.push_back(p.second);
        }
        
        return result;
    }
};

int main() {
    Solution obj;

    vector<string> code = {"SAVE20","","PHARMA5","SAVE@20"};
    vector<string> businessLine = {"restaurant","grocery","pharmacy","restaurant"};
    vector<bool> isActive = {true,true,true,true};

    vector<string> res = obj.validateCoupons(code, businessLine, isActive);

    for (auto &s : res) {
        cout << s << " ";
    }

    return 0;
}