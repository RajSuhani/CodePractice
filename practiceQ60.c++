#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();

        vector<pair<int,int>> robots;  

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], i});
        }

        sort(robots.begin(), robots.end());

        stack<int> st;   

        for (auto &robot : robots) {
            int idx = robot.second;

            if (directions[idx] == 'R') {
                st.push(idx);
            }
            else {
                while (!st.empty() && healths[idx] > 0) {
                    int top = st.top();

                    if (healths[top] < healths[idx]) {
                        st.pop();
                        healths[idx]--;
                        healths[top] = 0;
                    }
                    else if (healths[top] > healths[idx]) {
                        healths[top]--;
                        healths[idx] = 0;
                    }
                    else {
                        healths[top] = 0;
                        healths[idx] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> positions = {3,5,2,6};
    vector<int> healths = {10,10,15,12};
    string directions = "RLRL";

    vector<int> ans = obj.survivedRobotsHealths(positions, healths, directions);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}