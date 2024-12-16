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
    void rearrangeOddEven(ListNode* head) {
        if (!head || !head->next) return;  // Edge case: empty list or single node.

        ListNode* odd = head;          // Pointer to odd-indexed nodes.
        ListNode* even = head->next;   // Pointer to even-indexed nodes.
        ListNode* evenHead = even;     // Store the head of the even list.

        // Traverse the list and separate odd and even indices.
        while (even && even->next) {
            odd->next = even->next;    // Link the next odd-indexed node.
            odd = odd->next;           // Move the odd pointer forward.
            even->next = odd->next;    // Link the next even-indexed node.
            even = even->next;         // Move the even pointer forward.
        }

        // Connect the odd-indexed list to the even-indexed list.
        odd->next = evenHead;
    }
};
