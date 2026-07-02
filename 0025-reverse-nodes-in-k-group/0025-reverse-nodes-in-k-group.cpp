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


    ListNode*NthNode(ListNode* temp, int k){
        while(temp!=NULL){
            k--;
            if(k==0)return temp;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       if (head == NULL || k == 1) return head;
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
        ListNode*Knode=NthNode(temp,k);

        if(Knode==NULL){
            if(prev){
                prev->next=temp;
                break;
            }
        }
      ListNode*next=Knode->next;
      Knode->next=NULL;
      ListNode* newHead = reverse(temp); 
        if (temp == head) {
            head = newHead;
        }
      else{
        prev->next=Knode;
      }

      prev=temp;
      temp=next;
        
    }
    return head;
    }
};