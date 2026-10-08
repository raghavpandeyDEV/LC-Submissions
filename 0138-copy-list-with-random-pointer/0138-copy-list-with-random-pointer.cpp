/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       /* place dummy nodes in btw the actual nodes
        connect random ptrs
        connect next ptrs
        */

        Node*temp=head;
        while(temp ){
            Node*dummy=new Node(temp->val);
            dummy->next=temp->next;
            temp->next=dummy;
            temp=temp->next->next;
        }

        temp=head;
        while(temp){
            Node*dummy=temp->next;
           if(temp->random) dummy->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node*res=new Node(-1);
        Node*curr=res;
        while(temp){
        curr->next=temp->next;
       if(temp->next) temp->next=temp->next->next;
        curr=curr->next;
        temp=temp->next;
        }
        return res->next;


    }
};