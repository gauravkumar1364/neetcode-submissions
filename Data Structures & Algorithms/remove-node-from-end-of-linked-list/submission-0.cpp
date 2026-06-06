/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int N) {
        // Create a dummy ListNode before head to handle edge cases
        ListNode* dummy = new ListNode(0, head);

        // Initialize slow and fast pointers at dummy
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast pointer N+1 steps ahead to create a gap
        for (int i = 0; i <= N; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow is now at ListNode before target → delete target ListNode
        slow->next = slow->next->next;

        // Return updated head
        return dummy->next;
    }
};