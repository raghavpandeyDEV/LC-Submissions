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
        // create clone nodes and insert in btw org nodes
        Node*temp=head;
        while(temp){
            Node*node=new Node(temp->val);
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }
         temp=head;
        // connecting random ptrs
        while(temp && temp->next){
            Node*clone=temp->next;
           if(temp->random) clone->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node*dummy=new Node(-1);
        Node*curr=dummy;

       // connect next ptrs

       while(temp){
          curr->next=temp->next;
          temp->next=temp->next->next;
          temp=temp->next;
          curr=curr->next;
       }
        return dummy->next;
    }
};