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
   ListNode* reverse(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*forward=NULL;

        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }

    ListNode*findNode(ListNode*node , int k){
        while(node!=NULL){
            k--;
            if(k==0){
                return node;
            }
            node=node->next;
        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*kthNode=NULL;
        ListNode*next=NULL;
        ListNode*prev=NULL;

        while(temp!=NULL){
          kthNode=findNode(temp,k);
          if(kthNode==NULL){
            prev->next=temp;
            break;//bhool rha hu
          }

          next=kthNode->next;
        kthNode->next=NULL;
        reverse(temp);
        if(temp==head){
            head=kthNode;
        }
        else{
            prev->next=kthNode;
        }
        prev=temp;
        temp=next;
        
        }
        return head;
        
        
    }
};