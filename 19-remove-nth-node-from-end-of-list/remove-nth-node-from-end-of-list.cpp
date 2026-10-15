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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* fast = temp;
        ListNode* prev = temp;

        
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        
        while (fast != nullptr) {
            fast = fast->next;
            prev = prev->next;
        }

        
        ListNode* nodeToDelete = prev->next;
        prev->next = prev->next->next;
        delete nodeToDelete;

        return temp->next;
        
    }
};