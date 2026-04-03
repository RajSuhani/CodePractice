#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    int countWalls(vector<int>& walls, int l, int r) {
        return upper_bound(walls.begin(), walls.end(), r) -
               lower_bound(walls.begin(), walls.end(), l);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<tuple<int,int,int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({robots[i], distance[i], i});
        }

        sort(arr.begin(), arr.end());
        sort(walls.begin(), walls.end());

        vector<int> pos(n), dist(n);

        for (int i = 0; i < n; i++) {
            pos[i] = get<0>(arr[i]);
            dist[i] = get<1>(arr[i]);
        }

        vector<int> leftCount(n), rightCount(n);

        // Count left/right walls
        for (int i = 0; i < n; i++) {

            int leftBound = pos[i] - dist[i];
            if (i > 0) leftBound = max(leftBound, pos[i-1] + 1);

            leftCount[i] = countWalls(walls, leftBound, pos[i]);

            int rightBound = pos[i] + dist[i];
            if (i < n-1) rightBound = min(rightBound, pos[i+1] - 1);

            rightCount[i] = countWalls(walls, pos[i], rightBound);
        }

       
        vector<int> overlap(n, 0);

        for (int i = 0; i < n-1; i++) {

            int L = max(pos[i], max(pos[i+1]-dist[i+1], pos[i]+1));
            int R = min(pos[i+1], min(pos[i]+dist[i], pos[i+1]-1));

            if (L <= R) {
                overlap[i] = countWalls(walls, L, R);
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(2, 0));

        dp[0][0] = leftCount[0];
        dp[0][1] = rightCount[0];

        for (int i = 1; i < n; i++) {

            
            dp[i][0] = max(
                dp[i-1][0] + leftCount[i],
                dp[i-1][1] + leftCount[i] - overlap[i-1]
            );

            // current right
            dp[i][1] = max(
                dp[i-1][0] + rightCount[i],
                dp[i-1][1] + rightCount[i]
            );
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};

int main() {
    Solution obj;

    vector<int> robots = {10,2};
    vector<int> distance = {5,1};
    vector<int> walls = {5,2,7};

    cout << obj.maxWalls(robots, distance, walls);

    return 0;
}