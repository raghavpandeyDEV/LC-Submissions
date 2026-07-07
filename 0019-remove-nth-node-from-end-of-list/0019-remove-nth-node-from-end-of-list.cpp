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
        int len=0;
        ListNode*temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        int ans=len-n;
        if(ans==0){
            ListNode*newHead=head->next;
            delete(head);
            return newHead;
        }
        temp=head;

        while(temp){
            ans--;
            if(ans==0){
                ListNode*del=temp->next;
                temp->next=temp->next->next;
                delete(del);
            }
            temp=temp->next;
        }
        return head;
    }
};