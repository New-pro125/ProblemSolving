class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};

        vector<int> criticalPoints;
        ListNode *prev = head;
        ListNode *curr = head->next;
        int index = 1;

        while (curr->next) {
            ListNode *next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(index);
            }
            prev = curr;
            curr = next;
            index++;
        }

        if (criticalPoints.size() < 2) return {-1, -1};

        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();

        for (size_t i = 1; i < criticalPoints.size(); ++i) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};
