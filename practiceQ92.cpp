#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr != nullptr && curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                pos.push_back(index);
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (pos.size() < 2)
            return {-1, -1};

        int minDist = INT_MAX;

        for (int i = 1; i < pos.size(); i++) {
            minDist = min(minDist, pos[i] - pos[i - 1]);
        }

        int maxDist = pos.back() - pos.front();

        return {minDist, maxDist};
    }
};