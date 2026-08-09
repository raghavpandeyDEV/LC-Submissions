class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* forward = curr->next;

            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* second = slow->next;
        slow->next = NULL;   // split the list

        second = reverseList(second);

        // 3. Merge alternately
        ListNode* first = head;

        while(first != NULL && second != NULL) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};