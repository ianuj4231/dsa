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
    void reorderList(ListNode* head) {
        if(!head || ! head-> next   ){
            return;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast-> next && fast->next->next){
               fast=fast->next->next;
               slow=slow->next;
        }
        ListNode* prev=nullptr;
        ListNode*  curr= slow->next;
                slow->next=nullptr;
        while(curr!=nullptr){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        ListNode* first=head;
        ListNode* second=prev;
        while(second){
             ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
              first->next=second;
              second->next=temp1;
              first=temp1;
              second = temp2;
        }
    }
};
