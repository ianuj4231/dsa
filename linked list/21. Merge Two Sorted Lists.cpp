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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* rn=new ListNode(INT_MIN);
         ListNode* nn=rn;
         
         if(l1==nullptr && nullptr==l2){
                return nullptr;
         }
         if(l2==nullptr){
            return l1;
         }
         if(nullptr== l1){
            return l2;
         }
         while(l1 && l2  ){
            if(l1->val <= l2->val){
                nn->next=l1;
                l1=l1->next;
            }
            else{
                nn->next=l2;
                l2=l2->next;
            }
            nn=nn->next;
         }
         if(l1==nullptr){
                nn->next=l2;
         }
         else if(l2==nullptr){
                nn->next=l1;
         }
         return rn->next;
    }
};
