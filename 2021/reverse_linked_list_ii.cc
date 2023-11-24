/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* m_node = head;
        ListNode* n_node = head;
        ListNode* prev = nullptr;
        ListNode* tail = nullptr;
        ListNode* p = nullptr;
        ListNode* next = nullptr;
        ListNode* temp;
        
        while(m > 1 || n > 1) {
            if (m > 1) {
                prev = m_node;
                m_node = m_node->next;
                n_node = n_node->next;
                --m;
                --n;
            } else {
                n_node = n_node->next;
                --n;
            }
        }
        
        tail = n_node->next;
        n_node->next = nullptr;
        
        temp = m_node;
        while (m_node) {
            next = m_node->next;
            m_node->next = p;
            p = m_node;
            
            m_node = next;
        }
        
        if (prev) {
            prev->next = p;
        } else {
            head = p;
        }
        
        temp->next = tail;
        
        return head;
    }
};