class Solution{
    ListNode* helper(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow;

        // Step 2: Reverse the second half of the linked list
        ListNode* prev = NULL;
        ListNode* curr = mid;
        ListNode* nextNode;
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        ListNode* reversed = prev;

        // Step 3: Interleave the nodes of the first and reversed second halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = reversed;
        while (secondHalf->next) {
            ListNode* temp = firstHalf->next;
            firstHalf->next = secondHalf;
            firstHalf = temp;

            temp = secondHalf->next;
            secondHalf->next = firstHalf;
            secondHalf = temp;
        }
        return head;
    }
    public:
    void reorderList(ListNode* head) {
        ListNode* tempHead = head;
        helper(tempHead);
        return;
    }
};
