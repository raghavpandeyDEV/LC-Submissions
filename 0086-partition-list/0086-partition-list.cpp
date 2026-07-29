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
    ListNode* partition(ListNode* head, int x) {
      ListNode*dummy1=new ListNode(-1);
      ListNode*small=dummy1;
      
       ListNode*dummy2=new ListNode(-1);
      ListNode*large=dummy2;

      ListNode*temp=head;
      while(temp!=NULL){
        if(temp->val<x){
            small->next=temp;
            small=small->next;
        }
        else{
            large->next=temp;
            large=large->next;
        }
        temp=temp->next;
      }
      large->next=NULL;
      small->next=dummy2->next;
      delete(dummy2);
      ListNode*newHead=dummy1->next;
      delete(dummy1);
      return newHead;

    }
};