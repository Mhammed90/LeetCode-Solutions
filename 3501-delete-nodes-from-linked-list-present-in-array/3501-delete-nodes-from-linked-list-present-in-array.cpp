/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* get(vector<int>& freq, ListNode* head, int mx) {
        ListNode res(0);
        res.next = head;
        ListNode* cur = &res;
        while (cur->next != nullptr) {
            if (cur->next->val <= mx && freq[cur->next->val]) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return res.next;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1);
        for (auto i : nums) {
            freq[i]++;
        }
        return get(freq, head, mx);
    }
};