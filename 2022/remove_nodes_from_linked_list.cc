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
class Solution 
{
    int curMax = -1;
public:
    ListNode* removeNodes(ListNode* head) 
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode* next = removeNodes(head->next);

        if (head->val < curMax)
        {
            return next;
        }

        curMax = head->val;
        head->next = next;

        return head;
    }
};
// Runtime 467 ms
// Memory 161 MB
// 2022.12.22 at 奥盛大厦