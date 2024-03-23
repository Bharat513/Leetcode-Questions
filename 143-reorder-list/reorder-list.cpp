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
    ListNode* helper(ListNode* head){
        if(head == NULL || head->next == NULL)return head;
        ListNode* temp = head;
        while(temp->next->next){
            temp = temp->next;
        }
        ListNode* last = temp->next;
        temp->next = NULL;
        ListNode* newhead = head->next;
        head->next = last;
        if(last)last->next = helper(newhead);
        return head;

    }
public:
    void reorderList(ListNode* head) {
        ListNode* tempHead = head;
        helper(tempHead);
        return;
    }
};