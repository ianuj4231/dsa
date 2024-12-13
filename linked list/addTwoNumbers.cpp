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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* res=new ListNode(0);
  ListNode*         ptr=res;
        int sum=0;
        while(l1!=nullptr||l2!=nullptr){
              sum=carry;
              if(l1){
                    sum+=l1->val;
                    l1=l1->next;
              }
              if(l2){
                  sum+=l2->val;
                  l2=l2->next;
              }
              carry=sum/10;
              sum=sum%10;
              ListNode* tempnode=new ListNode(sum);
              ptr->next=tempnode;
              ptr=ptr->next;
        }
        if(carry==1){
            ptr->next=new ListNode(carry);
        }
        return res->next;
    }
};
/*
Time complexity: 
O
(
m
+
n
)
O(m+n)
Space complexity: 
O
(
1
)
O(1)
*/
