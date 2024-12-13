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
    bool hasCycle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast= head;
        while(fast && fast->next !=nullptr){
             slow=slow->next;fast=fast->next->next;
             if(fast==slow)return true;
        }
       return false;
       }
};


/*
Execution Trace Step-by-Step:
Initial Setup:

slow = head → slow starts at node 1
fast = head → fast also starts at node 1
First Iteration (do-while loop):

Move slow by 1 step: slow = slow->next → slow moves to node 2.
Move fast by 2 steps: fast = fast->next->next → fast moves to node 1 (because the list is cyclic, so fast moves from node 1 to node 2 and then from node 2 back to node 1).
After the first iteration, we have:

slow = 2
fast = 1
Second Iteration (do-while loop):

Move slow by 1 step: slow = slow->next → slow moves to node 1.
Move fast by 2 steps: fast = fast->next->next → fast moves from node 1 to node 2, and then from node 2 back to node 1.
After the second iteration:

slow = 1
fast = 1
Now, slow and fast are pointing to the same node (1), which means they meet. This meeting point indicates that there is a cycle in the linked list.


*/
