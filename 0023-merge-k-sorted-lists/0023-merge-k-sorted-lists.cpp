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
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> temp;
        for (auto head : lists) {
            for (ListNode* cur = head; cur; cur = cur->next)
                temp.push_back(cur->val);
        }

        sort(temp.begin(), temp.end());

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        for (int x : temp) {
            cur->next = new ListNode(x);
            cur = cur->next;
        }

        return dummy->next;
    }
};