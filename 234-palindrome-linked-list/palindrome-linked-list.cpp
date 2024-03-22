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
    bool isPalindrome(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL &&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*curr=slow->next;
        ListNode*prev=NULL;
        ListNode*next1=NULL;
        while(curr!=NULL){
            next1=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next1;
        }
        slow->next=prev;
        ListNode*temp1=head;
        ListNode*temp2=slow->next;

        while(temp2!=NULL){
            if(temp1->val!=temp2->val) return false;

            temp2=temp2->next;
            temp1=temp1->next;
        }
        return true;

        
    }
};